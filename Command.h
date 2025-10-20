#pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include <string>
using namespace std;

class Command {
public:
    Command() = default;
    virtual ~Command() = default;

    virtual void function() = 0;

protected:
    string command;
};
#endif

