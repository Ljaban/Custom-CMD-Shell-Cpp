#pragma once
#ifndef DECIDER_H

#include <iostream>
#include <string>
#include "Command.h"
#include "Echo.h"
#include "LineReader.h"
#include "Separator.h"
#include "Date.h"
#include "Time.h"
#include "Prompt.h"
#include "Touch.h"
#include "Truncate.h"
#include "Rm.h"
#include "WC.h"
#include "Head.h"
#include "Tr.h"
#include "Batch.h"
#include "CommandError.h"
#include "OptionError.h"

using namespace std;
class OptionError;
class Decider {
public:
	Decider(const Separator& s, Prompt& p, bool pipeFlag);
	~Decider();

    void decide();
	string getResult() const;

	friend class Echo;
	friend class WC;
	friend class TR;
	friend class Head;
	friend class Batch;
	friend class Time;
	friend class Date;
	friend class Touch;
	friend class Truncate;

protected:
	void setResult(const string& res);

private:
    Separator separator;
	string result;
	bool pipeFlag;
	Prompt& p;
};

#endif // !DECIDER_H
