#pragma once
#ifndef HEAD_H

#include <iostream>
#include <string>
#include <sstream>
#include "Command.h"
#include "Decider.h"
#include "FileError.h"
#include "OptionError.h"

class Decider;
class OptionError;
class FileError;

using namespace std;

class Head : public Command {
public:
	Head(const int& ncount, const string & argument, bool pipeFlag, Decider& decider);
	~Head() override;

	void function() override;
	int getN() const;
	string getText() const;

	friend ostream& operator<<(ostream& out, const Head& h);

private:
	int n;
	string text;
	bool pipeFlag;
	Decider& decider;
};

#endif // !HEAD_H
