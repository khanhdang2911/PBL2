#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <fstream>
using namespace std;
class Person
{
protected:
	string name;
	string email;
	string password;
	string phoneNumber;
	int maPS;
	static int setID;

public:
	Person(
		string name = "",
		string email = "",
		string password = "",
		string sdt = "");
	virtual void Get() const = 0;
	virtual void GetDetail() const = 0;
	virtual void Read(ifstream &in);
	virtual void Save(ofstream &out);
	virtual void Update();
	void ChangePassword();
	bool Search(string name);
	void SetMa(int id);
	int getId();
	string getName();
	string getEmail();
	string getPassword();
	virtual string getRole() = 0;
};

#endif