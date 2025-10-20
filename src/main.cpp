#include <iostream>
#include <string>
#include "Command.h"
#include "Echo.h"
#include "LineReader.h"
#include "Separator.h"
#include "Date.h"
#include "Time.h"
#include "Prompt.h"
#include "Touch.h"
#include "Truncate.h"
#include "Rm.h"
#include "WC.h"
#include "Head.h"
#include "Tr.h"
#include "Batch.h"
#include "Decider.h"

using namespace std;

int main() {
    Prompt p;
    while (true) {
        if (cin.eof()) {
            cin.clear();
        }

        cout << p.getSign() << " ";
        LineReader reader;
        string linija = reader.read();

        Separator line(linija, false, "");
        vector<string> commands = line.splitByPipe();

        string prevResult;

        for (size_t i = 0; i < commands.size(); i++) {
            bool pipe = true;
            if (i == 0) pipe = false;
            Separator cmd(commands[i], pipe, prevResult);
            if (!prevResult.empty()) {
                if (cmd.getCommand() == "echo" || cmd.getCommand() == "prompt" || cmd.getCommand() == "wc" ||
                    cmd.getCommand() == "tr" || cmd.getCommand() == "head" || cmd.getCommand() == "batch") {
                    cmd.setArgument(prevResult);
                }
                else if (cmd.getCommand() == "touch" || cmd.getCommand() == "truncate" || cmd.getCommand() == "rm") {
                    cmd.setFileName(prevResult);
                }
            }
            cmd.getArguments();
            if (i != commands.size() - 1) {
                Decider decider(cmd, p, true);
                decider.decide();
                prevResult = decider.getResult();
            }
            else {
                Decider decider(cmd, p, false);
                decider.decide();
            }
        }
    }

    return 0;
}
