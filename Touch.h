#pragma once
#ifndef TOUCH_H
#define TOUCH_H
#include "Command.h"

class Touch : public Command {
public:
	Touch(string fileName);
	virtual ~Touch() override;

	void function() override;

private:
	string fileName;
};

#endif // !TOUCH_H
