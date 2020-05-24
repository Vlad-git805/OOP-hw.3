#include "PhoneBook.h"

int PhoneBook::size = 0;

PhoneBook::PhoneBook()
{
	size = 0;
}

void PhoneBook::AddContact(const char *_name, const char *_number, const char* _adress)
{
	Info * tempInfo = new Info[size + 1];
	for (int i = 0; i < size; i++)
	{
		tempInfo[i] = info[i];
	}
	strcpy_s(tempInfo[size].name, _name);
	strcpy_s(tempInfo[size].number, _number);
	strcpy_s(tempInfo[size].adress, _adress);
	delete[]info;
	size += 1;
	info = tempInfo;
}

void PhoneBook::DeleteContact(const char *_name) 
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(info[i].name, _name) == 0)
		{
			cnt++;
		}
	}
	Info * tempInf = new Info[size - cnt];
	for (int i = 0, count = 0; i < size; i++)
	{
		if(strcmp(info[i].name, _name) != 0)
		{ 
			tempInf[count] = info[i];
			count++;
		}
	}
	delete[]info;
	size -= cnt;
	info = tempInf;
}

void PhoneBook::FindContactByName(const char *_name)const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(info[i].name, _name) == 0)
		{
			cout << "Name: " << info[i].name << endl;
			cout << "Number: " << info[i].number << endl;
			cout << "Adress: " << info[i].adress << endl;
		}
	}
}

void PhoneBook::FindContactByNumber(const char *_number)const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(info[i].number, _number) == 0)
		{
			cout << "Name: " << info[i].name << endl;
			cout << "Number: " << info[i].number << endl;
			cout << "Adress: " << info[i].adress << endl;
		}
	}
}

void PhoneBook::ShowAllContacts()const
{
	for (int i = 0; i < size; i++)
	{
		cout << "--------------------" << i + 1 << " contact--------------------" << endl;
		cout << "Name: " << info[i].name << endl;
		cout << "Number: " << info[i].number << endl;
		cout << "Adress: " << info[i].adress << endl;
	}
	
}

void PhoneBook::SaveInfo()
{
	ofstream fout;
	fout.open("save");
	bool isOpen_fout = fout.is_open();
	if (isOpen_fout == false)
	{
		cout << " File not open" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			fout << info[i].name << endl;
			fout << info[i].number << endl;
			fout << info[i].adress << endl;
		}
	}
	fout.close();
}

void PhoneBook::Load()
{
	int currentString = 0;
	int currentString2 = 0;
	char data[50];
	ifstream fin;
	fin.open("save");
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			currentString++;
			fin >> data;
		}
		currentString2 = (currentString - 1) / 3;
		currentString = 0;
	}
	fin.close();
	size = currentString2;
	Info *temp = new Info[size];
	int f = 0;
	fin.open("save");
	bool isOpenn = fin.is_open();
	if (isOpenn == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			currentString++;
			fin >> data;
			for (int i = f; i < currentString2;)
			{
				if (currentString == 1)
				{
					strcpy_s(temp[i].name, data);
					break;
				}
				else if (currentString == 2)
				{
					strcpy_s(temp[i].number, data);
					break;
				}
				else if (currentString == 3)
				{
					strcpy_s(temp[i].adress, data);
					currentString = 0;
					f++;
					break;
				}
			}
		}
		delete[]info;
		info = temp;
	}
	fin.close();
}

int PhoneBook::GetCountOfContacts()
{
	return size;
}

PhoneBook::~PhoneBook()
{
	delete[]info;
}
