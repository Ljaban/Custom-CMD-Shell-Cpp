#pragma once
#ifndef COMMAND_H
using namespace std;

class Command {
public:
	Command() = default;
	virtual ~Command() = default;

	virtual void function() = 0;
};
#endif // COMMAND_H

