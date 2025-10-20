#include "OptionError.h"

OptionError::OptionError(const string& msg) : Error(msg)
{
}

OptionError::~OptionError()
{
}

void OptionError::printError() const
{
	cerr << "Option Error: " << message << endl;
}
