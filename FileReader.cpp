#include "FileReader.h"

FileR::FileR(string fileName) : fileName(fileName) {

}

FileR::~FileR()
{
}

string FileR::readLine()
{
	string fileToOpen = getFile();

	if (!fileToOpen.empty() && fileToOpen[0] == ' ') {
		fileToOpen.erase(0, 1);
	}

	ifstream file(fileToOpen);
	string all = "";
	string line;

	if (!file) {
		cout << "Greska pri otvaranju fajla" << endl;
		return "";
	}

	while (getline(file, line)) {
		all += line + "\n";
	}

	file.close();
	return all;
}

string FileR::getFile() const
{
	return fileName;
}
