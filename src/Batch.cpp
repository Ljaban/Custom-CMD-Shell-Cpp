#include "Batch.h"

Batch::Batch(const string& functions, Prompt& p, const string& fileName) : Command(), listOfFunctions(functions), p(p), fileName(fileName)
{
}

Batch::~Batch()
{
}

void Batch::function() {
    try {
        if (!fileName.empty()) {
            ifstream file(fileName);
            if (!file.is_open()) {
                throw FileError("Greska: ne mogu da otvorim fajl '" + fileName + "'");
            }

            ostringstream content;
            string line;
            while (getline(file, line)) {
                content << line << "\n";
            }

            listOfFunctions = content.str();
            file.close();
        }

        if (listOfFunctions.empty()) {
            return;
        }

        istringstream iss(listOfFunctions);
        string line;
        int lineNumber = 1;

        while (getline(iss, line)) {
            if (line.find_first_not_of(" \t") == string::npos) {
                lineNumber++;
                continue;
            }

            try {
                Separator separator(line, false, "");
                separator.getArguments();

                Decider decider(separator, p, false);
                decider.decide();
            }
            catch (const FileError& e) {
                cout << "Greska u liniji " << lineNumber << ": " << line << endl;
                e.printError();
            }
            catch (const exception& e) {
                cout << "Greska u liniji " << lineNumber << ": " << line << endl;
                cout << "Error: " << e.what() << endl;
            }

            lineNumber++;
        }
    }
    catch (const FileError& e) {
        e.printError();
    }
}

string Batch::getFunctions() const
{
	return listOfFunctions;
}
