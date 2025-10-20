#pragma once
#ifndef RM_H

#include <iostream>
#include <filesystem>
#include <string>
#include "Command.h"
#include "FileError.h"

using namespace std;

class FileError;

class Rm : public Command {
public:
	Rm(const string& file);
	~Rm() override;

	void function() override;
	string getFileName() const;

private:
	string fileName;
};
#endif // !RM_H
