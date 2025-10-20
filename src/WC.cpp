#include "WC.h"
#include <sstream>
#include <cctype>
#include <iostream>

WC::WC(const char& c, const string& text, bool flag, const string& fileName, bool pipeFlag, Decider& decider)
    : Command(), textToCount(text), option(c), flag(flag), count(0), fileName(fileName), pipeFlag(pipeFlag), decider(decider)
{
}

WC::~WC() {}

bool WC::hasQuotes() const {
    return textToCount.size() >= 2 && textToCount.front() == '"' && textToCount.back() == '"';
}

bool WC::isInvalidQuotes() const {
    return (!textToCount.empty() && textToCount.front() == '"' && (textToCount.size() < 2 || textToCount.back() != '"'));
}

static void findOutput(string& outputFile) {
    outputFile = outputFile.substr(2);
    size_t start = outputFile.find_first_not_of(" \t\n\r");
    size_t end = outputFile.find_last_not_of(" \t\n\r");
    outputFile = outputFile.substr(start, end - start + 1);
}

static void findOutputText(string& output) {
    output = output.substr(1);
    size_t start = output.find_first_not_of(" \t\n\r");
    size_t end = output.find_last_not_of(" \t\n\r");
    output = output.substr(start, end - start + 1);
}

static void rtrim(string& s) {
    while (!s.empty() && std::isspace((unsigned char)s.back())) {
        s.pop_back();
    }
}

void WC::function() {
    try {
        count = 0;
        string content;
        rtrim(textToCount);
        rtrim(fileName);

        if (isInvalidQuotes()) {
            throw FileError("Greska: pocetni navodnik bez zavrsnog!");
        }

        if (fileName[0] == '<') {
            fileName = fileName.substr(1);
        }

        string outputFile;
        if (!fileName.empty()) {
            size_t position = fileName.find(">");
            if (position == string::npos) {
                FileReader fR(fileName);
                content = fR.read();
            }
            else {
                string text = fileName;
                fileName = text.substr(0, position);
                FileReader fR(fileName);
                content = fR.read();
                outputFile = text.substr(position);
            }
        }
        else if (hasQuotes()) {
            size_t position = textToCount.find(">");
            if (position == string::npos) {
                findOutputText(textToCount);
                size_t start = textToCount.find_first_not_of('"');
                size_t end = textToCount.find_last_not_of('"');
                textToCount = textToCount.substr(start, end - start + 1);
                content = textToCount;
            }
            else {
                string text = textToCount;
                textToCount = text.substr(0, position);
                outputFile = text.substr(position);
                content = textToCount;
            }
        }
        else if (flag) {
            content = textToCount;
        }

        if (option == 'c') {
            count = content.length();
        }
        else if (option == 'w') {
            istringstream iss(content);
            string word;
            while (iss >> word) {
                count++;
            }
        }
        else {
            throw FileError("Greska: nepoznata komanda '" + string(1, option) + "'");
        }

        if (!outputFile.empty()) {
            if (outputFile[0] == '>' && outputFile[1] == '>') {
                findOutput(outputFile);
                FileReader fr(outputFile);
                if (!fr.canOpen()) {
                    Touch t(outputFile);
                    t.function();
                }
                ofstream ofs(outputFile, ios::app);
                if (hasQuotes()) {
                    textToCount = textToCount.substr(1, textToCount.size() - 2);
                }
                if (!pipeFlag) {
                    ofs << *this;
                    ofs.close();
                    return;
                }
                else {
                    decider.setResult(to_string(count));
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
                ofstream ofs(outputFile, ios::app);
                if (hasQuotes()) {
                    findOutputText(textToCount);
                    size_t start = textToCount.find_first_not_of('"');
                    size_t end = textToCount.find_last_not_of('"');
                    textToCount = textToCount.substr(start, end - start + 1);
                }
                if (!pipeFlag) {
                    ofs << *this;
                    ofs.close();
                    return;
                }
                else {
                    decider.setResult(to_string(count));
                    return;
                }
            }
        }
        else {
            if (!pipeFlag) {
                cout << *this << endl;
            }
            else {
                decider.setResult(to_string(count));
            }
        }
    }
    catch (const FileError& e) {
        e.printError();
    }
}

int WC::getCount() const {
    return count;
}

ostream& operator<<(ostream& out, const WC& w) {
    out << w.getCount();
    return out;
}
