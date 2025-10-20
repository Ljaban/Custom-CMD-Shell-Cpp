#pragma once
#ifndef DATE_H

#include <iostream>
#include "Command.h"
#include "FileReader.h"
#include "Touch.h"
#include "Truncate.h"
#include "Decider.h"
#include "FileError.h"
#include <ctime>
#include <iomanip>
#include <sstream>

class Decider;

class FileError;

class Date : Command {
public:
    Date(const string& output, bool pipeFlag, Decider& decider);
    ~Date() = default;

    void function() override;
    friend ostream& operator<<(ostream& out, const Date& d);

private:
    string output;
    Decider& decider;
    bool pipeFlag;
};
#endif // !DATE_H