#pragma once
#ifndef READER_H
using namespace std;

#include <iostream>
#include <string>

class Reader {
public:
	Reader() = default;

	virtual string read() = 0;
};

#endif // !READER_H

