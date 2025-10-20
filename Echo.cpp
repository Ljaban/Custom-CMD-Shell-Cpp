#include "Echo.h"
#include <iostream>
Echo::Echo(const string& s): Command(), line(s){
}

Echo::~Echo()
{
}

string Echo::getLine() const {
	return line;
}

void Echo::function() {
	string linija = getLine();
	if (!linija.empty() && (linija.front() == '\n' || linija.front() == '"')) {
		linija.erase(linija.begin());
	}
	if (!linija.empty() && (linija.back() == '\n' || linija.back() == '"')) {
		linija.pop_back();
	}
	cout << linija << endl;
}
