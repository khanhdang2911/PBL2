#ifndef DASHBOARD_H
#define DASHBOARD_H
#include "../PS/Person.h"
#include "../Bill/Bill.h"
#include "../lib/List.h"
#include "../Product/Product.h"
#include "../Materials/Materials.h"
#include "../Middleware/Middleware.h"
class Dashboard
{
private:
    LinkedList<Person *> persons;
    LinkedList<Bill *> imports;
    LinkedList<Bill *> exports;
    LinkedList<Materials *> NL;
    LinkedList<Product *> SP;
    LinkedList<Middleware *> BHSP;
    LinkedList<Middleware *> MHNL;
    LinkedList<Middleware *> NLSP;

    string role;
    int idUser;

protected:
    void Create(int id1, int id2, int SL, string role);
    void Delete(int id1, int id2, string role);
    void Delete(int id, string role);
    void Read(string role);
    void Save(string role);
    void Search(int id2, string role);
    void Search(int id1, int id2, string role);
    void Get(string role);
    void GetSL(int id1, int id2, string role);

    void ReadPS();
    void SavePS();

    void ReadOutBill();
    void SaveOutBill();

    void ReadInBill();
    void SaveInBill();

    void ReadNL();
    void SaveNL();

    void ReadSP();
    void SaveSP();

public:
    Dashboard();
    ~Dashboard();
    
    string getRole();
    int ValidatePS(string email, string password);
    bool ValidateEmail(string email);
    // Person constructor
    void CreatePS(int);
    void GetPS();
    void GetPSDetail();
    void DeletePS();
    void UpdatePS();
    void SearchPS();
    void SortPS();
    void ChangePassword();

    // // OutBill constructor
    void DeleteOutBill();
    void GetOutBill();
    void GetDetailOutBill();
    void CreateOutBill(int);
    void UpdateOutBill();
    void SortOutBill();
    void PrintOutBill();
    void SearchOutBill();
    // // InBill constructor
    void DeleteInBill();
    void GetInBill();
    void GetDetailInBill();
    void CreateInBill(int);
    void UpdateInBill();
    void SortInBill();
    void SearchInBill();
    // Nguyen Lieu constructor
    void CreateNL(int);
    void GetNL();
    void DeleteNL();
    void SearchNL();
    void UpdateNL();
    void SortNL();

    // Product constructor
    void CreateSP(int);
    void GetSP();
    void GetSPDetail();
    void DeleteSP();
    void SearchSP();
    void UpdateSP();
    void SortSP();

    void Profit();
};
#endif