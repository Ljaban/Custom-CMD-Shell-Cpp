#include "Decider.h"
Decider::Decider(Separator sep) {
    command = sep.getFunction();
    option = sep.getChar();
    textOrF = sep.getText();
}

Decider::~Decider()
{
}

void Decider::chooseCommand() {
    command.erase(0, command.find_first_not_of(" \t"));
    command.erase(command.find_last_not_of(" \t") + 1);

    if (getText().size() > 1 &&
        (getText()[1] != '\"' && getText()[0] !='\"') &&
        getText()[0] != '\n' &&
        (getCom() != "date" && getCom() != "time" && getCom() != "touch")) {

        file();
    }
 
    if (command == "wc") {
        if (option == 'w' || option == 'c') {
            Wc wc(option, textOrF);
            wc.function();
        }
    }
    else if (command == "echo") {
        Echo echo(textOrF);
        echo.function();
    }
    else if (command == "date") {
        Date date;
        date.function();
    }
    else if (command == "time") {
        Time time;
        time.function();
    }
    else if (command == "touch") {
        Touch touch(textOrF);
        touch.function();
    }
    else {
        cout << "Nepoznata komanda!" << endl;
    }
}

string Decider::getCom() const
{
	return command;
}

char Decider::getOpt() const
{
	return option;
}

string Decider::getText() const
{
	return textOrF;
}

void Decider::file() {
    textOrF = FileR::FileR(textOrF).readLine();
}
