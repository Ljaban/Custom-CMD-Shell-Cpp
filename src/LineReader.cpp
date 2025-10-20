#include "LineReader.h"

LineReader::LineReader()
{
	getline(cin, line);
}

LineReader::~LineReader()
{
}

string LineReader::read()
{
	return line;
}
