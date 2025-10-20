#pragma once
#ifndef FILEREADER_H
using namespace std;

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Reader.h"

class FileReader : public Reader {
public:
	FileReader(const string& name);
	~FileReader();

	string read() override;
	bool canOpen();

private:
	string fileName;
};

#endif // !FILEREADER_H

