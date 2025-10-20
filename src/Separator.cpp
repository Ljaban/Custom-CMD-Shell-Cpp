#include "Separator.h"

Separator::Separator(const string& line, bool pipeFlag, const string& res) : wholeLine(line), pipeFlag(pipeFlag), res(res)
{
}

Separator::~Separator()
{
}

vector<string> Separator::splitByPipe() const
{
	vector<string> parts;
	size_t start = 0;
	size_t pos = wholeLine.find('|');

	while (pos != string::npos) {
		parts.push_back(wholeLine.substr(start, pos - start));
		start = pos + 1;
		pos = wholeLine.find('|', start);
	}

	parts.push_back(wholeLine.substr(start));
	return parts;
}

void Separator::getArguments()
{
	istringstream iss(wholeLine);
	iss >> command;

	if (command == "time" || command == "date") {
		getline(iss, argument);
		return;
	}
		
	if (command == "echo") {
		if (pipeFlag) {
			argument = res;
			return;
		}
		getline(iss, argument);

		size_t pos = argument.find_first_not_of(" \t");
		if (pos != string::npos) {
			argument = argument.substr(pos);
		};

		if (argument.empty()) {
			string temp, block;
			while (getline(cin, temp)) {
				block += temp + "\n";
			}
			argument = block;
			flag = true;
		}
		else {
			if (argument.find('"') == string::npos &&
				argument.find('\'') == string::npos &&
				argument.find('|') == string::npos &&
				argument.find(';') == string::npos) {
				fileName = argument;
				argument.clear();
			}
		}
		return;
	}

	if (command == "prompt") {
		getline(iss, argument);
		size_t pos = argument.find_first_not_of(" \t");
		if (pos != string::npos) {
			argument = argument.substr(pos);
		};
		return;
	}

	if (command == "touch" || command == "truncate" || command == "rm") {
		if (pipeFlag) {
			fileName = res;
			return;
		}
		iss >> fileName;
		return;
	}

	if (command == "wc") {
		iss >> option;
		if (pipeFlag) {
			argument = res;
			return;
		}
		getline(iss, argument);

		size_t pos = argument.find_first_not_of(" \t");
		if (pos != string::npos) {
			argument = argument.substr(pos);
		};

		if (argument.empty()) {
			string temp, block;
			while (getline(cin, temp)) {
				block += temp + "\n";
			}
			argument = block;
			flag = true;
		}
		else {
			if (argument.find('"') == string::npos &&
				argument.find('\'') == string::npos &&
				argument.find('|') == string::npos &&
				argument.find(';') == string::npos) {
				fileName = argument;
				argument.clear(); 
			}
		}
		return;
	}

	if (command == "head") {
		iss >> option;
		if (pipeFlag) {
			argument = res;
			return;
		}
		string temp, block;
		while (getline(cin, temp)) {
			block += temp + "\n";
		}
		argument = block;
		flag = true;
		cin.clear();
		return;
	}

	if (command == "tr") {
		string remainingLine;
		getline(iss, remainingLine);

		size_t firstQuote = remainingLine.find('"');

		if (firstQuote != string::npos) {
			argument = remainingLine.substr(0, firstQuote);

			size_t pos = argument.find_first_not_of(" \t");
			if (pos != string::npos) {
				fileName = argument.substr(pos);
				argument.clear();
			}
			else {
				argument.clear();
			}
			size_t secondQuote = remainingLine.find('"', firstQuote + 1);
			if (secondQuote != string::npos) {
				what = remainingLine.substr(firstQuote + 1, secondQuote - firstQuote - 1);
				size_t thirdQuote = remainingLine.find('"', secondQuote + 1);
				if (thirdQuote != string::npos) {
					size_t fourthQuote = remainingLine.find('"', thirdQuote + 1);
					if (fourthQuote != string::npos) {
						with = remainingLine.substr(thirdQuote + 1, fourthQuote - thirdQuote - 1);
					}
					else {
						with.clear();
					}
				}
				else {
					with.clear();
				}
			}
			if (pipeFlag) {
				argument = res;
				return;
			}
		}
		else {
			istringstream lineStream(remainingLine);
			string token;

			if (lineStream >> token) {
				if (token.find('"') == string::npos && token.find(';') == string::npos) {
					fileName = token;
				}
				else {
					what = token;
				}
			}
			if (what.empty() && lineStream >> token) {
				what = token;
			}
			if (lineStream >> token) {
				with = token;
			}
			else {
				with.clear();
			}
		}
		if (fileName.empty()) {
			string temp, block;
			while (getline(cin, temp)) {
				block += temp + "\n";
			}
			argument = block;
			flag = true;
			cin.clear();
		}
		return;
	}

	if (command == "batch") {
		if (pipeFlag) {
			argument = res;
			return;
		}
		getline(iss, argument);
		size_t pos = argument.find_first_not_of(" \t");

		if (pos != string::npos) {
			argument = argument.substr(pos);
		}
		else {
			argument.clear();
		}

		if (argument.empty()) {
			string temp, block;
			while (getline(cin, temp)) {
				block += temp + "\n";
			}
			argument = block;
			isBatch = true;
			cin.clear();
		}
		else {
			isBatch = true;
			fileName = argument;
			argument.clear();
		}
		return;
	}
}

string Separator::getCommand() const 
{
	return command;
}


string Separator::getArgument() const
{
	return argument;
}

string Separator::getFileName() const
{
	return fileName;
}

string Separator::getOption() const
{
	return option;
}

string Separator::getWhat() const
{
	return what;
}

string Separator::getWith() const
{
	return with;
}

void Separator::setArgument(const string& arg)
{
	argument = arg;
}

void Separator::setFileName(const string& fileN)
{
	fileName = fileN;
}

bool Separator::getFlag() const
{
	return flag;
}

bool Separator::isBatchBlock() const
{
	return isBatch;
}
