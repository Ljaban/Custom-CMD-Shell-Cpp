#pragma once
#ifndef FILEERROR_H

#include <string>
#include <iostream>
#include "Error.h"

using namespace std;

class FileError : public Error {
public:
	FileError(const string& msg);
	~FileError() override;

	void printError() const override;
};


#endif // !FILEERROR_H
