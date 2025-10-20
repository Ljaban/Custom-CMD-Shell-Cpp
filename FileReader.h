#pragma once
#ifndef FILEREADER_H
#define FILEREADER_H
#include "Reader.h"
#include <fstream>
using namespace std;

class FileR : public Reader {
public:
	FileR(string fileName);
	virtual ~FileR() override;

	virtual string readLine() override;
	string getFile() const;
private:
	string fileName;
};

#endif // !FILEREADER_H
