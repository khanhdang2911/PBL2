#include <fstream>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>

#include "Dashboard.h"
#include "../PS/Administrator.h"
#include "../PS/Staff.h"
#include "../PS/Person.h"
#include "../PS/Person.cpp"
#include "../Bill/Bill.h"
#include "../Bill/Bill.cpp"
#include "../Bill/InBill.h"
#include "../Bill/OutBill.h"
#include "../Materials/Materials.h"
#include "../Materials/Materials.cpp"
#include "../Product/Product.h"
#include "../Product/Product.cpp"
#include "../Middleware/Middleware.cpp"
#include "../Middleware/Middleware.h"
#include "../lib/List.cpp"
#include "../lib/lib.h"
using namespace std;

Dashboard::Dashboard()
{
    idUser = 0;
    role = "";
    ReadPS();
    ReadInBill();
    ReadOutBill();
    ReadNL();
    ReadSP();
    Read("BHSP");
    Read("MHNL");
    Read("NLSP");
}
Dashboard::~Dashboard()
{
    role = "";
    idUser = 0;
}

void Dashboard::Profit()
{
    system("cls");
    gotoxy(40, 10);
    TextColor(6);
    cout << "+--------------+------------------+";
    gotoxy(40, 11);
    cout << "|  Month";
    string str = "";
    int month = 0, year = 0;
    while (true)
    {
        gotoxy(56, 11);
        for (int i = 0; i < str.length(); i++)
        {
            cout << " ";
        }
        TextColor(6);
        gotoxy(55, 11);
        cout << "|";
        TextColor(7);
        fflush(stdin);
        getline(cin, str);
        month = atof(str.substr(0, str.length()).c_str());
        if ((month >= 1) && (month <= 12))
        {
            break;
        }
    }
    TextColor(6);
    gotoxy(74, 11);
    cout << "|";
    gotoxy(40, 12);
    cout << "+--------------+------------------+";
    gotoxy(40, 13);
    cout << "|  Year";
    while (true)
    {
        gotoxy(56, 13);
        for (int i = 0; i < str.length(); i++)
        {
            cout << " ";
        }
        TextColor(6);
        gotoxy(55, 13);
        cout << "|";
        TextColor(7);
        fflush(stdin);
        getline(cin, str);
        year = atof(str.substr(0, str.length()).c_str());
        if (year / 1000 < 10 && year / 1000 > 1 && year != 0)
        {
            break;
        }
    }
    loadingAnimation();
    TextColor(6);
    gotoxy(74, 13);
    cout << "|";
    gotoxy(40, 14);
    cout << "+--------------+------------------+";
    TextColor(7);
    system("cls");
    int sale = exports.search(year, month, true);
    int buy = imports.search(year, month, true);

    gotoxy(40, 7);
    TextColor(6);
    cout << "+--------------+------------------+";
    gotoxy(40, 8);
    cout << "|  Month";
    TextColor(6);
    gotoxy(55, 8);
    cout << "|";
    TextColor(7);
    cout << month;
    TextColor(6);
    gotoxy(74, 8);
    cout << "|";
    gotoxy(40, 9);

    cout << "+--------------+------------------+";
    gotoxy(40, 10);
    cout << "|  Year";
    TextColor(6);
    gotoxy(55, 10);
    cout << "|";
    TextColor(7);
    cout << year;
    TextColor(6);
    gotoxy(74, 10);
    cout << "|";
    gotoxy(40, 11);

    cout << "+--------------+------------------+";
    gotoxy(40, 12);
    cout << "|  Import";
    TextColor(6);
    gotoxy(55, 12);
    cout << "|";
    TextColor(7);
    cout << Currency(buy);
    TextColor(6);
    gotoxy(74, 12);
    cout << "|";
    gotoxy(40, 13);
    cout << "+--------------+------------------+";
    gotoxy(40, 14);
    cout << "|  Export";
    TextColor(6);
    gotoxy(55, 14);
    cout << "|";
    TextColor(7);
    cout << Currency(sale);
    TextColor(6);
    gotoxy(74, 14);
    cout << "|";
    gotoxy(40, 15);

    cout << "+--------------+------------------+";
    gotoxy(40, 16);
    cout << "|  Profit";
    TextColor(6);
    gotoxy(55, 16);
    cout << "|";
    TextColor(7);
    int price = sale - buy;
    cout << Currency(price);
    TextColor(6);
    gotoxy(74, 16);
    cout << "|";
    gotoxy(40, 17);

    cout << "+--------------+------------------+" << endl;
    TextColor(7);
}
string Dashboard::getRole()
{
    return role;
}
int Dashboard::ValidatePS(string email, string password)
{
    int size = persons.getSize();
    for (int i = 0; i < size; i++)
    {
        if (persons[i]->getEmail() == email)
        {
            if (persons[i]->getPassword() == password)
            {
                role = persons[i]->getRole();
                idUser = persons[i]->getId();
                return 1;
            }
            return 0;
        }
    }
    return -1;
}

bool Dashboard::ValidateEmail(string email)
{
    if (!is_email(email))
    {
        return true;
    }
    return persons.ExistEmail(email);
}
/*----------------------------Person Construction---------------------------------*/
void Dashboard::CreatePS(int n)
{
    if (role == "Administrator")
    {
        int root = 9;
        int stt = 1;
        string fullName;
        string email = "";
        string password = "";
        string sdt;
        string role;
        string errorEmail = "Email already exists or is in wrong format. Please use another email!";
        string errorPassword1 = "The password is invalid. It should have at least one uppercase letter, one lowercase letter, one number, ";
        string errorPassword2 = "and one special character. The length should be between 8 and 16 characters.";
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t ADD NEW HUMAN\n\n\n";
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        cout << "       ";
        cout << "| STT |    Full Name     |          Email           |   Password     |   Phone Number  |      Role       |" << endl;
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(8) << "|";
            TextColor(7);
            cout << stt;
            fflush(stdin);
            gotoxy(13, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            getline(cin, fullName);
            fflush(stdin);
            gotoxy(32, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            do
            {
                gotoxy(33, root);
                for (int i = 0; i < email.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(33, root);
                getline(cin, email);
                fflush(stdin);
                if (Dashboard::ValidateEmail(email))
                {
                    gotoxy(7, 5);
                    TextColor(4);
                    cout << errorEmail;
                    TextColor(7);
                }
            } while (Dashboard::ValidateEmail(email));
            gotoxy(7, 5);
            for (int i = 0; i < errorEmail.length(); i++)
            {
                cout << " ";
            }

            gotoxy(59, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            do
            {
                gotoxy(60, root);
                for (int i = 0; i < password.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(60, root);
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
            gotoxy(76, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            string errPhone = "Please enter your phone number.";
            bool checkPhone = false;
            while (true)
            {
                if (checkPhone)
                {
                    gotoxy(7, 5);
                    TextColor(4);
                    cout << errPhone;
                    TextColor(7);
                }
                gotoxy(79, root);
                for (int i = 0; i < sdt.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(79, root);
                getline(cin, sdt);
                fflush(stdin);
                if (!CheckChar(sdt))
                {
                    break;
                }
                else
                {
                    checkPhone = true;
                }
            }
            gotoxy(7, 5);
            for (int i = 0; i < errPhone.length(); i++)
            {
                cout << " ";
            }
            gotoxy(94, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            getline(cin, role);
            fflush(stdin);
            gotoxy(112, root);
            TextColor(6);
            cout << "|" << endl;
            root = root + 2;
            stt++;
            cout << "       ";
            cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
            TextColor(7);
            if (role == "1" || role == "admin" || role == "administrator" || role == "Administrator")
            {
                persons.create(new Administrator(fullName, email, password, sdt));
            }
            else if (role == "0" || role == "staff" || role == "Staff")
            {
                persons.create(new Staff(fullName, email, password, sdt));
            }
            else
            {
                TextColor(4);
                cout << "\n\n\n        Invalid role" << endl;
                TextColor(7);
                return;
            }
        }
        loadingAnimation();
        system("cls");
        GetPS();
        TextColor(2);
        cout << "\n\n\n        ADD NEW HUMAN SUCCESSFULLY\n";
        TextColor(7);
        SavePS();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::ChangePassword()
{
    if (role == "Administrator")
    {
        GetPS();
        if (persons.isEmpty())
            return;
        string idString;
        cout << "\n\n\n        Enter the Id which you want to change your password: ";
        fflush(stdin);
        getline(cin, idString);

        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        if (!persons.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID USER NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        system("cls");
        if (id == idUser)
        {
            persons.ChangePassword(idUser);
            loadingAnimation();
            TextColor(2);
            cout << "\n\n\n        CHANGE PASSWORD SUCCESSFULLY\n";
            TextColor(7);
        }
        else
        {
            bool check = persons[persons.getNumberInList(id)]->getRole() != "Administrator";
            if (check)
            {
                if (persons.ChangePassword(id))
                {
                    loadingAnimation();
                    TextColor(2);
                    cout << "\n\n\n        CHANGE PASSWORD SUCCESSFULLY\n";
                    TextColor(7);
                }
            }
            else
            {
                TextColor(4);
                cout << "\n\n\n        Cannot change password of Administrator!\n\n";
                TextColor(7);
                return;
            }
        }
    }
    else if (role == "Staff")
    {
        persons.ChangePassword(idUser);
        loadingAnimation();
        TextColor(2);
        cout << "\n\n\n        CHANGE PASSWORD SUCCESSFULLY\n";
        TextColor(7);
    }

    SavePS();
};
void Dashboard::GetPS()
{
    loadingAnimation();
    if (role == "Administrator")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST HUMAN\n";
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        cout << "       ";
        cout << "|  ID |    Full Name     |          Email           |   Password     |   Phone Number  |      Role       |" << endl;
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        TextColor(7);
        persons.get();
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        TextColor(7);
    }
    else if (role == "Staff")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST HUMAN\n";
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        cout << "       ";
        cout << "|  ID |    Full Name     |          Email           |   Password     |   Phone Number  |      Role       |" << endl;
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        TextColor(7);
        persons.get(idUser);
        TextColor(6);
        cout << "       ";
        TextColor(6);
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::GetPSDetail()
{
    if (role == "Administrator")
    {
        GetPS();
        string idString;
        cout << "\n\n\n        Enter the Id which you want to get detail: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        system("cls");
        loadingAnimation();
        if (id == idUser)
        {
            TextColor(2);
            cout << "\n\n\n\t\t\t\t\t\t\t PROFILE\n";
            TextColor(6);
            cout << "       ";
            cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
            cout << "       ";
            cout << "|  ID |    Full Name     |          Email           |   Password     |   Phone Number  |      Role       |" << endl;
            cout << "       ";
            cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
            TextColor(7);
            persons.get(id, false);
            TextColor(6);
            cout << "       ";
            cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
            TextColor(7);
        }
        else
        {
            TextColor(2);
            cout << "\n\n\n\t\t\t\t\t\t\t PROFILE\n";
            TextColor(6);
            cout << "       ";
            cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
            cout << "       ";
            cout << "|  ID |    Full Name     |          Email           |   Password     |   Phone Number  |      Role       |" << endl;
            cout << "       ";
            cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
            if (!persons.CheckId(id))
            {
                TextColor(4);
                cout << "\n\n\n        User not found!!!\n\n";
                TextColor(7);
                return;
            }
            TextColor(7);
            persons.get(id);
            TextColor(6);
            cout << "       ";
            cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
            TextColor(7);
        }
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::DeletePS()
{
    if (role == "Administrator")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t CHOOSE OPTION DELETE\n";
        TextColor(7);
        gotoxy(35, 4);
        TextColor(6);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "1.Delete by ID Human";
        gotoxy(85, 5);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 6);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "2.Delete by Full Name";
        gotoxy(85, 7);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 8);
        cout << "+-------------------------------------------------+" << endl;
        gotoxy(35, 10);
        TextColor(2);
        cout << "Choose a option: ";
        int opt;
        cin >> opt;
        TextColor(7);
        fflush(stdin);
        system("cls");
        loadingAnimation();
        GetPS();
        if (persons.isEmpty())
        {
            return;
        }
        if (opt == 1)
        {
            string idString;
            cout << "\n\n\n        Enter the Id which you want to delete: ";
            fflush(stdin);
            getline(cin, idString);
            int id;
            if (CheckChar(idString))
            {
                id = 0;
            }
            else
            {
                id = stoi(idString);
            }
            if (!persons.CheckId(id))
            {
                TextColor(4);
                cout << "\n\n\n        ID USER NOT FOUND!!\n\n";
                TextColor(7);
                return;
            }
            persons.remove(id);
        }
        else if (opt == 2)
        {
            string fullName;
            cout << "\n\n\n        Enter the FullName which you want to delete:";
            getline(cin, fullName);
            fflush(stdin);
            if (!persons.CheckName(fullName))
            {
                TextColor(4);
                cout << "\n\n\n        FULLNAME USER NOT FOUND!!\n\n";
                TextColor(7);
                return;
            }
            persons.remove(fullName);
        }
        else
        {
            TextColor(4);
            cout << "\nERROR";
            TextColor(7);
            return;
        }
        system("cls");
        loadingAnimation();
        GetPS();
        TextColor(2);
        cout << "\n\n\n        DELETE HUMAN SUCCESSFULLY\n";
        TextColor(7);
        SavePS();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::UpdatePS()
{
    if (role == "Administrator")
    {
        loadingAnimation();
        GetPS();
        if (persons.isEmpty())
            return;
        string idString;
        cout << "\n\n\n        Enter the Id which you want to update: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        if (!persons.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID USER NOT FOUND.!!!\n\n";
            TextColor(7);
            return;
        }
        system("cls");
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t UPDATE PROFILE\n\n";
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        cout << "       ";
        cout << "| ID  |    Full Name     |          Email           |   Password     |   Phone Number  |      Role       |" << endl;
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        TextColor(7);
        bool check = persons[persons.getNumberInList(id)]->getRole() != "Administrator";

        if (id != idUser)
        {
            if (check)
            {
                persons.update(id);
            }
        }
        else
        {
            persons.update(id);
        }
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        SavePS();
        system("cls");
        loadingAnimation();
        GetPS();
        if (check || id == idUser)
        {
            TextColor(2);
            cout << "\n\n\n        UPDATE PROFILE SUCCESSFULLY\n";
            TextColor(7);
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        Cannot update PROFILE of Administrator!\n\n";
            TextColor(7);
        }
    }
    else if (role == "Staff")
    {
        system("cls");
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t UPDATE PROFILE\n";
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        cout << "       ";
        cout << "| ID  |    Full Name     |          Email           |   Password     |   Phone Number  |      Role       |" << endl;
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        TextColor(7);
        persons.update(idUser);
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        SavePS();
        system("cls");
        loadingAnimation();
        GetPS();
        TextColor(2);
        cout << "\n\n\n        UPDATE PROFILE SUCCESSFULLY\n";
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::SearchPS()
{
    if (role == "Administrator")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t CHOOSE OPTION SEARCH\n";
        TextColor(7);
        gotoxy(35, 4);
        TextColor(6);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "1.Search by ID Human";
        gotoxy(85, 5);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 6);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "2.Search by Full Name";
        gotoxy(85, 7);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 8);
        cout << "+-------------------------------------------------+" << endl;
        TextColor(2);
        gotoxy(35, 10);
        cout << "Choose a option: ";
        TextColor(7);
        int opt;
        cin >> opt;
        fflush(stdin);
        string name;
        int id;
        system("cls");
        if (opt == 1)
        {
            GetPS();
            if (persons.isEmpty())
                return;
            string idString;
            cout << "\n\n\n        Enter the Id which you want to search: ";
            fflush(stdin);
            getline(cin, idString);
            if (CheckChar(idString))
            {
                id = 0;
            }
            else
            {
                id = stoi(idString);
            }
        }
        else if (opt == 2)
        {
            GetPS();
            if (persons.isEmpty())
                return;
            cout << "\n\n\n        Enter the FullName which you want to get:";
            getline(cin, name);
            fflush(stdin);
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        ERROR";
            TextColor(7);
            return;
        }
        system("cls");
        loadingAnimation();
        LinkedList<Person *> searchList = opt == 1 ? persons.search(id) : persons.search(name);
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t LIST HUMAN\n";
        TextColor(6);
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        cout << "       ";
        cout << "| ID  |    Full Name     |          Email           |   Password     |   Phone Number  |      Role       |" << endl;
        cout << "       ";
        cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
        TextColor(7);
        searchList.get();
        if (searchList.getSize())
        {
            TextColor(6);
            cout << "       ";
            cout << "+-----+------------------+--------------------------+----------------+-----------------+-----------------+" << endl;
            TextColor(7);
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        USER NOT FOUND!!\n\n";
            TextColor(7);
        }
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::ReadPS()
{
    ifstream in;
    in.open("Database\\Person.txt", ios_base::in);
    if (!in.is_open())
    {
        TextColor(4);
        cout << "Could not find database" << endl;
        TextColor(7);
        return;
    }
    string roleD;
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        in.ignore(1);
        getline(in, roleD, ',');
        if (roleD == "Administrator")
        {
            persons.create(new Administrator());
            persons[i]->Read(in);
        }
        else if (roleD == "Staff")
        {
            persons.create(new Staff());
            persons[i]->Read(in);
        }
    }
    in.close();
    persons.setId();
}
void Dashboard::SavePS()
{
    if (role == "Administrator" || role == "Staff")
    {
        ofstream out;
        out.open("Database\\Person.txt", ios_base::out);
        if (!out.is_open())
        {
            TextColor(4);
            cout << "Could not find database" << endl;
            TextColor(7);
            return;
        }
        persons.save(out);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::SortPS()
{
    if (role == "Administrator")
    {
        persons.sortByName();
        GetPS();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
// // /*----------------------------Person Construction---------------------------------*/

// // /*------------------------------OutBill Construction-------------------------------*/

void Dashboard::ReadOutBill()
{
    ifstream in;
    in.open("Database\\OutBill.txt", ios_base::in);
    if (!in.is_open())
    {
        TextColor(4);
        cout << "Could not find database" << endl;
        TextColor(7);
        return;
    }
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        exports.create(new OutBill());
        exports[i]->Read(in);
    }
    in.close();
    exports.setId();
}
void Dashboard::SaveOutBill()
{
    if (role == "Administrator" || role == "Staff")
    {
        ofstream out;
        out.open("Database\\OutBill.txt", ios_base::out);
        if (!out.is_open())
        {
            TextColor(4);
            cout << "Could not find database" << endl;
            TextColor(7);
            return;
        }
        exports.save(out);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::GetOutBill()
{
    if (role == "Administrator" || role == "Staff")
    {
        loadingAnimation();
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST EXPORTS\n";
        TextColor(6);
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        cout << "            ";
        cout << "|  ID |  Buyer ID   |       Type        |       Date        |     Total price     |   Payment type   |" << endl;
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        if (exports.isEmpty())
        {
            cout << "\n\n\n        CURRENTLY THE EXPORTS LIST IS EMPTY.\n";
        }
        else
        {
            exports.get();
            cout << "            ";
            TextColor(6);
            cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
            TextColor(7);
        }
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::GetDetailOutBill()
{
    loadingAnimation();
    if (role == "Administrator" || role == "Staff")
    {
        GetOutBill();
        string idString;
        cout << "\n\n\n        Enter the Id which you want to get details: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        fflush(stdin);
        system("cls");
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST EXPORTS\n";
        TextColor(6);
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        cout << "            ";
        cout << "|  ID |  Buyer ID   |       Type        |       Date        |     Total price     |   Payment type   |" << endl;
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        if (exports.isEmpty())
        {
            cout << "\n\n\n        CURRENTLY THE EXPORTS LIST IS EMPTY.\n";
        }
        if (SP.getNumberInList(id) == -1)
        {
            TextColor(4);
            cout << "\n\n\n        EXPORT BILL NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        exports[exports.getNumberInList(id)]->get();
        cout << "            ";
        TextColor(6);
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        LinkedList<Middleware *> products = BHSP.search(id);
        TextColor(2);
        cout << "\n\n\n\n\t\t\t\t LIST PRODUCTS\n\n";
        TextColor(6);
        cout << "                 ";
        cout << "+------------------------------+--------------------+" << endl;
        cout << "                 ";
        cout << "|          Products            |      Quantity      |" << endl;
        cout << "                 ";
        cout << "+------------------------------+--------------------+ " << endl;
        if (products.isEmpty())
        {
            TextColor(4);
            cout << "\n\n                 CURRENTLY EXPORT BILL HAVE NOT PRODUCT";
            TextColor(7);
            return;
        }
        int root = 18;
        for (int i = 0; i < products.getSize(); i++)
        {
            int orderId = products[i]->getId2();
            if (!SP.CheckId(orderId))
            {
                TextColor(6);
                gotoxy(17, root);
                cout << "|";
                TextColor(7);
                cout << "San pham id " << orderId << " da bi xoa";
                gotoxy(48, root);
                TextColor(6);
                cout << "|";
                TextColor(7);
                gotoxy(69, root);
                TextColor(6);
                cout << "|" << endl;
                root = root + 1;
                TextColor(7);
                continue;
            }
            TextColor(6);
            gotoxy(17, root);
            cout << "|";
            TextColor(7);
            cout << SP[SP.getNumberInList(orderId)]->getName();
            gotoxy(48, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            cout << products[i]->getSL();
            gotoxy(69, root);
            TextColor(6);
            cout << "|" << endl;
            root = root + 1;
        }
        cout << "                 ";
        cout << "+------------------------------+--------------------+ " << endl;
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::DeleteOutBill()
{
    if (role == "Administrator" || role == "Staff")
    {
        GetOutBill();
        if (exports.isEmpty())
            return;
        string idString;
        cout << "\n\n\n        Enter the Id which you want to delete: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        if (!exports.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID EXPORT NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        LinkedList<Middleware *> products = BHSP.search(id);
        for (int i = 0; i < products.getSize(); i++)
        {
            if (i < products.getSize())
            {
                LinkedList<Middleware *> materials = NLSP.search(products[i]->getId2());
                for (int j = 0; j < materials.getSize(); j++)
                {
                    int sttNL = NL.getNumberInList(materials[j]->getId2());
                    NL[sttNL]->updateSL(materials[j]->getSL(), products[i]->getSL());
                }
            }
        }
        exports.remove(id);
        Delete(id, "BHSP");
        SaveOutBill();
        SaveNL();
        system("cls");
        loadingAnimation();
        GetOutBill();
        TextColor(2);
        cout << "\n\n\n        DELETE EXPORT SUCCESSFULLY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::CreateOutBill(int n)
{
    if (role == "Administrator" || role == "Staff")
    {
        time_t current_time = time(NULL);
        tm *local_time = localtime(&current_time);
        int current_day = local_time->tm_mday;
        int current_month = local_time->tm_mon + 1;
        int current_year = local_time->tm_year + 1900;

        int maPS = idUser;
        int day, month, price = 0, year;
        string PaymentType;
        for (int i = 0; i < n; i++)
        {
            system("cls");
            TextColor(2);
            cout << "\n\n\n\t\t\t\t\t ADD NEW EXPORT\n\n";
            TextColor(6);
            cout << "                 ";
            cout << "+-----+-------------+-------------------+-------------------+" << endl;
            cout << "                 ";
            cout << "| STT |  Seller ID  |   Payment type    |       Date        |" << endl;
            cout << "                 ";
            cout << "+-----+-------------+-------------------+-------------------+" << endl;
            cout << setw(18) << "|";
            TextColor(7);
            cout << i + 1;
            fflush(stdin);
            gotoxy(23, 8);
            TextColor(6);
            cout << "|";
            TextColor(7);
            gotoxy(25, 8);
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
                for (int i = 0; i < PaymentType.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(40, 8);
                getline(cin, PaymentType);
                if (PaymentType == "cash" || PaymentType == "Cash" || PaymentType == "Banking" || PaymentType == "banking" || PaymentType == "0" || PaymentType == "1")
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
            TextColor(6);
            cout << "|";
            TextColor(7);
            cout << current_day << "/" << current_month << "/" << current_year;
            gotoxy(77, 8);
            TextColor(6);
            cout << "|" << endl;

            cout << "                 ";
            cout << "+-----+-------------+-------------------+-------------------+" << endl;
            TextColor(7);

            exports.create(new OutBill(current_year, current_month, current_day, price, maPS, PaymentType));

            int idHD = exports.getIdTail(), dem;
            cout << "\n\n\n        Quantity of product: ";
            string demSL;
            string errSL = "Invalid quantity. Try again!";
            check = false;
            while (true)
            {
                if (check)
                {
                    gotoxy(23, 12);
                    TextColor(4);
                    cout << errSL;
                    TextColor(7);
                }
                gotoxy(30, 13);
                for (int i = 0; i < demSL.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(30, 13);
                getline(cin, demSL);
                fflush(stdin);
                if (!CheckChar(demSL))
                {
                    dem = atof(demSL.substr(0, demSL.length()).c_str());
                    if (dem > 0)
                    {
                        break;
                    }
                }
                check = true;
            }
            gotoxy(23, 12);
            for (int i = 0; i < errSL.length(); i++)
            {
                cout << " ";
            }
            TextColor(2);
            cout << "\n\n\n\n\t\t\t\t LIST PRODUCTS\n\n";
            TextColor(6);
            cout << "                 ";
            cout << "+------------------------------+--------------------+" << endl;
            cout << "                 ";
            cout << "|          Products            |      Quantity      |" << endl;
            cout << "                 ";
            cout << "+------------------------------+--------------------+ " << endl;
            int SL, root = 21;
            string maSP = "", quantity = "";
            int arrID[50] = {0};
            int n = 0;
            string errIdSP = "This product already exists. Please add another products!";
            for (int i = 0; i < dem; i++)
            {
                TextColor(6);
                gotoxy(17, root);
                cout << "|";
                TextColor(7);

                string err = "Product not found.Please try again.";
                int ma;
                bool check = false;
                while (true)
                {
                    gotoxy(20, root);
                    getline(cin, maSP);
                    fflush(stdin);
                    if (CheckChar(maSP))
                    {
                        // name
                        ma = SP.getIdByName(maSP);
                        if (!SP.CheckId(ma))
                        {
                            check = true;
                            if (check)
                            {
                                gotoxy(17, 17);
                                for (int i = 0; i < errIdSP.length(); i++)
                                {
                                    cout << " ";
                                }
                                gotoxy(17, 17);
                                TextColor(4);
                                cout << err;
                                TextColor(7);
                            }
                        }
                        else
                        {
                            if (checkIdInArray(arrID, n, ma))
                            {
                                arrID[n] = ma;
                                n++;
                                break;
                            }
                            else
                            {
                                gotoxy(17, 17);
                                TextColor(4);
                                cout << errIdSP;
                                TextColor(7);
                            }
                        }
                    }
                    else
                    {
                        // ID
                        ma = atof(maSP.substr(0, maSP.length()).c_str());
                        if (!SP.CheckId(ma))
                        {
                            check = true;
                            if (check)
                            {
                                gotoxy(17, 17);
                                for (int i = 0; i < errIdSP.length(); i++)
                                {
                                    cout << " ";
                                }
                                gotoxy(17, 17);
                                TextColor(4);
                                cout << err;
                                TextColor(7);
                            }
                        }
                        else
                        {
                            if (checkIdInArray(arrID, n, ma))
                            {
                                arrID[n] = ma;
                                n++;
                                break;
                            }
                            else
                            {
                                gotoxy(17, 17);
                                TextColor(4);
                                cout << errIdSP;
                                TextColor(7);
                            }
                        }
                    }
                    gotoxy(20, root);
                    for (int i = 0; i < maSP.length(); i++)
                    {
                        cout << " ";
                    }
                }
                gotoxy(17, 17);
                for (int i = 0; i < err.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(17, 17);
                for (int i = 0; i < errIdSP.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(48, root);
                TextColor(6);
                cout << "|";
                TextColor(7);

                check = false;
                while (true)
                {
                    if (check)
                    {
                        gotoxy(17, 17);
                        TextColor(4);
                        cout << errSL;
                        TextColor(7);
                    }
                    gotoxy(50, root);
                    for (int i = 0; i < quantity.length(); i++)
                    {
                        cout << " ";
                    }
                    gotoxy(50, root);
                    getline(cin, quantity);
                    fflush(stdin);
                    if (!CheckChar(quantity))
                    {
                        SL = atof(quantity.substr(0, quantity.length()).c_str());
                        if (SL > 0)
                        {
                            break;
                        }
                    }
                    check = true;
                }
                gotoxy(17, 17);
                for (int i = 0; i < errSL.length(); i++)
                {
                    cout << " ";
                }

                gotoxy(69, root);
                TextColor(6);
                cout << "|" << endl;
                cout << "                 ";
                cout << "+------------------------------+--------------------+ " << endl;
                TextColor(7);
                root = root + 2;
                price += SP.getPrice(ma) * SL;

                Create(idHD, ma, SL, "BHSP");
                LinkedList<Middleware *> materials = NLSP.search(ma);
                for (int i = 0; i < materials.getSize(); i++)
                {
                    NL[NL.getNumberInList(materials[i]->getId2())]->updateSL(materials[i]->getSL(), -SL);
                }
            }
            if (dem <= 0)
            {
                cout << "                 ";
                cout << "+------------------------------+--------------------+ " << endl;
            }
            exports[exports.getSize() - 1]->setPrice(price);
        }
        loadingAnimation();
        TextColor(2);
        cout << "\n\n\n        CREATE NEW EXPORT SUCCESSFULLY\n";
        TextColor(7);
        SaveNL();
        SaveOutBill();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::UpdateOutBill()

{
    if (role == "Administrator" || role == "Staff")
    {
        GetOutBill();
        if (exports.isEmpty())
            return;
        string idString;
        cout << "\n\n\n        Enter the Id which you want to update: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        if (!exports.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID EXPORT NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        system("cls");
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t UPDATE EXPORT\n\n";
        TextColor(6);
        cout << "                 ";
        cout << "+-----+-------------+-------------------+-------------------+" << endl;
        cout << "                 ";
        cout << "| ID  |  Seller ID  |   Payment type    |       Date        |" << endl;
        cout << "                 ";
        cout << "+-----+-------------+-------------------+-------------------+" << endl;
        TextColor(7);
        exports.update(id);
        TextColor(6);
        cout << "                 ";
        cout << "+-----+-------------+-------------------+-------------------+" << endl;
        TextColor(7);
        // update quantity of materials when update a exports
        LinkedList<Middleware *> products = BHSP.search(id);
        for (int i = 0; i < products.getSize(); i++)
        {
            if (i < products.getSize())
            {
                LinkedList<Middleware *> materials = NLSP.search(products[i]->getId2());
                for (int j = 0; j < materials.getSize(); j++)
                {
                    int sttNL = NL.getNumberInList(materials[j]->getId2());
                    NL[sttNL]->updateSL(materials[j]->getSL(), products[i]->getSL());
                }
            }
        }
        BHSP.remove(id);
        int dem, price = 0;
        cout << "\n\n\n        Quantity of product: ";
        string errSL = "Invalid quantity. Try again!";
        bool check = false;
        string demSL = "";
        while (true)
        {
            if (check)
            {
                gotoxy(23, 12);
                TextColor(4);
                cout << errSL;
                TextColor(7);
            }
            gotoxy(30, 13);
            for (int i = 0; i < demSL.length(); i++)
            {
                cout << " ";
            }
            gotoxy(30, 13);
            getline(cin, demSL);
            fflush(stdin);
            if (!CheckChar(demSL))
            {
                dem = atof(demSL.substr(0, demSL.length()).c_str());
                if (dem > 0)
                {
                    break;
                }
            }
            check = true;
        }
        gotoxy(23, 12);
        for (int i = 0; i < errSL.length(); i++)
        {
            cout << " ";
        }
        TextColor(2);
        cout << "\n\n\n\n\t\t\t\t LIST PRODUCTS\n\n";
        TextColor(6);
        cout << "                 ";
        cout << "+------------------------------+--------------------+" << endl;
        cout << "                 ";
        cout << "|          Products            |      Quantity      |" << endl;
        cout << "                 ";
        cout << "+------------------------------+--------------------+ " << endl;
        int SL, root = 21;
        string maSP = "", quantity = "";
        int arrID[50] = {0};
        int n = 0;
        string errIdSP = "This product already exists. Please add another products!";
        for (int i = 0; i < dem; i++)
        {
            TextColor(6);
            gotoxy(17, root);
            cout << "|";
            TextColor(7);
            string err = "Product not found.Please try again.";
            int ma;
            bool check = false;
            while (true)
            {
                gotoxy(20, root);
                getline(cin, maSP);
                fflush(stdin);
                if (CheckChar(maSP))
                {
                    // name
                    ma = SP.getIdByName(maSP);
                    if (!SP.CheckId(ma))
                    {
                        check = true;
                        if (check)
                        {
                            gotoxy(17, 17);
                            for (int i = 0; i < errIdSP.length(); i++)
                            {
                                cout << " ";
                            }
                            gotoxy(17, 17);
                            TextColor(4);
                            cout << err;
                            TextColor(7);
                        }
                    }
                    else
                    {
                        if (checkIdInArray(arrID, n, ma))
                        {
                            arrID[n] = ma;
                            n++;
                            break;
                        }
                        else
                        {
                            gotoxy(17, 17);
                            TextColor(4);
                            cout << errIdSP;
                            TextColor(7);
                        }
                    }
                }
                else
                {
                    // ID
                    ma = atof(maSP.substr(0, maSP.length()).c_str());
                    if (!SP.CheckId(ma))
                    {
                        check = true;
                        if (check)
                        {
                            gotoxy(17, 17);
                            for (int i = 0; i < errIdSP.length(); i++)
                            {
                                cout << " ";
                            }
                            gotoxy(17, 17);
                            TextColor(4);
                            cout << err;
                            TextColor(7);
                        }
                    }
                    else
                    {
                        if (checkIdInArray(arrID, n, ma))
                        {
                            arrID[n] = ma;
                            n++;
                            break;
                        }
                        else
                        {
                            gotoxy(17, 17);
                            TextColor(4);
                            cout << errIdSP;
                            TextColor(7);
                        }
                    }
                }
                gotoxy(20, root);
                for (int i = 0; i < maSP.length(); i++)
                {
                    cout << " ";
                }
            }
            gotoxy(17, 17);
            for (int i = 0; i < err.length(); i++)
            {
                cout << " ";
            }
            gotoxy(17, 17);
            for (int i = 0; i < errIdSP.length(); i++)
            {
                cout << " ";
            }
            gotoxy(48, root);
            TextColor(6);
            cout << "|";
            TextColor(7);

            check = false;
            while (true)
            {
                if (check)
                {
                    gotoxy(17, 17);
                    TextColor(4);
                    cout << errSL;
                    TextColor(7);
                }
                gotoxy(50, root);
                for (int i = 0; i < quantity.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(50, root);
                getline(cin, quantity);
                fflush(stdin);
                if (!CheckChar(quantity))
                {
                    SL = atof(quantity.substr(0, quantity.length()).c_str());
                    if (SL > 0)
                    {
                        break;
                    }
                }
                check = true;
            }
            gotoxy(17, 17);
            for (int i = 0; i < errSL.length(); i++)
            {
                cout << " ";
            }

            gotoxy(69, root);
            TextColor(6);
            cout << "|" << endl;
            cout << "                 ";
            cout << "+------------------------------+--------------------+ " << endl;
            TextColor(7);
            root = root + 2;
            price += SP.getPrice(ma) * SL;

            Create(id, ma, SL, "BHSP");
            LinkedList<Middleware *> materials = NLSP.search(ma);
            for (int i = 0; i < materials.getSize(); i++)
            {
                NL[NL.getNumberInList(materials[i]->getId2())]->updateSL(materials[i]->getSL(), -SL);
            }
        }
        if (dem <= 0)
        {
            cout << "                 ";
            cout << "+------------------------------+--------------------+ " << endl;
        }
        exports[exports.getNumberInList(id)]->setPrice(price);
        SaveOutBill();
        Save("BHSP");
        SaveNL();
        system("cls");
        loadingAnimation();
        GetOutBill();
        TextColor(2);
        cout << "\n\n\n        UPDATE EXPORT SUCCESSFULLY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::SortOutBill()
{
    if (role == "Administrator" || role == "Staff")
    {
        exports.sortByDate();
        loadingAnimation();
        GetOutBill();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::PrintOutBill()
{
    if (role == "Administrator" || role == "Staff")
    {
        system("cls");
        loadingAnimation();
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t HI COFFEE\n";
        TextColor(6);
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        cout << "            ";
        cout << "|  ID |  Buyer ID   |       Type        |       Date        |     Total price     |   Payment type   |" << endl;
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        if (exports.isEmpty())
        {
            TextColor(4);
            cout << "\n\n\n        Cannot print bill!!\n\n";
            TextColor(7);
            return;
        }
        exports.getLast();
        cout << "            ";
        TextColor(6);
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(2);
        cout << "\n\t\t\t\t\t\t\t PRODUCTS\n";
        TextColor(6);
        cout << "                                     ";
        cout << "+-------------------------------+-------------------+" << endl;
        cout << "                                     ";
        cout << "|         Name Product          |     Quantity      |" << endl;
        cout << "                                     ";
        cout << "+-------------------------------+-------------------+" << endl;
        int root = 14;
        LinkedList<Middleware *> products = BHSP.search(exports.getIdTail());
        for (int i = 0; i < products.getSize(); i++)
        {
            TextColor(6);
            cout << setw(38) << "|";
            TextColor(7);
            cout << SP[SP.getNumberInList(products[i]->getId2())]->getName();
            gotoxy(69, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            gotoxy(79, root);
            cout << products[i]->getSL();
            gotoxy(89, root);
            TextColor(6);
            cout << "|" << endl;
            cout << "                                     ";
            cout << "+-------------------------------+-------------------+" << endl;
            TextColor(7);
            root = root + 2;
        }
        TextColor(7);
        if (products.isEmpty())
        {
            cout << "\n\n\n        CURRENTLY PRODUCT HAS NOT MATERIALS!!\n\n";
        }
        TextColor(2);
        cout << "\n                                                      ";
        cout << "HAVE A GOOD DAY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::SearchOutBill()
{
    if (role == "Administrator" || role == "Staff")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t CHOOSE OPTION SEARCH\n";
        TextColor(6);
        gotoxy(35, 4);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "1.Search by ID Exports";
        gotoxy(85, 5);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 6);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "2.Search by Date";
        gotoxy(85, 7);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 8);
        cout << "+-------------------------------------------------+" << endl;
        TextColor(7);
        gotoxy(35, 10);
        TextColor(2);
        cout << "Choose a option: ";
        int opt;
        cin >> opt;
        TextColor(7);
        fflush(stdin);
        string date = "";
        int id, day, month, year;
        system("cls");
        GetOutBill();
        if (exports.isEmpty())
        {
            return;
        }
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO position;
        GetConsoleScreenBufferInfo(hConsole, &position);
        int x = position.dwCursorPosition.X, y = position.dwCursorPosition.Y;
        if (opt == 1)
        {
            string idString;
            gotoxy(15, y + 2);
            cout << "Enter the Id which you want to search: ";
            fflush(stdin);
            getline(cin, idString);
            if (CheckChar(idString))
            {
                id = 0;
            }
            else
            {
                id = stoi(idString);
            }
        }
        else if (opt == 2)
        {
            bool check = false;
            while (true)
            {
                gotoxy(15, y);
                if (check)
                {
                    TextColor(4);
                    cout << "Wrong format of date. Please try again!";
                    TextColor(7);
                }
                gotoxy(15, y + 2);
                cout << "Enter the date which you want to get (dd/mm/yyyy): ";
                for (int i = 0; i < date.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(66, y + 2);
                getline(cin, date);
                fflush(stdin);
                if (date[2] == '/' && date[5] == '/' && date.length() == 10)
                    break;
                else
                    check = true;
            }
            day = atof(date.substr(0, 2).c_str());
            month = atof(date.substr(3, 5).c_str());
            year = atof(date.substr(6, 10).c_str());
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        ERROR";
            TextColor(7);
            return;
        }
        system("cls");
        loadingAnimation();
        LinkedList<Bill *> searchList = opt == 1 ? exports.search(id) : exports.search(day, month, year);
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST EXPORTS\n";
        TextColor(6);
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        cout << "            ";
        cout << "|  ID |  Buyer ID   |       Type        |       Date        |     Total price     |   Payment type   |" << endl;
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        searchList.get();
        if (searchList.getSize())
        {
            TextColor(6);
            cout << "            ";
            cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        EXPORT NOT FOUND!!\n\n";
        }
        TextColor(7);
    }
}
// /*------------------------------OutBill Construction-------------------------------*/

// /*------------------------------InBill Construction--------------------------------*/
void Dashboard::ReadInBill()
{
    ifstream in;
    in.open("Database\\InBill.txt", ios_base::in);
    if (!in.is_open())
    {
        TextColor(4);
        cout << "Could not find database" << endl;
        TextColor(7);
        return;
    }
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        imports.create(new InBill());
        imports[i]->Read(in);
    }
    in.close();
    imports.setId();
}
void Dashboard::SaveInBill()
{
    if (role == "Administrator")
    {
        ofstream out;
        out.open("Database\\InBill.txt", ios_base::out);
        if (!out.is_open())
        {
            TextColor(4);
            cout << "Could not find database" << endl;
            TextColor(7);
            return;
        }
        imports.save(out);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::GetInBill()
{
    loadingAnimation();
    if (role == "Administrator")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST IMPORTS\n";
        TextColor(6);
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        cout << "            ";
        cout << "|  ID |  Buyer ID   |       Type        |       Date        |     Total price     |   Payment type   |" << endl;
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        if (imports.isEmpty())
        {
            cout << "\n\n\n        CURRENTLY THE IMPORTS LIST IS EMPTY.\n\n";
        }
        else
        {
            imports.get();
            TextColor(6);
            cout << "            ";
            cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
            TextColor(7);
        }
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::GetDetailInBill()
{
    loadingAnimation();
    if (role == "Administrator" || role == "Staff")
    {
        GetInBill();
        string idString;
        cout << "\n\n\n        Enter the Id which you want to get details: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        fflush(stdin);
        system("cls");
        TextColor(2);
        loadingAnimation();
        cout << "\n\n\n\t\t\t\t\t\t\t LIST IMPORTS\n";
        TextColor(6);
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        cout << "            ";
        cout << "|  ID |  Buyer ID   |       Type        |       Date        |     Total price     |   Payment type   |" << endl;
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        if (imports.isEmpty())
        {
            cout << "\n\n\n        CURRENTLY THE IMPORTS LIST IS EMPTY.\n";
        }
        if (SP.getNumberInList(id) == -1)
        {
            TextColor(4);
            cout << "\n\n\n        IMPORTS BILL NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        imports[imports.getNumberInList(id)]->get();
        cout << "            ";
        TextColor(6);
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        LinkedList<Middleware *> materials = MHNL.search(id);
        TextColor(2);
        cout << "\n\n\t\t\t\t\t LIST MATERIALS\n";
        TextColor(6);
        cout << "                    ";
        cout << "+-----------------------------------+--------------------+" << endl;
        cout << "                    ";
        cout << "|           Name Material           |      Quantity      |" << endl;
        cout << "                    ";
        cout << "+-----------------------------------+--------------------+ " << endl;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO position;
        GetConsoleScreenBufferInfo(hConsole, &position);
        int root = position.dwCursorPosition.Y;
        TextColor(7);
        if (materials.isEmpty())
        {
            gotoxy(20, root);
            cout << "\n\n\n        CURRENTLY THIS PRODUCT HAS NO MATERIAL\n\n";
            return;
        }
        for (int i = 0; i < materials.getSize(); i++)
        {
            int orderId = materials[i]->getId2();
            if (!NL.CheckId(orderId))
            {
                gotoxy(20, root);
                TextColor(6);
                cout << "|";
                TextColor(7);
                cout << "Nguyen lieu id " << orderId << " da bi xoa";
                gotoxy(56, root);
                TextColor(6);
                cout << "|";
                TextColor(7);
                gotoxy(77, root);
                TextColor(6);
                cout << "|" << endl;
                TextColor(7);
                continue;
            }
            gotoxy(20, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            cout << NL[NL.getNumberInList(orderId)]->getName();
            gotoxy(56, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            cout << "\t" << materials[i]->getSL() << NL[NL.getNumberInList(orderId)]->getUnit();
            gotoxy(77, root);
            TextColor(6);
            cout << "|" << endl;
            TextColor(7);
            root = root + 1;
        }

        TextColor(6);
        cout << "                    ";
        cout << "+-----------------------------------+--------------------+ " << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::DeleteInBill()
{
    if (role == "Administrator")
    {
        GetInBill();
        if (imports.isEmpty())
            return;
        string idString;
        cout << "\n\n\n        Enter the Id which you want to delete: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        if (!imports.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID IMPORT NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        LinkedList<Middleware *> materials = MHNL.search(id);
        for (int i = 0; i < materials.getSize(); i++)
        {
            int sttIdNL = NL.getNumberInList(materials[i]->getId2());
            NL[sttIdNL]->updateSL(1, -materials[i]->getSL());
        }
        imports.remove(id);
        Delete(id, "MHNL");

        SaveInBill();
        SaveNL();
        system("cls");
        loadingAnimation();
        GetInBill();
        TextColor(2);
        cout << "\n\n\n        DELETE IMPORT BILL SUCCESSFULLY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::CreateInBill(int n)
{
    if (role == "Administrator")
    {
        int maPS = idUser;
        int day, month, price = 0, totalPrice = 0, year;
        string PaymentType, date;
        for (int i = 0; i < n; i++)
        {
            system("cls");
            TextColor(2);
            cout << "\n\n\n\t\t\t\t\t ADD NEW IMPORTS\n\n";
            TextColor(6);
            cout << "                 ";
            cout << "+-----+-------------+-------------------+-------------------+" << endl;
            cout << "                 ";
            cout << "| STT |  Buyer ID   |   Payment type    |       Date        |" << endl;
            cout << "                 ";
            cout << "+-----+-------------+-------------------+-------------------+" << endl;
            cout << setw(18) << "|";
            TextColor(7);
            cout << i + 1;
            fflush(stdin);
            gotoxy(23, 8);
            TextColor(6);
            cout << "|";
            TextColor(7);
            gotoxy(25, 8);
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
                for (int i = 0; i < PaymentType.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(40, 8);
                fflush(stdin);
                getline(cin, PaymentType);
                if (PaymentType == "cash" || PaymentType == "Cash" || PaymentType == "Banking" || PaymentType == "banking" || PaymentType == "0" || PaymentType == "1")
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
            TextColor(6);
            cout << "|";
            TextColor(7);
            check = false;
            string dateErr = "Wrong format of date. Please try again!";
            while (true)
            {
                gotoxy(15, 4);
                if (check)
                {
                    TextColor(4);
                    cout << dateErr;
                    TextColor(7);
                }
                gotoxy(58, 8);
                for (int i = 0; i < date.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(58, 8);
                getline(cin, date);
                fflush(stdin);
                if (date[2] == '/' && date[5] == '/' && date.length() == 10)
                {
                    day = atof(date.substr(0, 2).c_str());
                    month = atof(date.substr(3, 5).c_str());
                    year = atof(date.substr(6, 10).c_str());
                    if (isValidDate(day, month, year))
                        break;
                    else
                    {
                        check = true;
                    }
                }
                else
                    check = true;
            }
            gotoxy(15, 4);
            for (int i = 0; i < dateErr.length(); i++)
            {
                cout << " ";
            }
            gotoxy(77, 8);
            TextColor(6);
            cout << "|" << endl;
            cout << "                 ";
            cout << "+-----+-------------+-------------------+-------------------+" << endl;
            TextColor(7);

            imports.create(new InBill(year, month, day, totalPrice, maPS, PaymentType));
            int dem;
            int idHD = imports.getIdTail();
            cout << "\n\n\n        Quantity of materials: ";
            string demSL;
            string errSL = "Invalid quantity. Try again!";
            string errPrice = "Please enter a currency value.";
            check = false;
            while (true)
            {
                if (check)
                {
                    gotoxy(23, 12);
                    TextColor(4);
                    cout << errSL;
                    TextColor(7);
                }
                gotoxy(30, 13);
                for (int i = 0; i < demSL.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(30, 13);
                getline(cin, demSL);
                fflush(stdin);
                if (!CheckChar(demSL))
                {
                    dem = atof(demSL.substr(0, demSL.length()).c_str());
                    if (dem > 0)
                    {
                        break;
                    }
                }
                check = true;
            }
            gotoxy(23, 12);
            for (int i = 0; i < errSL.length(); i++)
            {
                cout << " ";
            }
            TextColor(2);
            cout << "\n\n\n\n\t\t\t\t LIST Materials\n\n";
            TextColor(6);
            cout << "                 ";
            cout << "+------------------------------+--------------------+--------------------+" << endl;
            cout << "                 ";
            cout << "|         Materials            |      Quantity      |        Price       |" << endl;
            cout << "                 ";
            cout << "+------------------------------+--------------------+--------------------+ " << endl;
            int SL, root = 21;
            string idNL = "", quantity = "", strPrice = "";
            int arrID[50] = {0};
            int n = 0;
            string errIdSP = "This material already exists. Please add another material!";
            for (int i = 0; i < dem; i++)
            {
                TextColor(6);
                gotoxy(17, root);
                cout << "|";
                TextColor(7);
                string err = "Material not found. Please try again or add that material and comeback.";
                bool check = false;
                int ma;
                while (true)
                {
                    gotoxy(20, root);
                    getline(cin, idNL);
                    fflush(stdin);
                    if (CheckChar(idNL))
                    {
                        // name
                        ma = NL.getIdByName(idNL);
                        if (!NL.CheckId(ma))
                        {
                            check = true;
                            if (check)
                            {
                                gotoxy(17, 17);
                                TextColor(4);
                                cout << err;
                                TextColor(7);
                            }
                        }
                        else
                        {
                            if (checkIdInArray(arrID, n, ma))
                            {
                                arrID[n] = ma;
                                n++;
                                break;
                            }
                            else
                            {
                                gotoxy(17, 17);
                                for (int i = 0; i < err.length(); i++)
                                {
                                    cout << " ";
                                }
                                gotoxy(17, 17);
                                TextColor(4);
                                cout << errIdSP;
                                TextColor(7);
                            }
                        }
                    }
                    else
                    {
                        // ID
                        ma = atof(idNL.substr(0, idNL.length()).c_str());
                        if (!NL.CheckId(ma))
                        {
                            check = true;
                            if (check)
                            {
                                gotoxy(17, 17);
                                TextColor(4);
                                cout << err;
                                TextColor(7);
                            }
                        }
                        else
                        {
                            if (checkIdInArray(arrID, n, ma))
                            {
                                arrID[n] = ma;
                                n++;
                                break;
                            }
                            else
                            {
                                gotoxy(17, 17);
                                for (int i = 0; i < err.length(); i++)
                                {
                                    cout << " ";
                                }
                                gotoxy(17, 17);
                                TextColor(4);
                                cout << errIdSP;
                                TextColor(7);
                            }
                        }
                    }
                    gotoxy(20, root);
                    for (int i = 0; i < idNL.length(); i++)
                    {
                        cout << " ";
                    }
                }
                gotoxy(17, 17);
                for (int i = 0; i < err.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(17, 17);
                for (int i = 0; i < errIdSP.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(48, root);
                TextColor(6);
                cout << "|";
                TextColor(7);

                check = false;
                while (true)
                {
                    if (check)
                    {
                        gotoxy(17, 17);
                        TextColor(4);
                        cout << errSL;
                        TextColor(7);
                    }
                    gotoxy(50, root);
                    for (int i = 0; i < quantity.length(); i++)
                    {
                        cout << " ";
                    }
                    gotoxy(50, root);
                    getline(cin, quantity);
                    fflush(stdin);
                    if (!CheckChar(quantity))
                    {
                        SL = atof(quantity.substr(0, quantity.length()).c_str());
                        if (SL > 0)
                        {
                            break;
                        }
                    }
                    check = true;
                }
                gotoxy(17, 17);
                for (int i = 0; i < errSL.length(); i++)
                {
                    cout << " ";
                }

                gotoxy(69, root);
                TextColor(6);
                cout << "|";
                TextColor(7);

                check = false;
                while (true)
                {
                    if (check)
                    {
                        gotoxy(17, 17);
                        TextColor(4);
                        cout << errPrice;
                        TextColor(7);
                    }
                    gotoxy(72, root);
                    for (int i = 0; i < quantity.length(); i++)
                    {
                        cout << " ";
                    }
                    gotoxy(72, root);
                    getline(cin, quantity);
                    fflush(stdin);
                    if (!CheckChar(quantity))
                    {
                        price = atof(quantity.substr(0, quantity.length()).c_str());
                        if (price > 0)
                        {
                            break;
                        }
                    }
                    check = true;
                }
                gotoxy(17, 17);
                for (int i = 0; i < errPrice.length(); i++)
                {
                    cout << " ";
                }

                gotoxy(90, root);
                TextColor(6);
                cout << "|" << endl;
                cout << "                 ";
                cout << "+------------------------------+--------------------+--------------------+" << endl;
                TextColor(7);
                root = root + 2;
                totalPrice += price;
                Create(idHD, ma, SL, "MHNL");
                NL[NL.getNumberInList(ma)]->updateSL(1, SL);
            }
            imports[imports.getSize() - 1]->setPrice(totalPrice);
            if (dem <= 0)
            {
                cout << "                 ";
                cout << "+------------------------------+--------------------+--------------------+" << endl;
            }
        }
        SaveNL();
        SaveInBill();
        system("cls");
        loadingAnimation();
        TextColor(2);
        cout << "\n\n\n        CREATE NEW EXPORT SUCCESSFULLY\n";
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::UpdateInBill()
{
    if (role == "Administrator")
    {
        GetInBill();
        if (imports.isEmpty())
        {
            return;
        }
        int price, totalPrice = 0;
        string idString;
        cout << "\n\n\n        Enter the Id which you want to update: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        if (!imports.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID IMPORT NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        system("cls");
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t UPDATE IMPORTS\n\n";
        TextColor(6);
        cout << "                 ";
        cout << "+-----+-------------+-------------------+-------------------+" << endl;
        cout << "                 ";
        cout << "| ID  |  Buyer ID   |   Payment type    |       Date        |" << endl;
        cout << "                 ";
        cout << "+-----+-------------+-------------------+-------------------+" << endl;
        TextColor(7);
        imports.update(id);
        TextColor(6);
        cout << "                 ";
        cout << "+-----+-------------+-------------------+-------------------+" << endl;
        TextColor(7);
        LinkedList<Middleware *> materials = MHNL.search(id);
        for (int i = 0; i < materials.getSize(); i++)
        {
            int sttIdNL = NL.getNumberInList(materials[i]->getId2());
            NL[sttIdNL]->updateSL(1, -materials[i]->getSL());
        }
        MHNL.remove(id);
        int dem;
        cout << "\n\n\n        Quantity of materials: ";
        string demSL;
        string errSL = "Invalid quantity. Try again!";
        string errPrice = "Please enter a currency value.";
        bool check = false;
        while (true)
        {
            if (check)
            {
                gotoxy(23, 12);
                TextColor(4);
                cout << errSL;
                TextColor(7);
            }
            gotoxy(30, 13);
            for (int i = 0; i < demSL.length(); i++)
            {
                cout << " ";
            }
            gotoxy(30, 13);
            getline(cin, demSL);
            fflush(stdin);
            if (!CheckChar(demSL))
            {
                dem = atof(demSL.substr(0, demSL.length()).c_str());
                if (dem > 0)
                {
                    break;
                }
            }
            check = true;
        }
        gotoxy(23, 12);
        for (int i = 0; i < errSL.length(); i++)
        {
            cout << " ";
        }
        TextColor(2);
        cout << "\n\n\n\n\t\t\t\t LIST Materials\n\n";
        TextColor(6);
        cout << "                 ";
        cout << "+------------------------------+--------------------+--------------------+" << endl;
        cout << "                 ";
        cout << "|         Materials            |      Quantity      |        Price       |" << endl;
        cout << "                 ";
        cout << "+------------------------------+--------------------+--------------------+ " << endl;
        int SL, root = 21;
        string idNL = "", quantity = "", strPrice = "";
        int arrID[50] = {0};
        int n = 0;
        string errIdSP = "This material already exists. Please add another material!";
        for (int i = 0; i < dem; i++)
        {
            TextColor(6);
            gotoxy(17, root);
            cout << "|";
            TextColor(7);
            string err = "Material not found. Please try again or add that material and comeback.";
            bool check = false;
            int ma = 0;
            while (true)
            {
                gotoxy(20, root);
                getline(cin, idNL);
                fflush(stdin);
                if (CheckChar(idNL))
                {
                    // name
                    ma = NL.getIdByName(idNL);
                    if (!NL.CheckId(ma))
                    {
                        check = true;
                        if (check)
                        {
                            gotoxy(17, 17);
                            TextColor(4);
                            cout << err;
                            TextColor(7);
                        }
                    }
                    else
                    {
                        if (checkIdInArray(arrID, n, ma))
                        {
                            arrID[n] = ma;
                            n++;
                            break;
                        }
                        else
                        {
                            gotoxy(17, 17);
                            for (int i = 0; i < err.length(); i++)
                            {
                                cout << " ";
                            }
                            gotoxy(17, 17);
                            TextColor(4);
                            cout << errIdSP;
                            TextColor(7);
                        }
                    }
                }
                else
                {
                    // ID
                    ma = atof(idNL.substr(0, idNL.length()).c_str());
                    if (!NL.CheckId(ma))
                    {
                        check = true;
                        if (check)
                        {
                            gotoxy(17, 17);
                            TextColor(4);
                            cout << err;
                            TextColor(7);
                        }
                    }
                    else
                    {
                        if (checkIdInArray(arrID, n, ma))
                        {
                            arrID[n] = ma;
                            n++;
                            break;
                        }
                        else
                        {
                            gotoxy(17, 17);
                            for (int i = 0; i < err.length(); i++)
                            {
                                cout << " ";
                            }
                            gotoxy(17, 17);
                            TextColor(4);
                            cout << errIdSP;
                            TextColor(7);
                        }
                    }
                }
                gotoxy(20, root);
                for (int i = 0; i < idNL.length(); i++)
                {
                    cout << " ";
                }
            }
            gotoxy(17, 17);
            for (int i = 0; i < err.length(); i++)
            {
                cout << " ";
            }
            gotoxy(17, 17);
            for (int i = 0; i < errIdSP.length(); i++)
            {
                cout << " ";
            }
            gotoxy(48, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            check = false;
            while (true)
            {
                if (check)
                {
                    gotoxy(17, 17);
                    TextColor(4);
                    cout << errSL;
                    TextColor(7);
                }
                gotoxy(50, root);
                for (int i = 0; i < quantity.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(50, root);
                getline(cin, quantity);
                fflush(stdin);
                if (!CheckChar(quantity))
                {
                    SL = atof(quantity.substr(0, quantity.length()).c_str());
                    if (SL > 0)
                    {
                        break;
                    }
                }
                check = true;
            }
            gotoxy(17, 17);
            for (int i = 0; i < errSL.length(); i++)
            {
                cout << " ";
            }

            gotoxy(69, root);
            TextColor(6);
            cout << "|";
            TextColor(7);

            check = false;
            while (true)
            {
                if (check)
                {
                    gotoxy(17, 17);
                    TextColor(4);
                    cout << errPrice;
                    TextColor(7);
                }
                gotoxy(72, root);
                for (int i = 0; i < strPrice.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(72, root);
                getline(cin, strPrice);
                fflush(stdin);
                if (!CheckChar(strPrice))
                {
                    price = atof(strPrice.substr(0, strPrice.length()).c_str());
                    if (price > 0)
                    {
                        break;
                    }
                }
                check = true;
            }
            gotoxy(17, 17);
            for (int i = 0; i < errPrice.length(); i++)
            {
                cout << " ";
            }

            gotoxy(90, root);
            TextColor(6);
            cout << "|" << endl;
            cout << "                 ";
            cout << "+------------------------------+--------------------+--------------------+ " << endl;
            TextColor(7);
            root = root + 2;
            totalPrice += price;
            Create(id, ma, SL, "MHNL");
            NL[NL.getNumberInList(ma)]->updateSL(1, SL);
        }
        if (dem <= 0)
        {
            cout << "                 ";
            cout << "+------------------------------+--------------------+--------------------+" << endl;
        }
        imports[imports.getNumberInList(id)]->setPrice(totalPrice);
        SaveInBill();
        SaveNL();
        system("cls");
        loadingAnimation();
        TextColor(2);
        cout << "\n\n\n        UPDATE IMPORT SUCCESSFULLY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::SortInBill()
{
    if (role == "Administrator")
    {
        imports.sortByDate();
        loadingAnimation();
        GetInBill();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}

void Dashboard::SearchInBill()
{
    if (role == "Administrator" || role == "Staff")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t CHOOSE OPTION SEARCH\n";
        TextColor(6);
        gotoxy(35, 4);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "1.Search by ID Imports";
        gotoxy(85, 5);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 6);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "2.Search by Date";
        TextColor(6);
        gotoxy(85, 7);
        cout << "|" << endl;
        gotoxy(35, 8);
        cout << "+-------------------------------------------------+" << endl;
        TextColor(2);
        gotoxy(35, 10);
        cout << "Choose a option: ";
        int opt;
        cin >> opt;
        TextColor(7);
        fflush(stdin);
        string date;
        int id, day, month, year;
        system("cls");
        GetInBill();
        if (imports.isEmpty())
        {
            return;
        }
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO position;
        GetConsoleScreenBufferInfo(hConsole, &position);
        int x = position.dwCursorPosition.X, y = position.dwCursorPosition.Y;
        if (opt == 1)
        {
            string idString;
            cout << "\n\n\n        Enter the Id which you want to search: ";
            fflush(stdin);
            getline(cin, idString);
            if (CheckChar(idString))
            {
                id = 0;
            }
            else
            {
                id = stoi(idString);
            }
        }
        else if (opt == 2)
        {
            bool check = false;
            while (true)
            {
                gotoxy(15, y);
                if (check)
                {
                    TextColor(4);
                    cout << "Wrong format of date. Please try again!";
                    TextColor(7);
                }
                gotoxy(15, y + 2);
                cout << "Enter the date which you want to get (dd/mm/yyyy): ";
                for (int i = 0; i < date.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(66, y + 2);
                getline(cin, date);
                fflush(stdin);
                if (date[2] == '/' && date[5] == '/' && date.length() == 10)
                    break;
                else
                    check = true;
            }
            day = atof(date.substr(0, 2).c_str());
            month = atof(date.substr(3, 5).c_str());
            year = atof(date.substr(6, 10).c_str());
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        ERROR";
            TextColor(7);
            return;
        }
        system("cls");
        loadingAnimation();
        LinkedList<Bill *> searchList = opt == 1 ? imports.search(id) : imports.search(day, month, year);
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST IMPORTS\n";
        TextColor(6);
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        cout << "            ";
        cout << "|  ID |  Buyer ID   |       Type        |       Date        |     Total price     |   Payment type   |" << endl;
        cout << "            ";
        cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        TextColor(7);
        searchList.get();
        if (searchList.getSize())
        {
            TextColor(6);
            cout << "            ";
            cout << "+-----+-------------+-------------------+-------------------+---------------------+------------------+" << endl;
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        IMPORT NOT FOUND !!! \n\n";
        }
        TextColor(7);
    }
}
/*------------------------------InBill Construction--------------------------------*/

/*------------------------------Nguyen Lieu------------------------------------------*/
void Dashboard::CreateNL(int n)
{
    if (role == "Administrator")
    {
        string name;
        int SL;
        string DonVi;
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t ADD NEW MATERIALS\n\n";
        TextColor(6);
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        cout << "                 ";
        cout << "| STT |      Name Material       |      Quantity         |       Unit       |" << endl;
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        int root = 9;
        for (int i = 0; i < n; i++)
        {
            TextColor(6);
            cout << setw(18) << "|";
            TextColor(7);
            cout << i + 1;
            gotoxy(23, root);
            TextColor(6);
            cout << "|";
            TextColor(7);

            string errName = "This name is available. Please use a another name!";
            bool check = false;
            while (true)
            {
                if (check)
                {
                    gotoxy(18, 5);
                    TextColor(4);
                    cout << errName;
                    TextColor(7);
                }
                gotoxy(25, root);
                for (int i = 0; i < name.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(25, root);
                fflush(stdin);
                getline(cin, name);
                if (!NL.CheckName(name))
                {
                    break;
                }
                else
                {
                    check = true;
                }
            }
            gotoxy(18, 5);
            for (int i = 0; i < errName.length(); i++)
            {
                cout << " ";
            }
            gotoxy(50, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            cin >> SL;
            fflush(stdin);
            gotoxy(74, root);
            TextColor(6);
            cout << "|";
            DonVi = "";
            while (DonVi != "ml" && DonVi != "g")
            {
                gotoxy(75, root);
                for (int i = 0; i < DonVi.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(75, root);
                TextColor(7);
                getline(cin, DonVi);
                fflush(stdin);
            }

            gotoxy(93, root);
            TextColor(6);
            cout << "|" << endl;
            cout << "                 ";
            cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
            TextColor(7);
            root = root + 2;
            NL.create(new Materials(name, SL, DonVi));
        }
        system("cls");
        loadingAnimation();
        GetNL();
        TextColor(2);
        cout << "\n\n\n        CREATE MATERIAL SUCCESSFULLY" << endl;
        TextColor(7);
        SaveNL();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}

void Dashboard::GetNL()
{
    loadingAnimation();
    if (role == "Administrator" || role == "Staff")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t LIST MATERIALS\n";
        TextColor(6);
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        cout << "                 ";
        cout << "|  ID |      Name Material       |      Quantity         |       Unit       |" << endl;
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        TextColor(7);
        if (NL.isEmpty())
        {
            cout << "\n\n\n        CURRENTLY THE PRODUCT LIST IS EMPTY!!\n\n";
        }
        else
        {
            NL.get();
            TextColor(6);
            cout << "                 ";
            cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
            TextColor(7);
        }
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::DeleteNL()
{
    if (role == "Administrator")
    {
        GetNL();
        if (NL.isEmpty())
        {
            return;
        }
        string idString;
        cout << "\n\n\n        Enter the Id which you want to delete: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        if (!NL.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID MATERIAL NOT FOUND\n\n";
            TextColor(7);
            return;
        }
        NL.remove(id);
        SaveNL();
        system("cls");
        loadingAnimation();
        GetNL();
        TextColor(2);
        cout << "\n\n\n        DELETE MATERIAL SUCCESSFULLY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::SearchNL()
{
    if (role == "Administrator" || role == "Staff")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t CHOOSE OPTION SEARCH\n";
        TextColor(6);
        gotoxy(35, 4);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "1.Search by ID Material";
        gotoxy(85, 5);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 6);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "2.Search by Name Material";
        gotoxy(85, 7);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 8);
        cout << "+-------------------------------------------------+" << endl;
        gotoxy(35, 10);
        TextColor(2);
        cout << "Choose a option: ";
        int opt;
        cin >> opt;
        TextColor(7);
        fflush(stdin);
        string name;
        int id;
        system("cls");
        GetNL();
        if (NL.isEmpty())
            return;
        if (opt == 1)
        {
            string idString;
            cout << "\n\n\n        Enter the Id which you want to search: ";
            fflush(stdin);
            getline(cin, idString);
            if (CheckChar(idString))
            {
                id = 0;
            }
            else
            {
                id = stoi(idString);
            }
        }
        else if (opt == 2)
        {
            cout << "\n\n\n        Enter the name which you want to get:";
            getline(cin, name);
            fflush(stdin);
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        ERROR";
            TextColor(7);
            return;
        }
        system("cls");
        loadingAnimation();
        LinkedList<Materials *> searchList = opt == 1 ? NL.search(id) : NL.search(name);
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t LIST MATERIALS\n";
        TextColor(6);
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        cout << "                 ";
        cout << "|  ID |      Name Material       |      Quantity         |       Unit       |" << endl;
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        TextColor(7);
        searchList.get();
        if (searchList.getSize())
        {
            TextColor(6);
            cout << "                 ";
            cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        MATERIAL NOT FOUND!!!\n\n";
        }
        TextColor(7);
    }
};
void Dashboard::UpdateNL()
{
    if (role == "Administrator" || role == "Staff")
    {
        GetNL();
        if (NL.isEmpty())
        {
            return;
        }
        int id;
        cout << "\n\n\n        Choose the Id which you want to update: ";
        cin >> id;
        fflush(stdin);
        if (!NL.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID MATERIAL NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        system("cls");
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t UPDATE MATERIALS\n";
        TextColor(6);
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        cout << "                 ";
        cout << "| ID  |      Name Material       |      Quantity         |       Unit       |" << endl;
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        TextColor(7);
        NL.update(id);
        TextColor(6);
        cout << "                 ";
        cout << "+-----+--------------------------+-----------------------+------------------+" << endl;
        TextColor(7);
        SaveNL();
        system("cls");
        loadingAnimation();
        GetNL();
        TextColor(2);
        cout << "\n\n\n        UPDATE MATERIAL SUCCESSFULLY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
};
void Dashboard::SortNL()
{
    if (role == "Administrator" || role == "Staff")
    {
        NL.sortByName();
        loadingAnimation();
        GetNL();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
};
void Dashboard::ReadNL()
{

    ifstream in;
    in.open("Database\\Materials.txt", ios_base::in);
    if (!in.is_open())
    {
        TextColor(4);
        cout << "Could not find database" << endl;
        TextColor(7);
        return;
    }
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        NL.create(new Materials());
        NL[i]->Read(in);
    }
    in.close();
    NL.setId();
}
void Dashboard::SaveNL()
{
    if (role == "Administrator" || role == "Staff")
    {
        ofstream out;
        out.open("Database\\Materials.txt", ios_base::out);
        if (!out.is_open())
        {
            TextColor(4);
            cout << "Could not find database" << endl;
            TextColor(7);
            return;
        }
        NL.save(out);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
/*------------------------------Nguyen Lieu------------------------------------------*/

/* -----------------------------Product-----------------------------------------------*/
void Dashboard::CreateSP(int n)
{
    if (role == "Administrator")
    {
        string name;
        int price;
        string guide;

        for (int i = 0; i < n; i++)
        {
            system("cls");
            TextColor(2);
            cout << "\n\n\n\t\t\t\t ADD NEW PRODUCTS\n\n";
            TextColor(6);
            cout << "                    ";
            cout << "+-----+--------------------------------+-------------+" << endl;
            cout << "                    ";
            cout << "| STT |          Name Product          |    Price    |" << endl;
            cout << "                    ";
            cout << "+-----+--------------------------------+-------------+" << endl;

            cout << setw(21) << "|";
            TextColor(7);
            cout << i + 1;
            gotoxy(26, 8);
            TextColor(6);
            cout << "|";
            TextColor(7);
            string errName = "This name is available. Please use a another name!";
            string errPrice = "Please enter a number.";
            bool check = false;
            string strPrice = "";
            while (true)
            {
                if (check)
                {
                    gotoxy(21, 4);
                    TextColor(4);
                    cout << errName;
                    TextColor(7);
                }
                gotoxy(27, 8);
                for (int i = 0; i < name.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(27, 8);
                fflush(stdin);
                getline(cin, name);
                if (!SP.CheckName(name))
                {
                    break;
                }
                else
                {
                    check = true;
                }
            }
            gotoxy(21, 4);
            for (int i = 0; i < errName.length(); i++)
            {
                cout << " ";
            }
            gotoxy(59, 8);
            TextColor(6);
            cout << "|";
            TextColor(7);

            check = false;
            while (true)
            {
                if (check)
                {
                    gotoxy(21, 4);
                    TextColor(4);
                    cout << errPrice;
                    TextColor(7);
                }
                gotoxy(62, 8);
                for (int i = 0; i < strPrice.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(62, 8);
                getline(cin, strPrice);
                fflush(stdin);
                if (!CheckChar(strPrice))
                {
                    price = atof(strPrice.substr(0, strPrice.length()).c_str());
                    if (price > 0)
                    {
                        break;
                    }
                }
                check = true;
            }
            gotoxy(21, 4);
            for (int i = 0; i < errPrice.length(); i++)
            {
                cout << " ";
            }
            gotoxy(73, 8);
            TextColor(6);
            cout << "|" << endl;
            cout << "                    ";
            cout << "+-----+--------------------------------+-------------+" << endl;
            cout << "                    Guide: ";
            TextColor(7);
            fflush(stdin);
            getline(cin, guide);
            SP.create(new Product(name, price, guide));
            int dem;
            int idSP = SP.getIdTail();
            cout << "\n\n\n        Quantity of materials: ";
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO position;
            GetConsoleScreenBufferInfo(hConsole, &position);
            string demSL;
            string errSL = "Invalid quantity. Try again!";
            check = false;
            int y = position.dwCursorPosition.Y;
            while (true)
            {
                if (check)
                {
                    gotoxy(23, y - 1);
                    TextColor(4);
                    cout << errSL;
                    TextColor(7);
                }
                gotoxy(30, y);
                for (int i = 0; i < demSL.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(30, y);
                getline(cin, demSL);
                fflush(stdin);
                if (!CheckChar(demSL))
                {
                    dem = atof(demSL.substr(0, demSL.length()).c_str());
                    if (dem > 0)
                    {
                        break;
                    }
                }
                check = true;
            }
            gotoxy(23, y - 1);
            for (int i = 0; i < errSL.length(); i++)
            {
                cout << " ";
            }
            TextColor(2);
            cout << "\n\n\n\n\t\t\t\t LIST MATERIALS\n\n";
            TextColor(6);
            cout << "                    ";
            cout << "+------------------------------+--------------------+" << endl;
            cout << "                    ";
            cout << "|          Material            |      Quantity      |" << endl;
            cout << "                    ";
            cout << "+------------------------------+--------------------+ " << endl;

            int root = position.dwCursorPosition.Y + 8;
            int errRoot = position.dwCursorPosition.Y + 4;
            int SL;
            string idNL = "", quantity = "";
            int arrID[50] = {0};
            int n = 0;
            string errIdSP = "This material already exists. Please add another material!";
            for (int i = 0; i < dem; i++)
            {
                TextColor(6);
                gotoxy(20, root);
                cout << "|";
                TextColor(7);

                string err = "Material not found. Please try again or add that material and comeback.";
                bool check = false;
                int ma;
                while (true)
                {
                    TextColor(7);
                    gotoxy(24, root);
                    fflush(stdin);
                    getline(cin, idNL);
                    fflush(stdin);
                    if (CheckChar(idNL))
                    {
                        // name
                        ma = NL.getIdByName(idNL);
                        if (!NL.CheckId(ma))
                        {
                            check = true;
                            if (check)
                            {
                                gotoxy(23, errRoot);
                                TextColor(4);
                                cout << err;
                                TextColor(7);
                            }
                        }
                        else
                        {
                            if (checkIdInArray(arrID, n, ma))
                            {
                                arrID[n] = ma;
                                n++;
                                break;
                            }
                            else
                            {
                                gotoxy(23, errRoot);
                                for (int i = 0; i < err.length(); i++)
                                {
                                    cout << " ";
                                }
                                gotoxy(23, errRoot);
                                TextColor(4);
                                cout << errIdSP;
                                TextColor(7);
                            }
                        }
                    }
                    else
                    {
                        // ID
                        ma = atof(idNL.substr(0, idNL.length()).c_str());
                        if (!NL.CheckId(ma))
                        {
                            check = true;
                            if (check)
                            {
                                gotoxy(23, errRoot);
                                TextColor(4);
                                cout << err;
                                TextColor(7);
                            }
                        }
                        else
                        {
                            if (checkIdInArray(arrID, n, ma))
                            {
                                arrID[n] = ma;
                                n++;
                                break;
                            }
                            else
                            {
                                gotoxy(23, errRoot);
                                for (int i = 0; i < err.length(); i++)
                                {
                                    cout << " ";
                                }
                                gotoxy(23, errRoot);
                                TextColor(4);
                                cout << errIdSP;
                                TextColor(7);
                            }
                        }
                    }
                    gotoxy(24, root);
                    for (int i = 0; i < idNL.length(); i++)
                    {
                        cout << " ";
                    }
                }
                gotoxy(23, errRoot);
                for (int i = 0; i < err.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(23, errRoot);
                for (int i = 0; i < errIdSP.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(51, root);
                TextColor(6);
                cout << "|";
                TextColor(7);

                check = false;
                while (true)
                {
                    if (check)
                    {
                        gotoxy(21, 4);
                        TextColor(4);
                        cout << errSL;
                        TextColor(7);
                    }
                    gotoxy(57, root);
                    for (int i = 0; i < strPrice.length(); i++)
                    {
                        cout << " ";
                    }
                    gotoxy(57, root);
                    getline(cin, strPrice);
                    fflush(stdin);
                    if (!CheckChar(strPrice))
                    {
                        SL = atof(strPrice.substr(0, strPrice.length()).c_str());
                        if (SL > 0)
                        {
                            break;
                        }
                    }
                    check = true;
                }
                gotoxy(21, 4);
                for (int i = 0; i < errSL.length(); i++)
                {
                    cout << " ";
                }
                gotoxy(72, root);
                TextColor(6);
                cout << "|" << endl;
                cout << "                    ";
                cout << "+------------------------------+--------------------+ " << endl;
                TextColor(7);
                root = root + 2;
                Dashboard::Create(idSP, ma, SL, "NLSP");
            }
        }
        SaveSP();
        loadingAnimation();
        TextColor(2);
        cout << "\n\n\n        ADD PRODUCT SUCCESSFULLY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}

void Dashboard::GetSP()
{
    loadingAnimation();
    if (role == "Administrator" || role == "Staff")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST PRODUCTS\n";
        TextColor(6);
        cout << "       ";
        cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
        cout << "       ";
        cout << "| ID |      Name Product      |  Price  |                            Preparing                             |" << endl;
        cout << "       ";
        cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
        TextColor(7);
        if (SP.isEmpty())
        {
            cout << "\n\n\n        CURRENTLY THE PRODUCT LIST IS EMPTY.\n\n";
        }
        else
        {
            SP.get();
            TextColor(6);
            cout << "       ";
            cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
            TextColor(7);
        }
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::GetSPDetail()
{
    if (role == "Administrator" || role == "Staff")
    {
        GetSP();
        string idString;
        cout << "\n\n\n        Enter the Id which you want to get details: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        fflush(stdin);
        system("cls");
        loadingAnimation();
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST PRODUCTS\n";
        TextColor(6);
        cout << "       ";
        cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
        cout << "       ";
        cout << "| ID |      Name Product      |  Price  |                            Preparing                             |" << endl;
        cout << "       ";
        cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
        TextColor(7);
        if (SP.isEmpty())
        {
            cout << "\n\n\n        CURRENTLY THE PRODUCT LIST IS EMPTY.\n\n";
            return;
        }
        if (SP.getNumberInList(id) == -1)
        {
            TextColor(4);
            cout << "\n\n\n        PRODUCT NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        SP[SP.getNumberInList(id)]->get();
        TextColor(6);
        cout << "       ";
        cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
        TextColor(7);
        SP[SP.getNumberInList(id)]->getDetails();

        LinkedList<Middleware *> materials = NLSP.search(id);
        TextColor(2);
        cout << "\n\n\t\t\t\t\t LIST MATERIALS\n";
        TextColor(6);
        cout << "                    ";
        cout << "+-----------------------------------+--------------------+" << endl;
        cout << "                    ";
        cout << "|           Name Material           |      Quantity      |" << endl;
        cout << "                    ";
        cout << "+-----------------------------------+--------------------+ " << endl;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO position;
        GetConsoleScreenBufferInfo(hConsole, &position);
        int root = position.dwCursorPosition.Y;
        TextColor(7);
        if (materials.isEmpty())
        {
            gotoxy(20, root);
            cout << "\n\n\n        CURRENTLY THIS PRODUCT HAS NO MATERIAL\n\n";
            return;
        }
        for (int i = 0; i < materials.getSize(); i++)
        {
            int orderId = materials[i]->getId2();
            gotoxy(20, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            cout << NL[NL.getNumberInList(orderId)]->getName();
            gotoxy(56, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            cout << "\t" << materials[i]->getSL() << NL[NL.getNumberInList(orderId)]->getUnit();
            gotoxy(77, root);
            TextColor(6);
            cout << "|" << endl;
            TextColor(7);
            root = root + 1;
        }

        TextColor(6);
        cout << "                    ";
        cout << "+-----------------------------------+--------------------+ " << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::DeleteSP()
{
    if (role == "Administrator")
    {
        GetSP();
        if (SP.isEmpty())
        {
            return;
        }
        string idString;
        cout << "\n\n\n        Enter the Id which you want to delete: ";
        fflush(stdin);
        getline(cin, idString);
        int id;
        if (CheckChar(idString))
        {
            id = 0;
        }
        else
        {
            id = stoi(idString);
        }
        if (!SP.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID PRODUCT NOT FOUND\n\n";
            TextColor(7);
            return;
        }
        NLSP.remove(id);
        SP.remove(id);
        SaveSP();
        Save("NLSP");
        system("cls");
        loadingAnimation();
        GetSP();
        TextColor(2);
        cout << "\n\n\n        DELETE PRODUCT SUCCESSFULLY\n\n";
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
void Dashboard::SearchSP()
{
    if (role == "Administrator" || role == "Staff")
    {
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t CHOOSE OPTION SEARCH\n";
        TextColor(6);
        gotoxy(35, 4);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "1.Search by ID Products";
        gotoxy(85, 5);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 6);
        cout << "+-------------------------------------------------+" << endl;
        cout << "                                   |         ";
        TextColor(7);
        cout << "2.Search by Name Products";
        gotoxy(85, 7);
        TextColor(6);
        cout << "|" << endl;
        gotoxy(35, 8);
        cout << "+-------------------------------------------------+" << endl;
        TextColor(2);
        gotoxy(35, 10);
        cout << "Choose a option: ";
        int opt;
        cin >> opt;
        TextColor(7);
        fflush(stdin);
        string name;
        int id;
        system("cls");
        GetSP();
        if (SP.isEmpty())
        {
            return;
        }
        if (opt == 1)
        {
            string idString;
            cout << "\n\n\n        Enter the Id which you want to search: ";
            fflush(stdin);
            getline(cin, idString);
            if (CheckChar(idString))
            {
                id = 0;
            }
            else
            {
                id = stoi(idString);
            }
        }
        else if (opt == 2)
        {

            cout << "\n\n\n        Enter the FullName which you want to search:";
            getline(cin, name);
            fflush(stdin);
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        ERROR";
            TextColor(7);
            return;
        }
        system("cls");
        loadingAnimation();
        LinkedList<Product *> searchList = opt == 1 ? SP.search(id) : SP.search(name);
        TextColor(2);
        cout << "\n\n\n\t\t\t\t\t\t\t LIST PRODUCTS\n";
        TextColor(6);
        cout << "       ";
        cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
        cout << "       ";
        cout << "| ID |      Name Product      |  Price  |                            Preparing                             |" << endl;
        cout << "       ";
        cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
        TextColor(7);
        searchList.get();
        if (searchList.getSize())
        {
            TextColor(6);
            cout << "       ";
            cout << "+----+------------------------+---------+------------------------------------------------------------------+" << endl;
        }
        else
        {
            TextColor(4);
            cout << "\n\n\n        PRODUCT NOT FOUND!!!\n\n";
        }
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
};
void Dashboard::UpdateSP()
{
    if (role == "Administrator")
    {
        GetSP();
        if (SP.isEmpty())
        {
            return;
        }
        int id, dem;
        cout << "\n\n\n        Choose the Id which you want to update: ";
        cin >> id;
        fflush(stdin);
        if (!SP.CheckId(id))
        {
            TextColor(4);
            cout << "\n\n\n        ID PRODUCT NOT FOUND!!\n\n";
            TextColor(7);
            return;
        }
        NLSP.remove(id);
        system("cls");
        cout << "\n\n\n";
        TextColor(2);
        cout << "\t\t\t\t\t\t\t UPDATE PRODUCTS\n";
        TextColor(6);
        cout << "                    ";
        cout << "+-----+------------------------+-------------+" << endl;
        cout << "                    ";
        cout << "| ID  |      Name Product      |    Price    |" << endl;
        cout << "                    ";
        cout << "+-----+------------------------+-------------+" << endl;
        TextColor(7);
        SP.update(id);

        cout << "\n\n\n        Quantity of materials: ";
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO position;
        GetConsoleScreenBufferInfo(hConsole, &position);
        string demSL;
        string errSL = "Invalid quantity. Try again!";
        bool check = false;
        int y = position.dwCursorPosition.Y;
        while (true)
        {
            if (check)
            {
                gotoxy(23, y - 1);
                TextColor(4);
                cout << errSL;
                TextColor(7);
            }
            gotoxy(30, y);
            for (int i = 0; i < demSL.length(); i++)
            {
                cout << " ";
            }
            gotoxy(30, y);
            getline(cin, demSL);
            fflush(stdin);
            if (!CheckChar(demSL))
            {
                dem = atof(demSL.substr(0, demSL.length()).c_str());
                if (dem > 0)
                {
                    break;
                }
            }
            check = true;
        }
        gotoxy(23, y - 1);
        for (int i = 0; i < errSL.length(); i++)
        {
            cout << " ";
        }
        TextColor(2);
        cout << "\n\n\n\n\t\t\t\t\t\t\t LIST MATERIALS\n\n";
        TextColor(6);
        cout << "                    ";
        cout << "+------------------------------+--------------------+" << endl;
        cout << "                    ";
        cout << "|          Material            |      Quantity      |" << endl;
        cout << "                    ";
        cout << "+------------------------------+--------------------+ " << endl;
        int root = position.dwCursorPosition.Y + 8;
        int errRoot = position.dwCursorPosition.Y + 4;
        int SL;
        string idNL = "";
        int arrID[50] = {0};
        int n = 0;
        string errIdSP = "This product already exists. Please add another products!";
        for (int i = 0; i < dem; i++)
        {
            gotoxy(20, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            string err = "Material not found. Please try again or add that material and comeback.";
            bool check = false;
            int ma;
            while (true)
            {
                TextColor(7);
                gotoxy(24, root);
                fflush(stdin);
                getline(cin, idNL);
                fflush(stdin);
                if (CheckChar(idNL))
                {
                    // name
                    ma = NL.getIdByName(idNL);
                    if (!NL.CheckId(ma))
                    {
                        check = true;
                        if (check)
                        {
                            gotoxy(23, errRoot);
                            TextColor(4);
                            cout << err;
                            TextColor(7);
                        }
                    }
                    else
                    {
                        if (checkIdInArray(arrID, n, ma))
                        {
                            arrID[n] = ma;
                            n++;
                            break;
                        }
                        else
                        {
                            gotoxy(23, errRoot);
                            for (int i = 0; i < err.length(); i++)
                            {
                                cout << " ";
                            }
                            gotoxy(23, errRoot);
                            TextColor(4);
                            cout << errIdSP;
                            TextColor(7);
                        }
                    }
                }
                else
                {
                    // ID
                    ma = atof(idNL.substr(0, idNL.length()).c_str());
                    if (!NL.CheckId(ma))
                    {
                        check = true;
                        if (check)
                        {
                            gotoxy(23, errRoot);
                            TextColor(4);
                            cout << err;
                            TextColor(7);
                        }
                    }
                    else
                    {
                        if (checkIdInArray(arrID, n, ma))
                        {
                            arrID[n] = ma;
                            n++;
                            break;
                        }
                        else
                        {
                            gotoxy(23, errRoot);
                            for (int i = 0; i < err.length(); i++)
                            {
                                cout << " ";
                            }
                            gotoxy(23, errRoot);
                            TextColor(4);
                            cout << errIdSP;
                            TextColor(7);
                        }
                    }
                }
                gotoxy(24, root);
                for (int i = 0; i < idNL.length(); i++)
                {
                    cout << " ";
                }
            }
            gotoxy(23, errRoot);
            for (int i = 0; i < err.length(); i++)
            {
                cout << " ";
            }
            gotoxy(23, errRoot);
            for (int i = 0; i < errIdSP.length(); i++)
            {
                cout << " ";
            }
            gotoxy(51, root);
            TextColor(6);
            cout << "|";
            TextColor(7);
            cin >> SL;
            fflush(stdin);
            gotoxy(72, root);
            TextColor(6);
            cout << "|" << endl;
            cout << "                    ";
            cout << "+------------------------------+--------------------+ " << endl;
            TextColor(7);
            root = root + 2;
            Dashboard::Create(id, ma, SL, "NLSP");
        }
        SaveSP();
        system("cls");
        loadingAnimation();
        GetSP();
        TextColor(2);
        cout << "\n\n\n        UPDATE PRODUCT SUCCESSFULLY" << endl;
        TextColor(7);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
};
void Dashboard::SortSP()
{
    if (role == "Administrator" || role == "Staff")
    {
        SP.sortByName();
        loadingAnimation();
        GetSP();
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
};
void Dashboard::ReadSP()
{

    ifstream in;
    in.open("Database\\Product.txt", ios_base::in);
    if (!in.is_open())
    {
        TextColor(4);
        cout << "Could not find database" << endl;
        TextColor(7);
        return;
    }
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        SP.create(new Product());
        SP[i]->Read(in);
    }
    in.close();
    SP.setId();
}
void Dashboard::SaveSP()
{
    if (role == "Administrator")
    {
        ofstream out;
        out.open("Database\\Product.txt", ios_base::out);
        if (!out.is_open())
        {
            TextColor(4);
            cout << "Could not find database" << endl;
            TextColor(7);
            return;
        }
        SP.save(out);
    }
    else
    {
        TextColor(4);
        cout << "\nYou do not have access. Please come back.";
        TextColor(7);
    }
}
/* -----------------------------Product-----------------------------------------------*/

/*----------------------------------Middleware Constructor---------------------*/
void Dashboard::Create(int id1, int id2, int SL, string role)
{
    if (role == "NLSP")
    {
        NLSP.create(new Middleware(id1, id2, SL));
        Save("NLSP");
    }
    else if (role == "BHSP")
    {
        BHSP.create(new Middleware(id1, id2, SL));
        Save("BHSP");
    }
    else if (role == "MHNL")
    {
        MHNL.create(new Middleware(id1, id2, SL));
        Save("MHNL");
    }
};
void Dashboard::Delete(int id1, int id2, string role)
{
    if (role == "NLSP")
    {
        NLSP.remove(id1, id2);
        Save("NLSP");
    }
    else if (role == "BHSP")
    {
        BHSP.remove(id1, id2);
        Save("BHSP");
    }
    else if (role == "MHNL")
    {
        MHNL.remove(id1, id2);
        Save("MHNL");
    }
};
void Dashboard::Delete(int id, string role)
{
    if (role == "NLSP")
    {
        NLSP.remove(id);
        Save("NLSP");
    }
    else if (role == "BHSP")
    {
        BHSP.remove(id);
        Save("BHSP");
    }
    else if (role == "MHNL")
    {
        MHNL.remove(id);
        Save("MHNL");
    }
};

void Dashboard::Read(string role)
{
    if (role == "NLSP")
    {
        ifstream in;
        in.open("Database\\NLSP.txt", ios_base::in);
        if (!in.is_open())
        {
            cout << "Could not find database" << endl;
            return;
        }
        int n;
        in >> n;
        for (int i = 0; i < n; i++)
        {
            in.ignore(1);
            NLSP.create(new Middleware());
            NLSP[i]->Read(in);
        }
        in.close();
    }
    else if (role == "BHSP")
    {
        ifstream in;
        in.open("Database\\BHSP.txt", ios_base::in);
        if (!in.is_open())
        {
            cout << "Could not find database" << endl;
            return;
        }
        int n;
        in >> n;
        for (int i = 0; i < n; i++)
        {
            in.ignore(1);
            BHSP.create(new Middleware());
            BHSP[i]->Read(in);
        }
        in.close();
    }
    else if (role == "MHNL")
    {
        ifstream in;
        in.open("Database\\MHNL.txt", ios_base::in);
        if (!in.is_open())
        {
            cout << "Could not find database" << endl;
            return;
        }
        int n;
        in >> n;
        for (int i = 0; i < n; i++)
        {
            in.ignore(1);
            MHNL.create(new Middleware());
            MHNL[i]->Read(in);
        }
        in.close();
    }
};
void Dashboard::Save(string role)
{
    if (role == "NLSP")
    {
        ofstream out;
        out.open("Database\\NLSP.txt", ios_base::out);
        if (!out.is_open())
        {
            cout << "Could not find database" << endl;
            return;
        }
        NLSP.save(out);
        out.close();
    }
    else if (role == "BHSP")
    {
        ofstream out;
        out.open("Database\\BHSP.txt", ios_base::out);
        if (!out.is_open())
        {
            cout << "Could not find database" << endl;
            return;
        }
        BHSP.save(out);
        out.close();
    }
    else if (role == "MHNL")
    {
        ofstream out;
        out.open("Database\\MHNL.txt", ios_base::out);
        if (!out.is_open())
        {
            cout << "Could not find database" << endl;
            return;
        }
        MHNL.save(out);
        out.close();
    }
};
void Dashboard::Search(int id1, string role)
{
    if (role == "NLSP")
    {
        LinkedList<Middleware *> list = NLSP.search(id1);
        cout << "\nResult: ";
        list.get();
    }
    else if (role == "BHSP")
    {
        LinkedList<Middleware *> list = BHSP.search(id1);
        cout << "\nResult: ";
        list.get();
    }
    else if (role == "MHNL")
    {
        LinkedList<Middleware *> list = MHNL.search(id1);
        cout << "\nResult: ";
        list.get();
    }
};
void Dashboard::Search(int id1, int id2, string role)
{
    if (role == "NLSP")
    {
        LinkedList<Middleware *> list = NLSP.search(id1, id2);
        cout << "\nResult: ";
        list.get();
    }
    else if (role == "BHSP")
    {
        LinkedList<Middleware *> list = BHSP.search(id1, id2);
        cout << "\nResult: ";
        list.get();
    }
    else if (role == "MHNL")
    {
        LinkedList<Middleware *> list = MHNL.search(id1, id2);
        cout << "\nResult: ";
        list.get();
    }
};
void Dashboard::Get(string role)
{
    if (role == "NLSP")
    {
        NLSP.get();
    }
    else if (role == "BHSP")
    {
        BHSP.get();
    }
    else if (role == "MHNL")
    {
        MHNL.get();
    }
};
void Dashboard::GetSL(int id1, int id2, string role)
{
    if (role == "NLSP")
    {
        cout << "\nQuantity: " << NLSP.getSL(id1, id2);
    }
    else if (role == "BHSP")
    {
        cout << "\nQuantity: " << BHSP.getSL(id1, id2);
    }
    else if (role == "MHNL")
    {
        cout << "\nQuantity: " << MHNL.getSL(id1, id2);
    }
};
/*----------------------------------Middleware Constructor---------------------*/