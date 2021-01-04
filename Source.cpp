#include<iostream>
#include<conio.h>
#include<fstream>
#include<Windows.h>
#include<iomanip>
#include<string.h>
using namespace std;
struct phone2
{
	char name[15];
	char phone[10];
}rec;
void addrec();
void del();
char menu();
void update();
void show();
void search();
char menu()
{
	char ch;
	system("cls");
	cout << "\n--------------------\n";
	cout << "  |enter your choice |\n";
	cout << "\n| 1)add a record   |\n";
	cout << "\n|2)update a record |\n";
	cout << "\n|3)delete a record |\n";
	cout << "\n|4)show a record   |\n";
	cout << "\n|5)search a record |\n";
	cout << "\n|6)exit            |\n";
	cout << "\n--------------------\n";
	cin >> ch;
	return ch;
}
void update()
{
	int n = 0,count=0;
	char pass[20];
	while (n != 4)
	{
		cout << "Enter the password";
		cin >> pass;
		if (strcmp(pass, "agent0047") == 0)
		{
			cout << "Password Is Correct";
			count = 1;
			break;
		}
		else
		{
			cout << "Wrong Password"<<endl;
		}
		n++;
	}
	if (count == 1)
	{
		char num[15];
		int rn = 0, t = 0;
		fstream rrr("C:\\Games\\phone.dat", ios::binary | ios::out|ios::in);
		if (!rrr)
		{
			cout << "File Not Found!!!";
		}
		else
		{
			cout << "Enter the phone number you want to update";
			cin >> num;
			while (rrr.read((char*)&rec, sizeof(rec)))
			{
				if (strcmp(num, rec.phone) == 0)
				{
					Sleep(2000);
					cout << "The name of the user is: " << endl;
					cout << rec.name<<endl;
					cout << "The phone number of the user is:" << endl;
					cout << rec.phone;
					rn = (rn)*sizeof(rec);
					rrr.seekp(rn);
					cout << "Enter the new name: "<<endl;
					cin >> rec.name;
					cout << "Enter the new number: ";
					cin >> rec.phone;
					rrr.write((char*)&rec, sizeof(rec));
					rrr.close();
					t = 1;

				}
				rn++;
			}
			if (t == 0)
			{
				cout << "Record Not Found!!!" << endl;
			}

		}
		
	}
	else
	{
		cout << "You havent put the correct password!!! ";
		return;
	}
	return;
}
void show()
{
	ifstream show;
	show.open("C:\\Games\\phone.dat", ios::binary);
	if (!show)
	{
		cout << "File Not Found!!!";
	}
	else
	{
		cout << "\n---------------------------\n";
		cout << "|   name   | phone number   |\n";
	    cout << "\n---------------------------\n";
		while (show)
		{
			show.read((char*)&rec, sizeof(rec));
			if (!show.eof())
			{
				cout << endl << rec.name << "\t" << rec.phone;
			}
		}
	}
	show.close();
	_getch();
}
void search()
{
	char num[10];
	int found = 0;
	ifstream search;
	search.open("C:\\Games\\phone.dat", ios::binary | ios::out | ios::in);
	if (!search)
	{
		cout << "File Not Found!!!";
	}
	else
	{
		cout << "Enter the number you want to search: " << endl;
		cin >> num;
		cout << " Please wait while searching " << endl;
		search.seekg(0, ios::beg);
		while (search.read((char*)&rec, sizeof(rec)))
		{
			if (strcmp(num, rec.phone) == 0)
			{
				Sleep(2000);
				found = 1;
				cout << "The name of the user is: " << endl;
				cout << rec.name << endl;
				cout << "The phone number of the user is: " << endl;
				cout << rec.phone;

			}
		}
		if (found == 0)
		{
			cout << "Record Not Found!!!";
		}
	}
}
void del()
{
	char num[10];
	int found = 0;
	ifstream del;
	del.open("C:\\Games\\phone.dat", ios::binary );
	ofstream ooo("C:\\Games\\temp.dat", ios::binary);
	
	
	
		cout << "Enter the number you want to delete" << endl;
		cin >> num;
		cout << "Please wait while searching" << endl;
		del.seekg(0, ios::beg);
		while (del.read((char*)&rec, sizeof(rec)))
		{
			if (strcmp(num, rec.phone) == 0)
			{
			
				found = 1;
				cout << "The name of the user is: " << endl;
				cout << rec.name << endl;
				cout << "The phone number of the user is: " << endl;
				cout << rec.phone;
				cout << "\nRecord Deleted.......";
			}
			if (strcmp(num, rec.phone) != 0)
			{
				ooo.write((char*)&rec, sizeof(rec));

			}
		}
		if (found == 0)
		{
			cout << "Record Not Found!!!";
		}
		del.close();
		ooo.close();
		remove("C:\\Games\\phone.dat");
		rename("C:\\Games\\temp.dat", "C:\\Games\\phone.dat");
		
	
	_getch();

	}

int main()
{
	char ch;
	do
	{
		ch = menu();
		switch (ch)
		{
		case '1': 
			addrec();
			break;
		case '2': 
			     update();
			break;
		case '3': 
			del();
			break;
		case '4': 
			show();
			break;
		case '5' :
			search();
				break;
		}
	} while (ch != '6');
	
	_getch();
	return 0;
}

	void addrec()
	{
		char  op;
		ofstream addrec;
		addrec.open("C:\\Games\\phone.dat", ios::binary | ios::app);
		if (!addrec)
		{
			cout << "File Not Found!!!";
		}
		do
		{
			cout << "Enter the name of the owner: " << endl;
			cin >> rec.name;
			cout << "Enter the phone number: ";
			cin >> rec.phone;
			addrec.write((char*)&rec, sizeof(rec));
			cout << "do u want more records[y\\n]";
			op = _getch();
			
		} while (op == 'y' || op == 'Y');
			addrec.close();
	}
