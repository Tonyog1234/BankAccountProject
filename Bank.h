#pragma once
#include <iostream>
#include<string>
using namespace std;
#include "Account.h"
#include "Customer.h"

class Bank {
private:
	static int BankIDGen;
	int BankID;
	string name,address, telNumber;
	int NumAccount, NumCustomer;
	Account** accFromBank;
	Customer** cusFromBank;
public:
	Bank();
	Bank(string, string, string);
	Bank(const Bank&);
	~Bank();

	//getter
	int getBankID()const;
	string getName() const;
	string getAddress() const;
	string getTelNumber() const;

	//setter except for bankID
	void setName(string);
	void setAddress(string);
	void setTelNumber(string);

	// add, remove, list, search for Account
	void AddAccount( Account*);
	void RemoveAccount(int);//pass ID
	void ListAccount() const;
	bool SearchAccount(int);//pass ID

	// add, remove, list, search for Customer
	void AddCustomer(Customer*);
	void RemoveCustomer(int);
	void ListCustomer() const;
	bool SearchCustomer(int);

	//print fucntions
	void printSpecificAccount(int)const;
	void printSpecificCustomer(int) const;

	void printBankInfo()const;
};