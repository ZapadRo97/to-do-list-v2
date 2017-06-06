#include "date.h"
#include <iostream>
#include <ctime>

using namespace std;

Date::Date()
{
    //ctor
}

Date::~Date()
{
    //dtor
}

void Date::SetDate(int hour, int minute)
{
    //auto get day month year from system time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    this->hour = hour;
    this->minute = minute;
}

void Date::SetDate(int day, int month, int year)
{
    this->day = day; this->month = month; this->year = year;
}

void Date::ShowDate()
{
    cout<<"Year: "<<year<<" Month: "<<month<<" Day: "<<day<<" Hour: "<<hour<<" Minute: "<<minute;
}
