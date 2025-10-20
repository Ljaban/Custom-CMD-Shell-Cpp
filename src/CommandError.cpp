#include "CommandError.h"

CommandError::CommandError(const string& msg) : Error(msg)
{
}

CommandError::~CommandError()
{
}

void CommandError::printError() const
{
	cerr << "Command Error: " << message << endl;
}
