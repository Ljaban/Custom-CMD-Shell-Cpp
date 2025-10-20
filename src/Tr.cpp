#include "Tr.h"

TR::TR(const string& text, const string& what, const string& with, const string& fileName, const bool& Flag, bool pipeFlag, Decider& decider) : Command(), text(text), what(what), with(with), fileName(fileName), flag(Flag), pipeFlag(pipeFlag), decider(decider)
{
}

TR::~TR()
{
}

static string toString(const TR& t) {
    ostringstream oss;
    oss << t; 
    return oss.str();
}

#include "TR.h"
#include "FileReader.h"
#include "FileError.h"
#include <iostream>
using namespace std;

void TR::function() {
    try {
        if (what.empty()) return;

        if (!fileName.empty()) {
            FileReader fr(fileName);
            if (!fr.canOpen()) {
                throw FileError("Greska: fajl '" + fileName + "' ne postoji ili se ne moze otvoriti.");
            }
            text = fr.read();
        }

        string result;
        size_t last_pos = 0;
        size_t found_pos = 0;

        while ((found_pos = text.find(what, last_pos)) != string::npos) {
            result += text.substr(last_pos, found_pos - last_pos);
            result += with;
            last_pos = found_pos + what.length();
        }

        result += text.substr(last_pos);
        text = result;

        if (!pipeFlag) {
            cout << *this << endl;
        }
        else {
            decider.setResult(toString(*this));
        }
    }
    catch (const FileError& e) {
        e.printError();
    }
}

string TR::getText() const
{
	return text;
}

string TR::getWhat() const
{
	return what;
}

string TR::getWith() const
{
	return with;
}

string TR::getFileName() const
{
    return fileName;
}

ostream& operator<<(ostream& out, const TR& t)
{
	out << t.getText() << endl;
	return out;
}
