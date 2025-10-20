#include "Touch.h"
#include <fstream> 
#include <iostream>
#include <sys/stat.h>

Touch::Touch(string fileName) : fileName(fileName) {}

Touch::~Touch() {
}

void Touch::function() {
    struct stat buffer;
    if (stat(fileName.c_str(), &buffer) == 0) {
        cout << "Greska: Fajl vec postoji." << endl;
        return;
    }

    ofstream file(fileName);
    if (file.is_open()) {
        file.close();
        cout << "Fajl " << fileName << " je uspesno kreiran." << endl;
    }
    else {
        cout << "Greska: Nije moguce kreirati fajl." << endl;
    }
}
