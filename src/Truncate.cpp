#include "Truncate.h"

Truncate::Truncate(const string& file) : Command(), fileName(file)
{
}

Truncate::~Truncate()
{
}

void Truncate::function() {
    ifstream check(fileName);
    if (!check.is_open()) {
        throw FileError("Greska: fajl '" + fileName + "' ne postoji.");
    }
    check.close();

    ofstream ofs(fileName, ios::trunc);
    if (!ofs) {
        throw FileError("Greska: ne mogu da obrisem sadrzaj fajla '" + fileName + "'");
    }

    ofs.close();
}


string Truncate::getFileName() const
{
	return fileName;
}
