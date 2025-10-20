#pragma once
#ifndef COMMANDERROR_H

#include <string>
#include <iostream>
#include "Error.h"

using namespace std;

class CommandError : public Error {
public:
	CommandError(const string& msg);
	~CommandError() override;

	void printError() const override;
}; 

#endif // !COMMANDERROR_H
