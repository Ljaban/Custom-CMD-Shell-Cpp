// Echo.h
#pragma once
#ifndef ECHO_H
#define ECHO_H

#include <iostream>
#include <string>
#include "Command.h"
#include "Separator.h"
#include "FileReader.h"
#include "Touch.h"
#include "Truncate.h"
#include "Decider.h"
#include "FileError.h"

class Decider;

class FileError;

class Echo : public Command {
public:
    Echo(const string& line, bool multilineFlag, const string& fileName, Decider& dec, bool pipeFlag);
    ~Echo() override;

    virtual void function() override;
    const string& getText() const;
    bool hasQuotes() const;
    bool isInvalidQuotes() const;

private:
    string text;
    string fileName;
    bool flag;
    bool pipeFlag;
    Decider& decider;
};

#endif // ECHO_H
