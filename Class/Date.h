#ifndef PROGRAM_FILE_DATE_H
#define PROGRAM_FILE_DATE_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Date {

protected:
    string month;
    int day;
    int year;

public:
    Date(string month, int day, int year) {
        this->day = day;
        this->year = year;
        this->month = year;
    }

    Date() {
        this->year = 0;
        this->month = " ";
        this->day = 0;
    }

    const string &getMonth() const {
        return month;
    }

    void setMonth(const string &month) {
        Date::month = month;
    }

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        Date::day = day;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Date::year = year;
    }

    void getDate() {
        cout << getMonth();
        cout << getDay();
        cout << getYear();
        cout << endl;
    }
};


#endif //PROGRAM_FILE_DATE_H
