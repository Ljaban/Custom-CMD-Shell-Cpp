#pragma once
#ifndef DATE_H
#define DATE_H
#include "Command.h"

class Date : public Command {
public:
	Date();
	virtual ~Date() override;

	virtual void function() override;

private:
	int day, month, year;
};

#endif // !DATE_H
