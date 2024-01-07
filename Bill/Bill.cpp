#include "Bill.h"
#include <iostream>
#include <fstream>
using namespace std;
void Bill::Get() const
{
    string number = to_string(price);
    int n = number.length() / 3;
    if (number.length() % 3 == 0)
    {
        n = n - 1;
    }
    int i = n;
    string str = number.substr(0, number.length() - 3 * n);
    while (i > 0)
    {
        str += ".";
        str += number.substr(number.length() - 3 * i, number.length() - 3 * (i - 1) - 1);
        i--;
    }
    TextColor(6);
    cout << "|" << setw(7);
    TextColor(7);
    day.Get();
    TextColor(6);
    cout << "|" << setw(21);
    TextColor(7);
    cout << str;
    TextColor(6);
    cout << "|";
    TextColor(7);
}
void Bill::Update()
{
    TextColor(6);
    cout << "|";
    TextColor(7);
    cout << day.getDay() << "/" << day.getMonth() << "/" << day.getYear();
}

void Bill::Read(ifstream &in)
{
    int d, m, y;
    in >> d;
    in.ignore(1);
    in >> m;
    in.ignore(1);
    in >> y;
    day.Set(d, m, y);
    in.ignore(1);
    in >> price;
}
void Bill::Save(ofstream &out)
{
    out << "," << day.getDay() << "/" << day.getMonth() << "/" << day.getYear() << "," << price << endl;
}
int Bill::getDay()
{
    return day.getDay();
}
int Bill::getMonth()
{
    return day.getMonth();
}
int Bill::getYear()
{
    return day.getYear();
}
int Bill::getPrice()
{
    return price;
}
void Bill::setPrice(int totalPrice)
{
    price = totalPrice;
}