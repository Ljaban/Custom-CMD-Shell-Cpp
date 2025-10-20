#pragma once
#ifndef ECHO_H
#define ECHO_H
#include "Command.h"

class Echo : public Command {
public:
	Echo(const string& s);
	~Echo() override;

	string getLine() const;
	void function() override;

private:
	string line;
};

#endif // !ECHO_H

