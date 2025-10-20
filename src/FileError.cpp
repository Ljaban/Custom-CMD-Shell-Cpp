#include "FileError.h"

FileError::FileError(const string& msg) : Error(msg) {

}

FileError::~FileError()
{
}

void FileError::printError() const
{
	cerr << "File error: " << message << endl;
}
