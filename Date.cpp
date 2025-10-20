#include "Date.h"
#include <chrono>
#include <iostream>

Date::Date() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);

    tm local_time;
    localtime_s(&local_time, &now_time);

    day = local_time.tm_mday;
    month = local_time.tm_mon + 1;
    year = local_time.tm_year + 1900;
}
Date::~Date() {
}

void Date::function() {
    cout << "Danasnji datum: " << (day < 10 ? "0" : "") << day << "."
        << (month < 10 ? "0" : "") << month << "."
        << year << "." << endl;
}
