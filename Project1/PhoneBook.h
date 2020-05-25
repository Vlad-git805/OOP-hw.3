#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class PhoneBook
{
private:
	struct Info
	{
		char name[50];
		char number[20];
		char adress[50];
	};
	Info *info;
	static int size;
	bool CheckAvailability(const char *count)const;
	void InfoAboutOneContact(int i)const;
public:
	PhoneBook();
	void AddContact(const char *_name, const char *_number, const char* _adress);
	void ShowAllContacts()const;
	void DeleteContact(const char *_name);
	void FindContactByName(const char *_name)const;
	void FindContactByNumber(const char *_number)const;
	void SaveInfo();
	void Load();
	static int GetCountOfContacts();
	~PhoneBook();
};

