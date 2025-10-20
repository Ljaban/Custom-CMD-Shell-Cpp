#include "Touch.h"
#include <filesystem> 

Touch::Touch(const string& file) : Command(), fileName(file)
{
}

Touch::~Touch()
{
}

void Touch::function() {
    ifstream check(fileName);
    if (check.is_open()) {
        throw FileError("Greska: fajl '" + fileName + "' vec postoji.");
    }

    ofstream ofs(fileName);
    if (!ofs) {
        throw FileError("Greska: ne mogu da kreiram fajl '" + fileName + "'");
    }

    ofs.close();
}

string Touch::getFileName() const
{
	return fileName;
}
