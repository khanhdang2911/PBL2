#ifndef LIB_H
#define LIB_H
#include <regex>
#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <thread>
using namespace std;
bool is_email(const string &email)
{
    regex email_regex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return regex_match(email, email_regex);
}
bool is_password(const string &password)
{
    regex password_regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,16}$");
    return regex_match(password, password_regex);
}
void gotoxy(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int x_position = x, y_position = y;
    COORD screen;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    screen.X = x_position;
    screen.Y = y_position;
    SetConsoleCursorPosition(hOutput, screen);
}
void TextColor(int x)
{ // x la ma mau
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
bool CheckChar(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9')
        {
            return true; //
        }
    }
    return false;
}
bool isValidDate(int day, int month, int year)
{
    tm time{};
    time.tm_mday = day;
    time.tm_mon = month - 1;
    time.tm_year = year - 1900;
    time.tm_isdst = -1;
    time_t time_t_value = mktime(&time);
    if (time_t_value == -1)
    {
        return false;
    }
    tm *check_time = localtime(&time_t_value);
    if (check_time->tm_mday == day && check_time->tm_mon == month - 1 && check_time->tm_year == year - 1900)
    {
        return true;
    }
    return false;
}
bool checkIdInArray(int a[],int n,int check_id){
    for(int i = 0; i <n; i++){
        if(a[i] == check_id){
            return false;
        }
    }
    return true;
}
void loadingAnimation() {
    system("cls");
  	TextColor(2);
    const char animation[] = {'-', '\\', '|', '/'};
    const int numFrames = sizeof(animation) / sizeof(animation[0]);

    const int numIterations = 10;

    for (int i = 0; i < numIterations; ++i) {
        gotoxy(50,12);
        cout << "Loading... " << animation[i % numFrames] << "\r";
        this_thread::sleep_for(chrono::milliseconds(15));
        cout.flush();
    }
	TextColor(7);
    system("cls");
}
string Currency(int price)
{
    string number = to_string(price);
    int n = number.length() / 3;
    if (number.length() % 3 == 0)
    {
        n = n - 1;
    }
    int i = n;
    string total = number.substr(0, number.length() - 3 * n);
    while (i > 0)
    {
        total += ".";
        total += number.substr(number.length() - 3 * i, number.length() - 3 * (i - 1) - 1);
        i--;
    }
    return total;
}
#endif