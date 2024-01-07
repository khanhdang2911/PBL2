#include "Middleware.h"
#include <iostream>
#include <fstream>
using namespace std;

void Middleware::Get(){
    cout<<id1<<"\t"<<id2<<"\t"<<SL<<endl;
};
void Middleware::Update(int id2, int SL){
    this->id2=id2;
    this->SL=SL;
};
void Middleware::Read(ifstream &in){
    in>>id1;
    in.ignore(1);
    in>>id2;
    in.ignore(1);
    in>>SL;
};
void Middleware::Save(ofstream &out){
    out<<id1<<" "<<id2<<" "<<SL<<endl;
};
int Middleware::getId2(){
    return id2;
};
int Middleware::getId(){
    return id1;
};
int Middleware::getSL(){
    return SL;
}