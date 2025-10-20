#pragma once
#ifndef TR_H

#include <iostream>
#include <string>
#include "FileReader.h"
#include "Command.h"
#include "Decider.h"
#include "FileError.h"

using namespace std;

class Decider;
class FileError;

class TR : public Command {
public:
	TR(const string& text, const string& what, const string& with, const string& fileName, const bool& Flag, bool pipeFlag, Decider& decider);
	~TR() override;

	void function();
	string getText() const;
	string getWhat() const;
	string getWith() const;
	string getFileName() const;

	friend ostream& operator << (ostream& out, const TR& t);

private:
	string text;
	string what;
	string with;
	string fileName;
	bool flag;
	bool pipeFlag;
	Decider& decider;
};

#endif // !TR_H
