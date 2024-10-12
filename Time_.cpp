#include "Time_.h"

Time_::Time_() : hours(0), minutes(0), seconds(0), format(true) {}

Time_::Time_(int h, int m, int s, bool f) : hours(h), minutes(m), seconds(s), format(f) {}

void Time_::setHour(int h) { hours = h; }
int Time_::getHour() const { return hours; }

void Time_::setMinutes(int m) { minutes = m; }
int Time_::getMinutes() const { return minutes; }

void Time_::setSeconds(int s) { seconds = s; }
int Time_::getSeconds() const { return seconds; }

void Time_::setFormat(bool f) { format = f; }
bool Time_::getFormat() const { return format; }

void Time_::tickTime() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            hours++;
            if (hours >= (format ? 24 : 12)) hours = 0;
        }
    }
}

void Time_::untickTime() {
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
        if (minutes < 0) {
            minutes = 59;
            hours--;
            if (hours < 0) hours = (format ? 23 : 11);
        }
    }
}

void Time_::showTime() const {
    int h = format ? hours : (hours % 12 == 0 ? 12 : hours % 12);
    cout << (h < 10 ? "0" : "") << h << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds;
    if (!format) cout << (hours >= 12 ? " PM" : " AM");
    cout << endl;
}

Time_& Time_::operator += (int s) {
    seconds += s;
    while (seconds >= 60) {
        seconds -= 60;
        minutes++;
        if (minutes >= 60) {
            minutes -= 60;
            hours++;
            if (hours >= 24) hours = 0;
        }
    }
    return *this;
}

Time_ Time_::operator + (int s) const {
    Time_ temp = *this;
    return temp += s;
}

bool Time_::operator == (const Time_& t) const {
    return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
}

bool Time_::operator != (const Time_& t) const {
    return !(*this == t);
}

ostream& operator << (ostream& os, const Time_& t) {
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
       << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
       << (t.seconds < 10 ? "0" : "") << t.seconds;
    if (!t.format) os << (t.hours >= 12 ? " PM" : " AM");
    return os;
}

istream& operator >> (istream& is, Time_& t) {
    char c;
    is >> t.hours >> c >> t.minutes >> c >> t.seconds;
    return is;
}
