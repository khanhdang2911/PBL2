#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "Person.h"
#include "../lib/lib.h"
#include <fstream>
class Administrator : public Person
{
private:
	string role;

public:
	Administrator(string name = "", string email = "", string password = "", string phoneNumber = "", string role = "Administrator") : Person(name, email, password, phoneNumber), role(role){};
	virtual void Get() const
	{
		Person::Get();
		TextColor(6);
		cout << "|" << setw(17);
		TextColor(7);
		cout << role;
		TextColor(6);
		cout << "|" << endl;
		TextColor(7);
	}
	virtual void GetDetail() const
	{
		Person::GetDetail();
		TextColor(6);
		cout << "|" << setw(17);
		TextColor(7);
		cout << role;
		TextColor(6);
		cout << "|" << endl;
		TextColor(7);
	}
	virtual void Read(ifstream &in)
	{
		Person::Read(in);
		role = "Administrator";
	}
	virtual void Save(ofstream &out)
	{
		out << role;
		Person::Save(out);
	}
	virtual void Update()
	{
		Person::Update();
		cout << "|" << setw(17) << role << "|" << endl;
	}
	virtual string getRole()
	{
		return role;
	}
};
#endif