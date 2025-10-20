#include "FileReader.h"

FileReader::FileReader(const string& name): fileName(name)
{
}

FileReader::~FileReader()
{
}

string FileReader::read() 
{
    ifstream in(fileName);
    if (!in.is_open()) {
        cerr << "Ne mogu da otvorim fajl: " << fileName << endl;
        return "";
    }

    string line;
    string content;

    while (getline(in, line)) {
        content += line + "\n";
    }

    return content;
}

bool FileReader::canOpen()
{
    ifstream in(fileName);
    return in.is_open();
}
