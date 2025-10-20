#pragma once
#ifndef OPTIONERROR_H

#include <string>
#include <iostream>
#include "Error.h"

using namespace std;

class OptionError : public Error {
public:
	OptionError(const string& msg);
	~OptionError() override;

	void printError() const override;
};

#endif // !OPTIONERROR_H
