#include "Product.h"
#include "../lib/lib.h"
Product::Product(string name, int price, string guide) : name(name), price(price), guide(guide)
{
    maSP = ++setID;
};

Product::~Product(){};

int Product::setID = 0;
void Product::Get()
{
    string str = guide.substr(0, 63);
    if (str.length() > 62)
    {
        str += "...";
    }
    string number = to_string(price);
    int n = number.length() / 3;
    if (number.length() % 3 == 0)
    {
        n = n - 1;
    }
    int i = n;
    string str1 = number.substr(0, number.length() - 3 * n);
    while (i > 0)
    {
        str1 += ".";
        str1 += number.substr(number.length() - 3 * i, number.length() - 3 * (i - 1) - 1);
        i--;
    }
    cout << setw(8);
    TextColor(6);
    cout << "|" << setw(4);
    TextColor(7);
    cout << maSP;
    TextColor(6);
    cout << "|" << setw(24);
    TextColor(7);
    cout << name;
    TextColor(6);
    cout << "|" << setw(9);
    TextColor(7);
    cout << str1;
    TextColor(6);
    cout << "|" << setw(66);
    TextColor(7);
    cout << str;
    TextColor(6);
    cout << "|" << endl;
    TextColor(7);
};
void Product::GetDetail()
{
    int n = guide.length() / 100;
    cout << "\n\n";
    TextColor(6);
    cout << "\tPreparing: \n";
    TextColor(7);
    for (int i = 0; i < n; i++)
    {
        string str = "";
        str = guide.substr(str.length(), str.length() + 100);
        while (str.back() != ' ')
        {
            str = str.substr(0, str.length() - 1);
        }
        cout << "\t\t" << str << endl;
    }
    cout << "\t\t" << guide.substr(n * 100, guide.length());
}
void Product::Read(ifstream &in)
{
    in >> maSP;
    in.ignore(1);
    getline(in, name, ';');
    getline(in, guide, ';');
    in >> price;
};
void Product::Save(ofstream &out)
{
    out << maSP << ";" << name << ";" << guide << ";" << price << endl;
};
int Product::getPrice()
{
    return price;
};
void Product::Update()
{
    TextColor(6);
    cout << setw(21) << "|";
    TextColor(7);
    cout << maSP;
    gotoxy(26, 7);
    TextColor(6);
    cout << "|";
    TextColor(7);
    cout<<name;
    gotoxy(51, 7);
    TextColor(6);
    cout << "|";
    TextColor(7);
    cin >> price;
    fflush(stdin);
    gotoxy(65, 7);
    TextColor(6);
    cout << "|" << endl;
    cout << "                    ";
    cout << "+-----+------------------------+-------------+" << endl;
    cout << "                    Guide: ";
    TextColor(7);
    getline(cin, guide);
}
bool Product::Search(string name)
{
    return this->name == name;
};
void Product::SetMa(int id)
{
    setID = id;
};
int Product::getId()
{
    return maSP;
};
string Product::getName()
{
    return name;
};
