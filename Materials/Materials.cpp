#include "Materials.h"
#include <fstream>
#include <iostream>
using namespace std;
Materials::Materials(string name, int quantity, string unit) : name(name), quantity(quantity), unit(unit)
{
    maNL = ++setID;
};

Materials::~Materials(){};

int Materials::setID = 0;
void Materials::Get()
{
    cout << setw(18);
    TextColor(6);
    cout << "|" << setw(5);
    TextColor(7);
    cout << maNL;
    TextColor(6);
    cout << "|" << setw(26);
    TextColor(7);
    cout << name;
    TextColor(6);
    cout << "|" << setw(23);
    TextColor(7);
    cout << quantity;
    TextColor(6);
    cout << "|" << setw(18);
    TextColor(7);
    cout << unit;
    TextColor(6);
    cout << "|" << endl;
    TextColor(7);
};
int Materials::getId()
{
    return maNL;
}
void Materials::Read(ifstream &in)
{
    in >> maNL;
    in.ignore(1);
    getline(in, name, ',');
    getline(in, unit, ',');
    in >> quantity;
}
void Materials::Save(ofstream &out)
{
    out << maNL << "," << name << "," << unit << "," << quantity << endl;
}
void Materials::Update()
{
    TextColor(6);
    cout << setw(18) << "|";
    TextColor(7);
    cout << maNL;
    gotoxy(23, 7);
    TextColor(6);
    cout << "|";
    TextColor(7);
    cout << name;
    gotoxy(50, 7);
    TextColor(6);
    cout << "|";
    TextColor(7);
    fflush(stdin);
    cin >> quantity;
    gotoxy(74, 7);
    TextColor(6);
    cout << "|";
    unit="";
    while (unit != "ml" && unit != "g")
    {
        gotoxy(75, 7);
        for(int i= 0;i<unit.length();i++){
            cout<<" ";
        }
        gotoxy(75,7);
        TextColor(7);
        getline(cin, unit);
        fflush(stdin);
    }

    gotoxy(93, 7);
    TextColor(6);
    cout << "|" << endl;
    TextColor(7);
}
void Materials::UpdateSL(int SL)
{
    quantity += SL;
}
bool Materials::Search(string name)
{
    return this->name == name;
}
void Materials::SetMa(int id)
{
    setID = id;
}
string Materials::getName()
{
    return name;
}
string Materials::getUnit()
{
    return unit;
}