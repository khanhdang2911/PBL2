#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Materials
{
private:
    int maNL;
    string name;
    int quantity;
    string unit;
    static int setID;

public:
    Materials(string name = "", int quantity = 0, string unit = "");
    ~Materials();
    void Get();
    void Read(ifstream &in);
    void Save(ofstream &out);
    void Update();
    void UpdateSL(int);
    bool Search(string name);
    void SetMa(int id);
    int getId();
    string getName();
    string getUnit();
};