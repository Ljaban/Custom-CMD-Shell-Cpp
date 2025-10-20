#pragma once
#ifndef WC_H
#define WC_H
#include "Command.h"

class Wc : public Command {
public:
	Wc(char c, string line);
	virtual ~Wc() override;

	void function() override;
	const char getC();
	string getLine();

private:
	string line;
	char c;
};

#endif