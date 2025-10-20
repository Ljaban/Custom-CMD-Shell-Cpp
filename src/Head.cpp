#include "Head.h"

Head::Head(const int& ncount, const string& argument, bool pipeFlag, Decider& decider) : Command(), n(ncount), text(argument), pipeFlag(pipeFlag), decider(decider)
{
}

Head::~Head()
{
}

static string toString(const Head& h) {
    ostringstream oss;
    oss << h; 
    return oss.str();
}

void Head::function() {
    if (!pipeFlag) {
        cout << *this << endl;
        return;
    }
    else {
        string res = toString(*this);
        decider.setResult(res);
        return;
    }
}

int Head::getN() const
{
	return n;
}

string Head::getText() const
{
	return text;
}

ostream& operator<<(ostream& out, const Head& h) {
    istringstream iss(h.getText());
    string line;
    int count = 0;

    while (count < h.getN() && getline(iss, line)) {
        if (count != h.getN() - 1) out << line << endl;
        else out << line;
        count++;
    }

    return out;
}

