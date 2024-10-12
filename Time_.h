#pragma once
#include <iostream>
using namespace std;

class Time_ {
    int hours;
    int minutes;
    int seconds;
    bool format;

public:
    Time_();
    Time_(int hours, int minutes, int seconds = 0, bool format = true);

    void setHour(int hours);
    int getHour() const;
    void setMinutes(int minutes);
    int getMinutes() const;
    void setSeconds(int seconds);
    int getSeconds() const;
    void setFormat(bool format);
    bool getFormat() const;

    void tickTime();
    void untickTime();
    void showTime() const;

    Time_& operator += (int s);
    Time_ operator + (int s) const;

    bool operator == (const Time_& t) const;
    bool operator != (const Time_& t) const;

    friend ostream& operator << (ostream& os, const Time_& t);
    friend istream& operator >> (istream& is, Time_& t);
};
