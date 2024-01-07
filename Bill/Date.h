#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date
{
    int year, month, day;

public:
    Date(int year = 0, int month = 0, int day = 0) : year(year), month(month), day(day){};
    void Get() const
    {
        cout << day << " / " ;
        if(month<10){
            cout<<"0";
        }
        cout<< month << " / " << year ;
    }
    void Set(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
};

#endif