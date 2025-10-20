#pragma once
#ifndef LINEREADER_H
#define LINEREADER_H
#include "Reader.h"
#include "Separator.h"

class LineReader : public Reader {
public:
	LineReader();
	virtual ~LineReader() override;

	virtual string readLine();

private:
	string all;
};

#endif // !MANUELR_H

