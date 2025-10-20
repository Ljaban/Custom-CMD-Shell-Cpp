#include "Decider.h"

Decider::Decider(const Separator& s, Prompt& p, bool pipeFlag) : separator(s), p(p), pipeFlag(pipeFlag)
{
}

Decider::~Decider()
{
}

void Decider::decide()
{
    try {
        if (separator.getCommand() == "echo") {
            Echo ispis(separator.getArgument(), separator.getFlag(), separator.getFileName(), *this, pipeFlag);
            ispis.function();
        }
        else if (separator.getCommand() == "date") {
            Date datum(separator.getArgument(), pipeFlag, *this);
            datum.function();
        }
        else if (separator.getCommand() == "time") {
            Time time(separator.getArgument(), pipeFlag, *this);
            time.function();
        }
        else if (separator.getCommand() == "prompt") {
            p.setSign(separator.getArgument()[1]);
        }
        else if (separator.getCommand() == "touch") {
            Touch file(separator.getFileName());
            file.function();
        }
        else if (separator.getCommand() == "truncate") {
            Truncate file(separator.getFileName());
            file.function();
        }
        else if (separator.getCommand() == "rm") {
            Rm file(separator.getFileName());
            file.function();
        }
        else if (separator.getCommand() == "wc") {
            WC count(separator.getOption()[1], separator.getArgument(), separator.getFlag(), separator.getFileName(), pipeFlag, *this);
            count.function();
        }
        else if (separator.getCommand() == "head") {
            string numberPart = separator.getOption().substr(2);
            int numPt = stoi(numberPart);
            Head glava(numPt, separator.getArgument(), pipeFlag, *this);
            glava.function();
        }
        else if (separator.getCommand() == "tr") {
            TR tr(separator.getArgument(), separator.getWhat(), separator.getWith(), separator.getFileName(), separator.getFlag(), pipeFlag, *this);
            tr.function();
        }
        else if (separator.getCommand() == "batch") {
            Batch batch(separator.getArgument(), p, separator.getFileName());
            batch.function();
        }
        else {
            throw CommandError("Nepoznata komanda: " + separator.getCommand());
        }
    }
    catch (const Error& e) {
        e.printError();
    }
}


string Decider::getResult() const
{
	return result;
}

void Decider::setResult(const string& res)
{
	result = res;
}
