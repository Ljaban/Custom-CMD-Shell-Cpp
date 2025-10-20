#pragma once
#ifndef TIME_H
using namespace std;
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Command.h"
#include "Truncate.h"
#include "FileReader.h"
#include "Touch.h"
#include "Decider.h"

class Decider;

class FileError;

class Time : public Command {
public:
	Time(const string& output, bool pipeFlag, Decider& decider);
	~Time() = default;

	void function() override;
	friend ostream& operator<<(ostream& out, const Time& t);

private:
	string output;
	bool pipeFlag;
	Decider& decider;
};

#endif // !TIME_H

