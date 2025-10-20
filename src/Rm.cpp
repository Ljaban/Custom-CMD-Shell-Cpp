#include "Rm.h"

Rm::Rm(const string& file) : Command(), fileName(file)
{
}

Rm::~Rm()
{
}

#include "Rm.h"
#include "FileError.h"
#include <cstdio>
#include <iostream>
using namespace std;

void Rm::function() {
    try {
        if (remove(fileName.c_str()) != 0) {
            throw FileError("Greska: fajl '" + fileName + "' ne postoji ili se ne moze obrisati.");
        }
        else {
            cout << "Fajl '" << fileName << "' je obrisan." << endl;
        }
    }
    catch (const FileError& e) {
        e.printError();
    }
}

string Rm::getFileName() const
{
	return fileName;
}
