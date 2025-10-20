#pragma once
#include "Prompt.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#ifndef SEPARATOR_H
#define SEPARATOR_H

class Separator {
public:
	Separator(string all);
	~Separator();

	Prompt getSign() const;
	string getFunction() const;
	char getChar() const;
	string getText() const;

	void parseCommand();
	void parseOption();
	void parseText();

private:
	string all;
	Prompt sign;
	string function;
	char c;
	string textOrFile;

};

#endif // !SEPARATOR_H
