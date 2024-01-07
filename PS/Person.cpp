#include "Person.h"
#include "Administrator.h"
#include "../lib/lib.h"
#include "Staff.h"
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

int Person::setID = 0;
Person::Person(string name, string email, string password, string phoneNumber)
{
	this->name = name;
	this->email = email;
	this->password = password;
	this->phoneNumber = phoneNumber;
	this->maPS = ++setID;
}
void Person::Read(ifstream &in)
{
	in >> maPS;
	in.ignore(1);
	getline(in, name, ',');
	getline(in, email, ',');
	getline(in, password, ',');
	in >> phoneNumber;
}
void Person::Save(ofstream &out)
{
	out << "," << maPS << "," << name << "," << email << "," << password << "," << phoneNumber << endl;
}
void Person::Get() const
{
	string hidePassword = "";
	int length = password.length();
	for (int i = 0; i < length; i++)
	{
		hidePassword += "*";
	}
	cout << setw(8);
	TextColor(6);
	cout << "|" << setw(5);
	TextColor(7);
	cout << maPS;
	TextColor(6);
	cout << "|" << setw(18);
	TextColor(7);
	cout << name;
	TextColor(6);
	cout << "|" << setw(26);
	TextColor(7);
	cout << email;
	TextColor(6);
	cout << "|" << setw(16);
	TextColor(7);
	cout << hidePassword;
	TextColor(6);
	cout << "|" << setw(17);
	TextColor(7);
	cout << phoneNumber;
	TextColor(6);
}
void Person::GetDetail() const
{
	cout << setw(8);
	TextColor(6);
	cout << "|" << setw(5);
	TextColor(7);
	cout << maPS;
	TextColor(6);
	cout << "|" << setw(18);
	TextColor(7);
	cout << name;
	TextColor(6);
	cout << "|" << setw(26);
	TextColor(7);
	cout << email;
	TextColor(6);
	cout << "|" << setw(16);
	TextColor(7);
	cout << password;
	TextColor(6);
	cout << "|" << setw(17);
	TextColor(7);
	cout << phoneNumber;
	TextColor(6);
}
void Person::Update()
{
	string hidePassword = "";
	int length = password.length();
	for (int i = 0; i < length; i++)
	{
		hidePassword += "*";
	}
	TextColor(6);
	cout << setw(8);
	cout << "|" << setw(5);
	TextColor(7);
	cout << maPS;
	gotoxy(13, 8);
	TextColor(6);
	cout << "|";
	TextColor(7);
	fflush(stdin);
	getline(cin, name);
	fflush(stdin);
	gotoxy(32, 8);
	TextColor(6);
	cout << "|" << setw(26);
	TextColor(7);
	cout << email;
	TextColor(6);
	cout << "|" << setw(16);
	TextColor(7);
	cout << hidePassword;
	gotoxy(76, 8);
	TextColor(6);
	cout << "|";
	TextColor(7);
	string errPhone = "Please enter your phone number.";
	bool checkPhone = false;
	while (true)
	{
		if (checkPhone)
		{
			gotoxy(7, 4);
			TextColor(4);
			cout << errPhone;
			TextColor(7);
		}
		gotoxy(79,8);
		for (int i = 0; i < phoneNumber.length(); i++)
		{
			cout << " ";
		}
		gotoxy(79,8);
		getline(cin, phoneNumber);
		fflush(stdin);
		if (!CheckChar(phoneNumber))
		{
			break;
		}
		else
		{
			checkPhone = true;
		}
	}
	gotoxy(7, 4);
	for (int i = 0; i < errPhone.length(); i++)
	{
		cout << " ";
	}
	gotoxy(94, 8);
}
void Person::ChangePassword()
{
	string errorCurrentPassword = "Password is not correct";
	string errorPassword1 = "The password is invalid. It should have at least one uppercase letter, one lowercase letter, one number, ";
	string errorPassword2 = "and one special character. The length should be between 8 and 16 characters.";
	string errorConfirmPassword = "New password does not match the confirmed password. Please ensure both passwords are the same.";
	TextColor(2);
	cout << "\n\n\n\t\t\t\t CHANGE PASSWORD\n\n\n";
	TextColor(6);
	cout << "       ";
	cout << "+-----------------------+-----------------------+-----------------------+" << endl;
	cout << "       ";
	cout << "|    Current Password   |     New Password      |    CONFIRM PASSWORD   |" << endl;
	cout << "       ";
	cout << "+-----------------------+-----------------------+-----------------------+" << endl;
	string pass = "";
	while (true)
	{
		gotoxy(7, 9);
		cout << "|";
		TextColor(7);
		gotoxy(12, 9);
		for (int i = 0; i < pass.length(); i++)
		{
			cout << " ";
		}
		gotoxy(12, 9);
		fflush(stdin);
		getline(cin, pass);
		fflush(stdin);
		if (pass == password)
		{
			gotoxy(7, 4);
			for (int i = 0; i < errorCurrentPassword.length(); i++)
			{
				cout << " ";
			}

			gotoxy(31, 9);
			TextColor(6);
			cout << "|";
			TextColor(7);
			do
			{
				gotoxy(34, 9);
				for (int i = 0; i < password.length(); i++)
				{
					cout << " ";
				}
				gotoxy(34, 9);
				getline(cin, password);
				fflush(stdin);
				if (!is_password(password))
				{
					TextColor(4);
					gotoxy(7, 4);
					cout << errorPassword1;
					gotoxy(7, 5);
					cout << errorPassword2;
					TextColor(7);
				}
			} while (!is_password(password));
			gotoxy(7, 4);
			for (int i = 0; i < errorPassword1.length(); i++)
			{
				cout << " ";
			}
			gotoxy(7, 5);
			for (int i = 0; i < errorPassword2.length(); i++)
			{
				cout << " ";
			}

			pass = "";
			gotoxy(55, 9);
			TextColor(6);
			cout << "|";
			TextColor(7);
			do
			{
				gotoxy(58, 9);
				for (int i = 0; i < pass.length(); i++)
				{
					cout << " ";
				}
				gotoxy(58, 9);
				getline(cin, pass);
				fflush(stdin);
				gotoxy(79, 9);
				TextColor(6);
				cout << "|" << endl;
				TextColor(7);
				if (pass != password)
				{
					TextColor(4);
					gotoxy(7, 4);
					cout << errorConfirmPassword;
					TextColor(7);
				}
			} while (pass != password);
			gotoxy(7, 4);
			for (int i = 0; i < errorConfirmPassword.length(); i++)
			{
				cout << " ";
			}
			break;
		}
		else
		{
			gotoxy(7, 4);
			TextColor(4);
			cout << "Password is not correct" << endl;
			TextColor(7);
		}
	}
	gotoxy(0, 10);
	TextColor(6);
	cout << "       ";
	cout << "+-----------------------+-----------------------+-----------------------+" << endl;
	TextColor(7);
}
bool Person::Search(string name)
{
	return this->name == name;
}
void Person::SetMa(int id)
{
	setID = id;
}
int Person::getId()
{
	return maPS;
}
string Person::getName()
{
	return name;
}
string Person::getEmail()
{
	return email;
};
string Person::getPassword()
{
	return password;
};
