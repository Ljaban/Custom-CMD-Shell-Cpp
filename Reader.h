#pragma once
#include <string>
#include <iostream>
using namespace std;
#ifndef READER_H
#define READER_H

class Reader {
public:
	Reader() = default;
	virtual ~Reader() = default;

	virtual string readLine() = 0;
};

#endif // !READER_H
