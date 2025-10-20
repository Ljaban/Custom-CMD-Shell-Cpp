#pragma once
#ifndef BATCH_H

#include <iostream>
#include <string>
#include <sstream>
#include "Command.h"
#include "Separator.h"
#include "Decider.h"
#include "FileError.h"
#include "Prompt.h"

using namespace std;
class FileError;

class Batch : public Command {
public:
	Batch(const string& functions, Prompt& p, const string& fileName);
	~Batch() override;

	void function() override;
	string getFunctions() const;

private:
	string listOfFunctions;
	Prompt& p;
	string fileName;
};

#endif // !BATCH_H
