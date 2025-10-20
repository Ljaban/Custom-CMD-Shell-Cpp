#include "Error.h"

Error::Error(const string& msg) : message(msg)
{
}

string Error::getMessage() const
{
	return message;
}
