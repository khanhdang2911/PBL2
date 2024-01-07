#ifndef INBILL_H
#define INBILL_H
#include "Bill.h"
#include "../lib/lib.h"
class InBill : public Bill
{
private:
    int maHD, maPS;
    int static setID;
    string paymentType;
    string static type;

public:
    InBill(int year = 0, int month = 0, int day = 0, int price = 0, int maPS = 0, string paymentType = "") : Bill(year, month, day, price), maPS(maPS), paymentType(paymentType)
    {
        maHD = ++setID;
    };
    virtual void Get() const
    {
        cout << setw(13);
        TextColor(6);
        cout << "|" << setw(5);
        TextColor(7);
        cout << maHD;
        TextColor(6);
        cout << "|" << setw(13);
        TextColor(7);
        cout << maPS;
        TextColor(6);
        cout << "|" << setw(19);
        TextColor(7);
        cout << type;
        Bill::Get();
        cout << setw(18) << paymentType;
        TextColor(6);
        cout << "|" << endl;
        TextColor(7);
    }
    virtual void Read(ifstream &in)
    {
        in >> maHD;
        in.ignore(1);
        in >> maPS;
        in.ignore(1);
        getline(in, paymentType, ',');
        Bill::Read(in);
    }
    virtual void Save(ofstream &out)
    {
        out << maHD << "," << maPS << "," << paymentType;
        Bill::Save(out);
    }
    virtual void Update()
    {
        TextColor(6);
        cout << setw(18) << "|";
        TextColor(7);
        cout << maHD;
        gotoxy(23, 8);
        TextColor(6);
        cout << "|";
        TextColor(7);
        cout << maPS;
        gotoxy(37, 8);
        TextColor(6);
        cout << "|";
        TextColor(7);

        bool check = false;
        string errPayment = "Please enter the correct payment method!";
        while (true)
        {
            if (check)
            {
                gotoxy(23, 4);
                TextColor(4);
                cout << errPayment;
                TextColor(7);
            }
            gotoxy(40, 8);
            for (int i = 0; i < paymentType.length(); i++)
            {
                cout << " ";
            }
            gotoxy(40, 8);
            getline(cin, paymentType);
            if (paymentType == "cash" || paymentType == "Cash" || paymentType == "Banking" || paymentType == "banking" || paymentType == "0" || paymentType == "1")
            {
                break;
            }
            else
            {
                check = true;
            }
        }
        gotoxy(23, 4);
        for (int i = 0; i < errPayment.length(); i++)
        {
            cout << " ";
        }

        gotoxy(57, 8);
        Bill::Update();
        gotoxy(77, 8);
        TextColor(6);
        cout << "|" << endl;
        TextColor(7);
    }
    virtual void SetMa(int id)
    {
        setID = id;
    }
    virtual int getId()
    {
        return maHD;
    }
};
int InBill::setID = 0;
string InBill::type = "Good Receipt";
#endif