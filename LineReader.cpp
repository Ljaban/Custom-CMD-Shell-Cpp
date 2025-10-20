#include "LineReader.h"

LineReader::LineReader() : all("") {
}

LineReader::~LineReader() {
}

string LineReader::readLine() {
    all = "";
    string line;
    getline(cin, line);
    Separator sep(line);
    sep.parseCommand();
    sep.parseOption();
    sep.parseText();

    if ((sep.getText() == "" && (sep.getFunction() == "date" || sep.getFunction() == "time")) ||
        (sep.getText() != "" && (sep.getFunction() == "echo" || sep.getFunction() == "touch" || sep.getFunction() == "wc"))) {
        all = line;
        return all;
    }
    
    all = line + '\n';
    while (getline(cin, line)) {
        if (!line.empty()) {
            all += line + "\n";
        }
    }
    all.erase(all.find_last_not_of(" \t") + 1);
    return all;
}
