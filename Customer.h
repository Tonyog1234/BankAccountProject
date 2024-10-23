#pragma once
#include <iostream>
#include <string>
using namespace std;
class Account;//forward declaration
class Saving;
class Chequing;
class CreditCard;

class Customer {
private:
	static int customerIDGen;
	int customerID;
	int NumAccount;
	string fname, lname, address, telNumber, email;
	Account** acc;
public:
	Customer();//default constructor
	Customer(string, string, string, string, string);//regular constructor
	Customer(const Customer&);//copy constructor
	~Customer();//destructor

	//getter
	int getID()const;
	int getNumAccount()const;
	string getFname()const;
	string getLname()const;
	string getAddress()const;
	string getTelNumber()const;
	string getEmail()const;
	string getFullName()const;
	//setter
	
	void setFname(string);
	void setLname(string);
	void setAddress(string);
	void setTelNumber(string);
	void setEmail(string);

	void AddAccount( Account*);//ask prof why I can't put const
	void RemoveAccount(int);//pass account ID
	void ListAccount();
	bool SearchAccount(int);//check account ID

	//print
	void print() const;
};