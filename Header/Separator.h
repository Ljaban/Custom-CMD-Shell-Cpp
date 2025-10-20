#pragma once
#ifndef SEPARATOR_H
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include "LineReader.h"
#include <sstream>

class Separator {
public:
	Separator(const string& line, bool pipeFlag, const string& res);
	~Separator();

	vector<string> splitByPipe() const;

	void getArguments();

	string getCommand() const;
	string getArgument() const;
	string getFileName() const;
	string getOption() const;
	string getWhat() const;
	string getWith() const;

	void setArgument(const string& arg);
	void setFileName(const string& fileN);
	
	bool getFlag() const;
	bool isBatchBlock() const;

private:
	string wholeLine;
	string command;
	string argument;
	string option;
	string fileName;
	string what;
	string with;
	string res;
	vector<string> arguments;
	bool flag = false;
	bool isBatch;
	bool pipeFlag;
};

#endif // !SEPARATOR_H

