#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H
#include <fstream>
class Middleware
{
    int id1, id2, SL;

public:
    Middleware(int id1 = 0, int id2 = 0, int SL = 0) : id1(id1), id2(id2), SL(SL){};
    void Get();
    void Update(int id2,int SL);
    void Read(ifstream &in);
    void Save(ofstream &out);
    int getId2();
    int getId();
    int getSL();
};

#endif