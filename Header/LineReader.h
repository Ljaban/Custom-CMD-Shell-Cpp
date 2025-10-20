#pragma once
#ifndef LINEREADER_H
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include "Reader.h"

class LineReader : public Reader {
public:
	LineReader();
	~LineReader();

	string read() override;

private:
	string line;
};

#endif // !LINEREADER_H

