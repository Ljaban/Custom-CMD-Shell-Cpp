#pragma once
#ifndef DECIDER_H
#define DECIDER_H
#include "Prompt.h"
#include <string>
#include "Command.h"
#include "WC.h"
#include "Echo.h"
#include "Time.h"
#include "Date.h"
#include "Touch.h"
#include "FileReader.h"
#include "LineReader.h"
using namespace std;
#include "Separator.h"
#include <iostream>

class Decider {
public:
	Decider(Separator sep);
	~Decider();

	void chooseCommand();
	string getCom() const;
	char getOpt() const;
	string getText() const;
	void file();

private:
	string command;
	char option;
	string textOrF;

};

#endif // !DECIDER_H

