#pragma once
#ifndef TIME_H
#define TIME_H
#include "Command.h"

class Time : public Command {
public:
	Time();
	~Time() override;

	void function() override;
private:
	int s, m, h;
};

#endif // !TIME_H
