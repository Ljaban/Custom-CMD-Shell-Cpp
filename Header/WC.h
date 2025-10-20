#pragma once
#ifndef WC_H

#include <iostream>
#include <string>
#include "Command.h"
#include "FileReader.h"
#include "Touch.h"
#include "Truncate.h"
#include "Decider.h"
#include "FileError.h"
#include "CommandError.h"

class Decider;
class FileError;
class CommandError;

using namespace std;

class WC : public Command {
public:
	WC(const char& c, const string& text, bool flag, const string& fileName, bool pipeFlag, Decider& decider);
	~WC() override;

	void function() override;
	int getCount() const;

	friend ostream& operator<<(ostream& out, const WC& w);

private:
	string textToCount;
	char option;
	int count = 0;
	string fileName;
	bool flag;
	bool pipeFlag;
	bool hasQuotes() const;
	bool isInvalidQuotes() const;
	Decider& decider;
};
#endif // !WC_H
