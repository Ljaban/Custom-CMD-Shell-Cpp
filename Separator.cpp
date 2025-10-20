#include "Separator.h"

Separator::Separator(string all) : all(all), c(' '), function(""), textOrFile("") {

}

Separator::~Separator()
{
}

Prompt Separator::getSign() const
{
	return sign.getPrompt();
}

string Separator::getFunction() const
{
	return function;
}

char Separator::getChar() const
{
	return c;
}

string Separator::getText() const
{
	return textOrFile;
}

void Separator::parseCommand() {
    stringstream ss(all);
    if (all[0] == '$') {
        ss.ignore(1);
    }

    ss >> function;
}

void Separator::parseOption() {
    if (function == "wc") {
        size_t pos = all.find("-");
        if (pos != string::npos) {
            c = all[pos + 1];
        }
    }
}

void Separator::parseText() {
    if (function == "echo" || function == "touch") {
        size_t spacePos = all.find_first_not_of(" \t", all.find(function) + function.size());
        if (spacePos != string::npos) {
            textOrFile = all.substr(spacePos);
        }
    }
    else if (function == "wc") {
        size_t firstSpacePos = all.find_first_not_of(" \t", all.find(function) + function.size());
        size_t secondSpacePos = all.find_first_not_of(" \t", firstSpacePos + 1);

        if (secondSpacePos != string::npos) {
            if (all[secondSpacePos] != '-') {
                textOrFile = all.substr(secondSpacePos + 1);
            }
            else {
                size_t thirdSpacePos = all.find_first_not_of(" \t", secondSpacePos + 1);
                if (thirdSpacePos != string::npos) {
                    textOrFile = all.substr(thirdSpacePos);
                }
            }
        }
    }
}
