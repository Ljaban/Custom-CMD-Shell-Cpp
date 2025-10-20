#pragma once
#ifndef TRUNCATE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include "Command.h"
#include "FileError.h"

using namespace std;

class FileError;

class Truncate : public Command {
public:
	Truncate(const string& file);
	~Truncate() override;

	void function() override;
	string getFileName() const;
private:
	string fileName;
};
#endif // !TRUNCATE_H
