#include "WC.h"
#include <iostream>

Wc::Wc(char c, string line): c(c), line(line) {
}

Wc::~Wc()
{
}

int countW(string s) {
	int count = 0;
	bool in = false;

	for (char c : s) {
		if (isspace(c)) {
			in = false;
		}
		else {
			if (!in) {
				count++;
				in = true;
			}
		}
	}

	return count;
}

int countC(string s) {
	int count = 0;
	if (s[0] == ' ') {
		s.erase(0, 1);
	}
	for (char c : s) {
		if (c != '"' && c != '\n') {
			count++;
		}
	}
	return count;
}

void Wc::function() {
	int counted = 0;
	string line = getLine();
	if (getC() == 'w') {
		counted = countW(line);
		cout << "Broj reci u komandi: " << counted << endl;
	}
	else if (getC() == 'c') {
		counted = countC(line);
		cout << "Broj znakova u komandi: " << counted << endl;
	}
}

const char Wc::getC()
{
	return c;
}

string Wc::getLine()
{
	return line;
}
