#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    void Read(ifstream &in);
    string getEmail();
    string getPassword();
    string getRole();
    string getName();
    string getUnit();
    void setPrice(int price);
    int getId();
    int getId2();
    int getSL();
    void updateSL(int,int);
    void get();
    void getDetails();
    Node(const T &data);
    ~Node();
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
public:
    LinkedList();
    ~LinkedList();
    void save(ofstream &out);
    void get() const;
    void getLast() const;
    void get(int id, bool check = true) const;
    void create(const T &data);
    void remove(int id);
    void remove(int id1, int id2);
    void remove(string name);
    void sortByName();
    void sortByDate();
    void update(int id);
    LinkedList<T> search(string name);
    LinkedList<T> search(int id);
    LinkedList<T> search(int id1, int id2);
    int search(int year,int month,bool check);
    LinkedList<T> search(int day,int month,int year);
    Node<T> *operator[](int i);
    LinkedList<T> operator = (const LinkedList<T> &list);
    int getSL(int id1, int id2) const;
    int getIdTail();
    void setId();
    int getSize();
    int getNumberInList(int);
    int getPrice(int id);
    int getPrice(string name);
    int getIdByName(string name);
    bool ExistEmail(string email);
    bool ChangePassword(int id);
    bool CheckId(int id);
    bool CheckName(string name);
    bool isEmpty();
};
#endif
