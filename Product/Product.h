#pragma once

class Product
{
private:
    int maSP;
    string name;
    int price;
    string guide;

    int static setID;

public:
    Product(string name = "", int price = 0, string guide = "");
    ~Product();

    void Get();
    void GetDetail();
    void Read(ifstream &in);
    void Save(ofstream &out);
    void Update();
    bool Search(string name);
    void SetMa(int id);
    int getId();
    int getPrice();
    string getName();
};