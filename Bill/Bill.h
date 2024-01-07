#ifndef BILL_H
#define BILL_H
#include "Date.h"
#include <fstream>
class Bill
{
private:
    Date day;
    int price;

public:
    Bill(int year = 0, int month = 0, int day = 0, int price = 0) : day(year, month, day), price(price){};
    virtual void Get() const;
    virtual void Update();
    virtual void Read(ifstream &in);
    virtual void Save(ofstream &out);
    virtual void SetMa(int id) = 0;
    virtual int getId() = 0;
    void setPrice(int);
    int getPrice();
    int getDay();
    int getMonth();
    int getYear();
};

#endif