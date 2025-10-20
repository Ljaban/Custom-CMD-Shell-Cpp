#include "Time.h"
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;

Time::Time() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);

    tm local_time; 
    localtime_s(&local_time, &now_time);

    s = local_time.tm_sec;
    m = local_time.tm_min;
    h = local_time.tm_hour;
}

Time::~Time() {
}

void Time::function() {
    cout << "Trenutno vreme: " << (h < 10 ? "0" : "") << h << ":"
        << (m < 10 ? "0" : "") << m << ":"
        << (s < 10 ? "0" : "") << s << endl;
}


