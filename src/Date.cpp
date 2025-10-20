#include "Date.h"
#include "FileError.h"

std::ostream& operator<<(std::ostream& out, const Date& d) {
    std::time_t t = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &t);

    out << std::setfill('0')
        << std::setw(2) << localTime.tm_mday << "/"
        << std::setw(2) << (localTime.tm_mon + 1) << "/"
        << (localTime.tm_year + 1900);

    return out;
}


Date::Date(const string& output, bool pipeFlag, Decider& decider) : output(output), pipeFlag(pipeFlag), decider(decider)
{
}

static void findOutputDate(string& outputFile) {
    outputFile = outputFile.substr(2);
    size_t start = outputFile.find_first_not_of(" \t\n\r");
    size_t end = outputFile.find_last_not_of(" \t\n\r");
    outputFile = outputFile.substr(start, end - start + 1);
}

static string getCurrentDateString() {
    std::time_t t = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &t);

    std::ostringstream oss;
    oss << std::setfill('0')
        << std::setw(2) << localTime.tm_mday << "/"
        << std::setw(2) << (localTime.tm_mon + 1) << "/"
        << (localTime.tm_year + 1900);

    return oss.str();
}

void Date::function()
{
    if (output.empty() || output == " ") {
        if (!pipeFlag) {
            cout << *this << endl;
            return;
        }
        else {
            string outputReS = getCurrentDateString();
            decider.setResult(outputReS);
        }
    }
    else {
        size_t start = output.find_first_not_of(" \t\n\r");
        size_t end = output.find_last_not_of(" \t\n\r");
        output = output.substr(start, end - start + 1);

        if (output[0] == '>' && output[1] == '>') {
            findOutputDate(output);
            FileReader fr(output);
            if (!fr.canOpen()) {
                Touch t(output);
                t.function();
            }

            if (!pipeFlag) {
                ofstream ofs(output, ios::app);
                if (!ofs) {
                    throw FileError("Greska: ne mogu da kreiram ili otvorim fajl '" + output + "'");
                }
                ofs << *this;
                ofs.close();
            }
            else {
                string outputReS = getCurrentDateString();
                decider.setResult(outputReS);
            }
        }
        else if (output[0] == '>' && output[1] != '>') {
            findOutputDate(output);
            FileReader fr(output);
            if (!fr.canOpen()) {
                Touch t(output);
                t.function();
            }
            Truncate tr(output);
            tr.function();

            if (!pipeFlag) {
                ofstream ofs(output, ios::app);
                if (!ofs) {
                    throw FileError("Greska: ne mogu da kreiram ili otvorim fajl '" + output + "'");
                }
                ofs << *this;
                ofs.close();
            }
            else {
                string outputReS = getCurrentDateString();
                decider.setResult(outputReS);
            }
        }
    }
}
