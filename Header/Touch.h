#pragma once
#ifndef TOUCH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem> 
#include "Command.h"
#include "FileError.h"

using namespace std;

class FileError;

class Touch : public Command {
public:
	Touch(const string& file);
	~Touch() override;

	void function() override;
	string getFileName() const;
private:
	string fileName;
};
#endif // !TOUCH_H
