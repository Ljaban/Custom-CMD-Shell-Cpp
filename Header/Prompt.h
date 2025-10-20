#pragma once
#ifndef PROMPT_H
#include <iostream>
#include <string>
using namespace std;

class Prompt {
public:
	Prompt(char c = '$');
	~Prompt();

	void setSign(char c);
	char getSign();

private:
	char sign;
};

#endif // !PROMPT_H

