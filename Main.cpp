#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Dashboard/Dashboard.h"
#include "Dashboard/Dashboard.cpp"

using namespace std;
Dashboard ds;
char ch;

class Frame
{
public:
	Frame(int width, int height, char borderChar, char cornerChar)
		: width(width), height(height), borderChar(borderChar), cornerChar(cornerChar)
	{
	}

	void print()
	{
		int screenWidth = 155;
		int screenHeight = 10;

		int startX = (screenWidth - width) / 2;
		int startY = (screenHeight - height) / 2;
		TextColor(2);
		printHorizontalLine(startX);
		printContent(startX);
		TextColor(2);
		printHorizontalLine(startX);
	}

	void addContent(const string &line)
	{
		content.push_back(line);
	}

private:
	int width;
	int height;
	char borderChar;
	char cornerChar;
	vector<string> content;
	void printHorizontalLine(int startX)
	{
		cout << setw(startX) << cornerChar;
		for (int i = 1; i < width - 1; i++)
		{
			cout << borderChar;
		}
		cout << cornerChar << endl;
	}

	void printContent(int startX)
	{
		int i = 1;
		for (const string &line : content)
		{
			TextColor(i);
			i++;
			cout << setw(startX) << borderChar << line;
			for (int i = 0; i < (width - 2 - line.length()); i++)
			{
				cout << ' ';
			}
			cout << borderChar << endl;
		}
		TextColor(7);
	}
};

int frameWidth = 60;
int frameHeight = 60;
char frameBorderChar = '*';
char frameCornerChar = '+';

void printMenuAdmin(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                       ADMINISTRATOR");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("               > 1. Manage Human");
	}
	else
	{
		frame1.addContent("                 > 1. Manage Human");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("               > 2. Manage Products");
	}
	else
	{
		frame1.addContent("                 > 2. Manage Products");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("               > 3. Manage Materials");
	}
	else
	{
		frame1.addContent("                 > 3. Manage Materials");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("               > 4. Manage Export Receipt");
	}
	else
	{
		frame1.addContent("                 > 4. Manage Export Receipt");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("               > 5. Manage Import Receipt");
	}
	else
	{
		frame1.addContent("                 > 5. Manage Import Receipt");
	}
	if (selectedOption == 6)
	{
		frame1.addContent("               > 6. Get revenue");
	}
	else
	{
		frame1.addContent("                 > 6. Get revenue");
	}

	if (selectedOption == 7)
	{
		frame1.addContent("               > 7. Exit");
	}
	else
	{
		frame1.addContent("                 > 7. Exit");
	}
	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}

void printMenuMaterialAdmin(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                      MANAGE MATERIAL");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("             > 1. Get all information Materials");
	}
	else
	{
		frame1.addContent("               > 1. Get all information Materials");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("             > 2. Sort list Materials");
	}
	else
	{
		frame1.addContent("               > 2. Sort list Materials");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("             > 3. Add new Material");
	}
	else
	{
		frame1.addContent("               > 3. Add new Material");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("             > 4. Delete a Material");
	}
	else
	{
		frame1.addContent("               > 4. Delete a Material");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("             > 5. Update a Material");
	}
	else
	{
		frame1.addContent("               > 5. Update a Material");
	}

	if (selectedOption == 6)
	{
		frame1.addContent("             > 6. Find a Material");
	}
	else
	{
		frame1.addContent("               > 6. Find a Material");
	}
	if (selectedOption == 7)
	{
		frame1.addContent("             > 7. Exit");
	}
	else
	{
		frame1.addContent("               > 7. Exit");
	}
	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}
void printMenuProductAdmin(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                      MANAGE PRODUCT");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("             > 1. Get all information Product");
	}
	else
	{
		frame1.addContent("               > 1. Get all information Product");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("             > 2. Get detail information Product");
	}
	else
	{
		frame1.addContent("               > 2. Get detail information Product");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("             > 3. Sort list Product");
	}
	else
	{
		frame1.addContent("               > 3. Sort list Product");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("             > 4. Add new Product");
	}
	else
	{
		frame1.addContent("               > 4. Add new Product");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("             > 5. Delete a Product");
	}
	else
	{
		frame1.addContent("               > 5. Delete a Product");
	}

	if (selectedOption == 6)
	{
		frame1.addContent("             > 6. Update a Product");
	}
	else
	{
		frame1.addContent("               > 6. Update a Product");
	}
	if (selectedOption == 7)
	{
		frame1.addContent("             > 7. Find a Product");
	}
	else
	{
		frame1.addContent("               > 7. Find a Product");
	}
	if (selectedOption == 8)
	{
		frame1.addContent("             > 8. Exit");
	}
	else
	{
		frame1.addContent("               > 8. Exit");
	}
	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}

void printMenuExportReceiptAdmin(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                    MANAGE EXPORT RECEIPT");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("        > 1. Get all information Export Receipt");
	}
	else
	{
		frame1.addContent("          > 1. Get all information Export Receipt");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("        > 2. Get detail information Export Receipt");
	}
	else
	{
		frame1.addContent("          > 2. Get detail information Export Receipt");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("        > 3. Sort list Export Receipt by Date");
	}
	else
	{
		frame1.addContent("          > 3. Sort list Export Receipt by Date");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("        > 4. Add new Export Receipt");
	}
	else
	{
		frame1.addContent("          > 4. Add new Export Receipt");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("        > 5. Delete a Export Receipt");
	}
	else
	{
		frame1.addContent("          > 5. Delete a Export Receipt");
	}
	if (selectedOption == 6)
	{
		frame1.addContent("        > 6. Update a Export Receipt");
	}
	else
	{
		frame1.addContent("          > 6. Update a Export Receipt");
	}

	if (selectedOption == 7)
	{
		frame1.addContent("        > 7. Find a Export Receipt");
	}
	else
	{
		frame1.addContent("          > 7. Find a Export Receipt");
	}
	if (selectedOption == 8)
	{
		frame1.addContent("        > 8. Print a Export Receipt");
	}
	else
	{
		frame1.addContent("          > 8. Print a Export Receipt");
	}
	if (selectedOption == 9)
	{
		frame1.addContent("        > 9. Exit");
	}
	else
	{
		frame1.addContent("          > 9. Exit");
	}
	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}

void printMenuImportReceiptAdmin(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                  MANAGE IMPORT RECEIPT");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("       > 1. Get all information Import Receipt");
	}
	else
	{
		frame1.addContent("         > 1. Get all information Import Receipt");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("       > 2. Get detail information Import Receipt");
	}
	else
	{
		frame1.addContent("         > 2. Get all information Import Receipt");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("       > 3. Sort list Import Receipt by Date");
	}
	else
	{
		frame1.addContent("         > 3. Sort list Import Receipt by Date");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("       > 4. Add new Import Receipt");
	}
	else
	{
		frame1.addContent("         > 4. Add new Import Receipt");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("       > 5. Delete a Import Receipt");
	}
	else
	{
		frame1.addContent("         > 5. Delete a Import Receipt");
	}
	if (selectedOption == 6)
	{
		frame1.addContent("       > 6. Update a Import Receipt");
	}
	else
	{
		frame1.addContent("         > 6. Update a Import Receipt");
	}

	if (selectedOption == 7)
	{
		frame1.addContent("       > 7. Find a Import Receipt");
	}
	else
	{
		frame1.addContent("         > 7. Find a Import Receipt");
	}

	if (selectedOption == 8)
	{
		frame1.addContent("       > 8. Exit");
	}
	else
	{
		frame1.addContent("         > 8. Exit");
	}
	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}

void printMenuMaterialsStaff(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                     MANAGE MATERIALS");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("             > 1. Get all information Materials");
	}
	else
	{
		frame1.addContent("               > 1. Get all information Materials");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("             > 2. Sort list Materials");
	}
	else
	{
		frame1.addContent("               > 2. Sort list Materials");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("             > 3. Find a Material");
	}
	else
	{
		frame1.addContent("               > 3. Find a Material");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("             > 4. Exit");
	}
	else
	{
		frame1.addContent("               > 4. Exit");
	}

	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}
void printMenuProductStaff(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                     MANAGE PRODUCT");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("             > 1. Get all information Product");
	}
	else
	{
		frame1.addContent("               > 1. Get all information Product");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("             > 2. Get detail information Product");
	}
	else
	{
		frame1.addContent("               > 2. Get detail information Product");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("             > 3. Sort list Product");
	}
	else
	{
		frame1.addContent("               > 3. Sort list Product");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("             > 4. Find a Product");
	}
	else
	{
		frame1.addContent("               > 4. Find a Product");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("             > 5. Exit");
	}
	else
	{
		frame1.addContent("               > 5. Exit");
	}

	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}
void printExportReceiptStaff(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                    MANAGE EXPORT RECEIPT");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("          > 1. Get all information Export Receipt");
	}
	else
	{
		frame1.addContent("            > 1. Get all information Export Receipt");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("          > 2. Sort list Export Receipt by Date");
	}
	else
	{
		frame1.addContent("            > 2. Sort list Export Receipt by Date");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("          > 3. Add new Export Receipt");
	}
	else
	{
		frame1.addContent("            > 3. Add new Export Receipt");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("          > 4. Delete a Export Receipt");
	}
	else
	{
		frame1.addContent("            > 4. Delete a Export Receipt");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("          >5. Update a Export Receipt");
	}
	else
	{
		frame1.addContent("            > 5. Update a Export Receipt");
	}
	if (selectedOption == 6)
	{
		frame1.addContent("          > 6. Find a Export Receipt");
	}
	else
	{
		frame1.addContent("            > 6. Find a Export Receipt");
	}
	if (selectedOption == 7)
	{
		frame1.addContent("          > 7. Print a Export Receipt");
	}
	else
	{
		frame1.addContent("            > 7. Print a Export Receipt");
	}
	if (selectedOption == 8)
	{
		frame1.addContent("          >8. Exit");
	}
	else
	{
		frame1.addContent("            > 8. Exit");
	}

	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}

void printHumanStaff(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                      MANAGE PROFILE");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("             > 1. Get all information");
	}
	else
	{
		frame1.addContent("               > 1. Get all information");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("             > 2. Update information");
	}
	else
	{
		frame1.addContent("               > 2. Update information");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("             > 3. ChangePassword");
	}
	else
	{
		frame1.addContent("               > 3. ChangePassword");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("             > 4. Exit");
	}
	else
	{
		frame1.addContent("               > 4. Exit");
	}

	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}
void printStaff(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                          STAFF");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("               > 1. Manage Profile");
	}
	else
	{
		frame1.addContent("                 > 1. Manage Profile");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("               > 2. Manage Product");
	}
	else
	{
		frame1.addContent("                 > 2. Manage Product");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("               > 3. Manage Materials");
	}
	else
	{
		frame1.addContent("                 > 3. Manage Materials");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("               > 4. Manage Export Receipt");
	}
	else
	{
		frame1.addContent("                 > 4. Manage Export Receipt");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("               > 5. Exit");
	}
	else
	{
		frame1.addContent("                 > 5. Exit");
	}

	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}

void printMenuHumanAdmin(int selectedOption)
{

	system("cls");
	Frame frame1(frameWidth, frameHeight, frameBorderChar, frameCornerChar);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	frame1.addContent("                      MANAGE HUMAN");
	frame1.addContent("");
	if (selectedOption == 1)
	{
		frame1.addContent("             > 1. Get all information account");
	}
	else
	{
		frame1.addContent("               > 1. Get all information account");
	}
	if (selectedOption == 2)
	{
		frame1.addContent("             > 2. Get detail information account");
	}
	else
	{
		frame1.addContent("               > 2. Get detail information account");
	}
	if (selectedOption == 3)
	{
		frame1.addContent("             > 3. Sort list account");
	}
	else
	{
		frame1.addContent("               > 3. Sort list account");
	}
	if (selectedOption == 4)
	{
		frame1.addContent("             > 4. Add new account");
	}
	else
	{
		frame1.addContent("               > 4. Add new account");
	}
	if (selectedOption == 5)
	{
		frame1.addContent("             > 5. Delete a account");
	}
	else
	{
		frame1.addContent("               > 5. Delete a account");
	}

	if (selectedOption == 6)
	{
		frame1.addContent("             > 6. Update a account");
	}
	else
	{
		frame1.addContent("               > 6. Update a account");
	}
	if (selectedOption == 7)
	{
		frame1.addContent("             > 7. Find a account");
	}
	else
	{
		frame1.addContent("               > 7. Find a account");
	}
	if (selectedOption == 8)
	{
		frame1.addContent("             > 8. Change password account");
	}
	else
	{
		frame1.addContent("               > 8. Change password account");
	}
	if (selectedOption == 9)
	{
		frame1.addContent("             > 9. Exit");
	}
	else
	{
		frame1.addContent("               > 9. Exit");
	}

	frame1.addContent("");
	frame1.addContent("");
	frame1.print();
}

void MaterialsAdmin()
{

	while (true)
	{

	temp:
		int sel = 1;
		printMenuMaterialAdmin(sel);

		char key;
		while (true)
		{

			key = _getch();

			switch (key)
			{
			case 13:
				switch (sel)
				{

				case 1:
					system("cls");
					ds.GetNL();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 2:
					system("cls");
					ds.SortNL();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 3:
					system("cls");
					int quantity;
					cout << "Enter the quantity of Materials you want to add: ";
					cin >> quantity;
					ds.CreateNL(quantity);
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 4:
					system("cls");
					ds.DeleteNL();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 5:
					system("cls");
					ds.UpdateNL();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 6:
					system("cls");
					ds.SearchNL();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 7:
					system("cls");

					return;
				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 7 : sel - 1;
				printMenuMaterialAdmin(sel);
				break;

			case 80:
				sel = (sel == 7) ? 7 : sel + 1;
				printMenuMaterialAdmin(sel);
				break;
			}
		}
	}
}
void ProductAdmin()
{
	while (true)
	{
	temp:

		system("cls");
		int sel = 1;
		printMenuProductAdmin(sel);
		char key;
		while (true)
		{

			key = _getch();

			switch (key)
			{
			case 13:
				switch (sel)
				{

				case 1:
					system("cls");
					ds.GetSP();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 2:
					system("cls");
					ds.GetSPDetail();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 3:
					system("cls");
					ds.SortSP();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 4:
					system("cls");
					int quantity;
					cout << "Enter the quantity of Product you want to add: ";
					cin >> quantity;
					system("cls");
					ds.CreateSP(quantity);
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 5:
					system("cls");
					ds.DeleteSP();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 6:
					system("cls");
					ds.UpdateSP();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 7:
					system("cls");
					ds.SearchSP();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 8:
					system("cls");
					return;

				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 8 : sel - 1;
				printMenuProductAdmin(sel);
				break;

			case 80:
				sel = (sel == 8) ? 8 : sel + 1;
				printMenuProductAdmin(sel);
				break;
			}
		}
	}
}
void ExportReceiptAdmin()
{
	while (true)
	{
	temp:
		system("cls");
		int sel=1;
		printMenuExportReceiptAdmin(sel);
		char key;
		while (true)
		{

			key = _getch();
			switch (key)
			{
			case 13:
				switch (sel)
				{

				case 1:
					system("cls");
					ds.GetOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 2:
					system("cls");
					ds.GetDetailOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 3:
					system("cls");
					ds.SortOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 4:
					system("cls");
					int quantity;
					cout << "Enter the quantity of Export Receipt you want to add: ";
					cin >> quantity;
					ds.CreateOutBill(quantity);
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 5:
					system("cls");
					ds.DeleteOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 6:
					system("cls");
					ds.UpdateOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 7:
					system("cls");
					ds.SearchOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 8:
					system("cls");
					ds.PrintOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					system("cls");
					break;
				case 9:
					system("cls");
					return;
				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 9 : sel - 1;
				printMenuExportReceiptAdmin(sel);
				break;

			case 80:
				sel = (sel == 9) ? 9 : sel + 1;
				printMenuExportReceiptAdmin(sel);
				break;
			}
		}
	}
}
void ImportReceiptAdmin()
{
	while (true)
	{
	temp:
		system("cls");
		int sel=1;
		printMenuImportReceiptAdmin(sel);

		char key;
		while (true)
		{

			key = _getch();
			switch (key)
			{
			case 13:
				switch (sel)
				{

				case 1:
					system("cls");
					ds.GetInBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 2:
					system("cls");
					ds.GetDetailInBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 3:
					system("cls");

					ds.SortInBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;

					break;
				case 4:
					system("cls");

					int quantity;
					cout << "Enter the quantity of Import Receipt you want to add: ";
					cin >> quantity;
					ds.CreateInBill(quantity);
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;

					break;
				case 5:
					system("cls");

					ds.DeleteInBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;

					break;
				case 6:
					system("cls");

					ds.UpdateInBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;

					break;
				case 7:
					system("cls");

					ds.SearchInBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;

					break;
				case 8:
					system("cls");
					return;
					break;
				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 8 : sel - 1;
				printMenuImportReceiptAdmin(sel);
				break;

			case 80:
				sel = (sel == 8) ? 8 : sel + 1;
				printMenuImportReceiptAdmin(sel);
				break;
			}
		}
	}
}
void HumanAdmin()
{
	while (true)
	{

	temp:

		int sel = 1;
		
		printMenuHumanAdmin(sel);

		char key;
		while (true)
		{

			key = _getch();

			switch (key)
			{
			case 13:

				switch (sel)
				{
					{
					case 1:
						system("cls");
						ds.GetPS();
						cout << "Press any key to back: ";
						cin >> ch;
						fflush(stdin);
						goto temp;
						break;
					case 2:
						system("cls");
						ds.GetPSDetail();
						cout << "Press any key to back: ";
						cin >> ch;
						fflush(stdin);
						goto temp;
						break;
					case 3:
						system("cls");
						ds.SortPS();
						cout << "Press any key to back: ";
						cin >> ch;
						fflush(stdin);
						goto temp;
						break;
					case 4:
						system("cls");
						int quantity;
						cout << "Enter the quantity of human you want to add: ";
						cin >> quantity;
						system("cls");
						ds.CreatePS(quantity);
						cout << "Press any key to back: ";
						cin >> ch;
						fflush(stdin);
						goto temp;
						break;
					case 5:
						system("cls");
						ds.DeletePS();
						cout << "Press any key to back: ";
						cin >> ch;
						fflush(stdin);
						goto temp;
						break;
					case 6:
						system("cls");
						ds.UpdatePS();
						cout << "Press any key to back: ";
						cin >> ch;
						fflush(stdin);
						goto temp;
						break;
					case 7:
						system("cls");
						ds.SearchPS();
						cout << "Press any key to back: ";
						cin >> ch;
						fflush(stdin);
						goto temp;
						break;
					case 8:
						system("cls");
						ds.ChangePassword();
						cout << "Press any key to back: ";
						cin >> ch;
						fflush(stdin);
						goto temp;
						break;
					case 9:
						system("cls");
						return;
					default:
						break;
					}
				}

				break;

			case 72:
				sel = (sel == 1) ? 9 : sel - 1;
				printMenuHumanAdmin(sel);
				break;

			case 80:
				sel = (sel == 9) ? 9 : sel + 1;
				printMenuHumanAdmin(sel);
				break;
			}
		}
	}
}

void MaterialsStaff()
{
	while (true)
	{
	temp:
		int check = 1;

		system("cls");
		int sel = 1;

		printMenuMaterialsStaff(sel);
		char key;
		while (true)
		{

			key = _getch();

			switch (key)
			{
			case 13:
				switch (sel)
				{

				case 1:
					system("cls");
					ds.GetNL();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 2:
					system("cls");
					ds.SortNL();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 3:
					system("cls");
					ds.SearchNL();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 4:
					system("cls");
					return;
				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 4 : sel - 1;
				printMenuMaterialsStaff(sel);
				break;

			case 80:
				sel = (sel == 4) ? 4 : sel + 1;
				printMenuMaterialsStaff(sel);
				break;
			}
		}
	}
}
void ProductStaff()
{
	while (true)
	{
	temp:

		int check = 1;
		system("cls");
		int sel = 1;
		printMenuProductStaff(sel);
		char key;
		while (true)
		{

			key = _getch();

			switch (key)
			{
			case 13:
				switch (sel)
				{

				case 1:
					system("cls");
					ds.GetSP();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 2:
					system("cls");
					ds.GetSPDetail();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 3:
					system("cls");
					ds.SortSP();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 4:
					system("cls");
					ds.SearchSP();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 5:
					system("cls");
					return;

				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 5 : sel - 1;
				printMenuProductStaff(sel);
				break;

			case 80:
				sel = (sel == 5) ? 5 : sel + 1;
				printMenuProductStaff(sel);
				break;
			}
		}
	}
}
void ExportReceiptStaff()
{
	while (true)
	{
	temp:
		system("cls");
		int sel = 1;
		printExportReceiptStaff(sel);
		char key;
		while (true)
		{

			key = _getch();

			switch (key)
			{
			case 13:
				switch (sel)
				{

				case 1:
					system("cls");
					ds.GetOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 2:
					system("cls");
					ds.SortOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 3:
					system("cls");
					int quantity;
					cout << "Enter the quantity of Export Receipt you want to add: ";
					cin >> quantity;
					ds.CreateOutBill(quantity);
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 4:
					system("cls");
					ds.DeleteOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 5:
					system("cls");
					ds.UpdateOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 6:
					system("cls");
					ds.SearchOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 7:
					system("cls");
					ds.PrintOutBill();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 8:
					system("cls");
					return;

				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 8 : sel - 1;
				printExportReceiptStaff(sel);
				break;

			case 80:
				sel = (sel == 8) ? 8 : sel + 1;
				printExportReceiptStaff(sel);
				break;
			}
		}
	}
}
void HumanStaff()
{
	while (true)
	{
	temp:
		system("cls");
		int sel = 1;
		printHumanStaff(sel);
		char key;
		while (true)
		{

			key = _getch();

			switch (key)
			{
			case 13:
				switch (sel)
				{
				case 1:
					system("cls");
					ds.GetPS();

					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 2:
					system("cls");
					ds.UpdatePS();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 3:
					system("cls");
					ds.ChangePassword();
					cout << "Press any key to back: ";
					cin >> ch;
					fflush(stdin);
					goto temp;
					break;
				case 4:
					system("cls");
					return;
					break;
				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 4 : sel - 1;
				printHumanStaff(sel);
				break;

			case 80:
				sel = (sel == 4) ? 4 : sel + 1;
				printHumanStaff(sel);
				break;
			}
		}
	}
}
void Administrator()
{
temp:
	while (true)
	{

		int sel = 1;
		loadingAnimation();
		printMenuAdmin(sel);

		char key;
		while (true)
		{
			key = _getch();

			switch (key)
			{
			case 13:
				switch (sel)
				{
				case 1:
					loadingAnimation();
					HumanAdmin();
					goto temp;
					break;
				case 2:
					loadingAnimation();
					ProductAdmin();
					goto temp;
					break;
				case 3:
					loadingAnimation();
					MaterialsAdmin();
					goto temp;
					break;
				case 4:
					loadingAnimation();
					ExportReceiptAdmin();
					goto temp;
					break;
				case 5:
					loadingAnimation();
					ImportReceiptAdmin();
					goto temp;
					break;
				case 6:
					loadingAnimation();
					ds.Profit();
					char s;
					cout<<"Press any key to continue...";
					cin>>s;
					goto temp;
					break;
				case 7:
					loadingAnimation();
					system("cls");
					return;
				}

				break;

			case 72:
				sel = (sel == 1) ? 7 : sel - 1;
				printMenuAdmin(sel);
				break;

			case 80:
				sel = (sel == 7) ? 7 : sel + 1;
				printMenuAdmin(sel);
				break;
			}
		}
	}
}
void Staff()
{
temp:

	while (true)
	{
		int sel = 1;
		loadingAnimation();
		printStaff(sel);

		char key;
		while (true)
		{
			key = _getch();

			switch (key)
			{
			case 13:
				switch (sel)

				{
				case 1:
					loadingAnimation();
					HumanStaff();
					goto temp;
					break;

				case 2:
					loadingAnimation();
					ProductStaff();
					goto temp;
					break;
				case 3:
					loadingAnimation();
					MaterialsStaff();
					goto temp;
					break;
				case 4:
					loadingAnimation();
					ExportReceiptStaff();
					goto temp;
					break;
				case 5:
					loadingAnimation();
					system("cls");
					return;

				default:
					break;
				}

			case 72:
				sel = (sel == 1) ? 5 : sel - 1;
				printStaff(sel);
				break;

			case 80:
				sel = (sel == 5) ? 5 : sel + 1;
				printStaff(sel);
				break;
			}
		}
	}
}
int main()
{
	string email = "admin@gmail.com", password = "Admin@123";
	string errEmail = "Email is not exist. Please try again!!!";
	string errPassword = "Password is incorrect. Please try again!!!";
	gotoxy(51, 5);
	TextColor(2);
	cout << "HI COFFFE, XIN CHAO";
	gotoxy(43, 7);
	time_t current_time = time(NULL);
	tm *local_time = localtime(&current_time);
	char time_str[40];
	strftime(time_str, sizeof(time_str), "%X, %A, %B %d, %Y", local_time);
	cout << time_str;

	gotoxy(40, 10);
	TextColor(6);
	cout << "Email";
	gotoxy(40, 11);
	cout << "+------------------------------------------+";
	gotoxy(40, 12);
	cout << "| ";
	TextColor(6);
	gotoxy(83, 17);
	cout << "|";
	gotoxy(40, 18);
	cout << "+------------------------------------------+";
	gotoxy(83, 12);
	cout << "|";
	gotoxy(40, 13);
	cout << "+------------------------------------------+";
	gotoxy(40, 15);
	cout << "Password: ";
	gotoxy(40, 16);
	cout << "+------------------------------------------+";
	gotoxy(40, 17);
	cout << "| ";

	gotoxy(55, 20);
	cout << "+-------------+";
	gotoxy(55, 21);
	cout << "|";
	gotoxy(60, 21);
	cout << "LOGIN";
	gotoxy(69, 21);
	cout << "|";

	gotoxy(55, 22);
	cout << "+-------------+";
	TextColor(7);
	while (ds.ValidatePS(email, password) != 1)
	{
		do
		{
			gotoxy(42, 12);
			getline(cin, email);
			fflush(stdin);
			if (ds.ValidatePS(email, password) == -1)
			{
				gotoxy(40, 14);
				TextColor(4);
				cout << errEmail << endl;
				TextColor(7);
				gotoxy(42, 12);
				for (int i = 0; i < email.length(); i++)
				{
					cout << " ";
				}
			}
		} while (ds.ValidatePS(email, password) == -1);
		gotoxy(40, 14);
		for (int i = 0; i < errEmail.length(); i++)
		{
			cout << " ";
		}

		do
		{
			gotoxy(42, 17);
			while (true)
			{
				char ch = _getch();

				if (ch == '\b')
				{
					if (!password.empty())
					{
						password.pop_back();
						cout << "\b \b";
					}
				}
				else if (ch == '\r')
				{
					break;
				}
				else if (ch != '\n')
				{
					password.push_back(ch);
					cout << '*';
				}
			}
			if (ds.ValidatePS(email, password) == 0)
			{
				gotoxy(40, 19);
				TextColor(4);
				cout << errPassword << endl;
				TextColor(7);
				gotoxy(42, 17);
				for (int i = 0; i < password.length(); i++)
				{
					cout << " ";
				}
				gotoxy(22, 17);
				password = "";
			}
		} while (ds.ValidatePS(email, password) == 0);
	}
	gotoxy(40, 19);
	for (int i = 0; i < errPassword.length(); i++)
	{
		cout << " ";
	}
	gotoxy(59, 21);
	while (true)
	{
		char ch = _getch();
		gotoxy(59, 21);
		if (ch == '\b')
		{
			if (!password.empty())
			{
				password.pop_back();
				cout << "\b \b";
			}
		}
		else if (ch == '\r')
		{
			break;
		}
		else if (ch != '\n')
		{
			password.push_back(ch);
		}
	}
	ds.ValidatePS(email, password);
	if (ds.getRole() == "Administrator")
	{
		Administrator();
	}
	else if (ds.getRole() == "Staff")
	{
		Staff();
	}
	gotoxy(35, 11);
	TextColor(2);
	cout << "                 SEE YOU SOON. HAVE A GOOD DAY!";
	gotoxy(0, 25);
	return 0;
}