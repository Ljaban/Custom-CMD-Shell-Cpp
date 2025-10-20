#include "Echo.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

Echo::Echo(const string& line, bool multilineFlag, const string& fileName, Decider& dec, bool pipeFlag)
    : text(line), flag(multilineFlag), fileName(fileName), decider(dec), pipeFlag(pipeFlag)
{
}

Echo::~Echo()
{
}

ostream& operator<<(ostream& out, const Echo& e) {
    out << e.getText() << endl;
    return out;
}

bool Echo::hasQuotes() const {
    if (text.empty()) return false;
    if (text.front() != '"') return false;
    size_t pos = text.find('"', 1);
    return pos != std::string::npos;
}

bool Echo::isInvalidQuotes() const {
    return (!text.empty() && text.front() == '"' && (text.size() < 2 || text.back() != '"'));
}

static void findOutputText(string& output) {
    output.erase(remove(output.begin(), output.end(), '"'), output.end());

    size_t start = output.find_first_not_of(" \t\n\r");
    size_t end = output.find_last_not_of(" \t\n\r");

    if (start == string::npos) {
        output.clear();
    }
    else {
        output = output.substr(start, end - start + 1);
    }
}

static void findOutput(string& outputFile) {
    if (!outputFile.empty() && outputFile[0] == '>') outputFile = outputFile.substr(1);
    size_t start = outputFile.find_first_not_of(" \t\n\r");
    size_t end = outputFile.find_last_not_of(" \t\n\r");
    if (start == string::npos) outputFile.clear();
    else outputFile = outputFile.substr(start, end - start + 1);
}

void Echo::function() {
    try {
        string content;

        if (isInvalidQuotes() and !hasQuotes()) {
            throw FileError("Greska: pocetni navodnik bez zavrsnog!");
        }

        if (!fileName.empty() && fileName[0] == '<' && fileName[1] != ' ') {
            fileName = fileName.substr(1);
        }
        else if (!fileName.empty() && fileName[0] == '<' && fileName[1] == ' ') {
            fileName = fileName.substr(2);
        }

        string outputFile;

        if (!fileName.empty()) {
            size_t position = fileName.find(">");
            if (position == string::npos) {
                FileReader fR(fileName);
                content = fR.read();
            }
            else {
                string textPart = fileName;
                fileName = textPart.substr(0, position);
                FileReader fR(fileName);
                content = fR.read();
                outputFile = textPart.substr(position);
            }
        }
        else if (hasQuotes()) {
            size_t position = text.find(">");
            if (position == string::npos) {
                findOutputText(text);
                size_t start = text.find_first_not_of('"');
                size_t end = text.find_last_not_of('"');
                text = text.substr(start, end - start + 1);
                content = text;
            }
            else {
                string textPart = text;
                text = textPart.substr(0, position);
                outputFile = textPart.substr(position);
                content = text;
            }
        }
        else if (flag) {
            content = text;
        }
        if (!outputFile.empty()) {
            if (outputFile[0] == '>' && outputFile[1] == '>') {
                findOutput(outputFile);
                findOutput(outputFile);
                FileReader fr(outputFile);
                if (!fr.canOpen()) {
                    Touch t(outputFile);
                    t.function();
                }
                if (!content.empty() && (content.back() == '\n' || content.back() == '\r')) {
                    content.pop_back();
                }

                ofstream ofs(outputFile, ios::app);
                if (hasQuotes()) {
                    content = content.substr(1, content.size() - 2);
                }
                if (!pipeFlag) {
                    ofs << content;
                    ofs.close();
                    return;
                }
                else {
                    decider.setResult(content);
                    return;
                }
            }
            else if (outputFile[0] == '>' && outputFile[1] != '>') {
                findOutput(outputFile);
                FileReader fr(outputFile);
                if (!fr.canOpen()) {
                    Touch t(outputFile);
                    t.function();
                }
                Truncate tr(outputFile);
                tr.function();
                if (!content.empty() && (content.back() == '\n' || content.back() == '\r')) {
                    content.pop_back();
                }
                ofstream ofs(outputFile, ios::app);
                if (hasQuotes()) {
                    findOutputText(content);
                    size_t start = content.find_first_not_of('"');
                    size_t end = content.find_last_not_of('"');
                    content = content.substr(start, end - start + 1);
                }
                if (!pipeFlag) {
                    ofs << content;
                    ofs.close();
                    return;
                }
                else {
                    decider.setResult(content);
                    return;
                }
            }
        }
        else {
            if (!pipeFlag) {
                cout << content << endl;
            }
            else {
                decider.setResult(content);
            }
        }
    }
    catch (const FileError& e) {
        e.printError();
    }
}

const string& Echo::getText() const
{
    return text;
}
