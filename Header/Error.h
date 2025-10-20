#pragma once
#ifndef ERROR_H
#include <string>
#include <iostream>

using namespace std;

class Error {
public:
	Error(const string& msg);
	virtual ~Error() = default;

	virtual void printError() const = 0;
	string getMessage() const;
protected:
	string message;
};


#endif // !ERROR_H
