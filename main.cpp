#include <iostream>
#include "Echo.h"
#include "Command.h"
#include "Time.h"
#include "Date.h"
#include "Touch.h"
#include "WC.h"
#include "Reader.h"
#include "LineReader.h"
#include "Separator.h"
#include "Prompt.h"
#include "Decider.h"
using namespace std;

int main() {
    string input;

    while (true) {
        Prompt prompt;
        cout << prompt.getPrompt() << " ";

        if (cin.eof()) {
            cin.clear();
        }
        
        LineReader reader;
        string line = reader.readLine();
        if (line == "") {
            cout << "Greska" << endl;
            continue;
        }
        Separator sep(line);
        sep.parseCommand();
        sep.parseOption();
        sep.parseText();
        Decider decided(sep);
        decided.chooseCommand();
    }

    return 0;
}
