#include <iostream>
#include<string>
using namespace std;
#include "Account.h"
#include "Customer.h"
#include"bank.h"
int Bank::BankIDGen = 1000;

Bank::Bank() {
	BankIDGen++;
	BankID = BankIDGen;
	name = "";
	address = "";
	telNumber = "";
	NumAccount = 0;
	NumCustomer = 0;
	accFromBank = new Account * [10];// assume size is 10
	cusFromBank = new Customer * [10];//assume size is 10
	for (int i = 0; i < 10; i++) {
		accFromBank[i] = nullptr;
		cusFromBank[i] = nullptr;
	}
}
Bank::Bank(string n, string a, string t) {
	BankIDGen++;
	BankID = BankIDGen;
	name = n;
	address = a;
	telNumber = t;
	NumAccount = 0;
	NumCustomer = 0;
	accFromBank = new Account * [10];// assume size is 10
	cusFromBank = new Customer * [10];//assume size is 10
	for (int i = 0; i < 10; i++) {
		accFromBank[i] = nullptr;
		cusFromBank[i] = nullptr;
	}
}
Bank::Bank(const Bank& b) {
	BankID = b.BankID;
	name = b.name;
	address = b.address;
	telNumber = b.telNumber;
	NumAccount = b.NumAccount;
	NumCustomer = b.NumCustomer;
	accFromBank = new Account*[10];
	cusFromBank = new Customer*[10];
	for (int i = 0; i < 10; i++) {
		accFromBank[i] = b.accFromBank[i];
		cusFromBank[i] = b.cusFromBank[i];
	}
}
Bank::~Bank() {
	delete[]accFromBank;
	delete[]cusFromBank;
}

//getter
int Bank::getBankID()const {
	return BankID;
}
string Bank::getName() const {
	return name;
}
string Bank::getAddress() const {
	return address;
}
string Bank::getTelNumber() const {
	return telNumber;
}

//setter
void Bank::setName(string a) {
	name = a;
}
void Bank::setAddress(string b) {
	address = b;
}
void Bank::setTelNumber(string c) {
	telNumber = c;
}

// add, remove, list, search for Account
void Bank::AddAccount(Account* a) {
	if (NumAccount < 10) {
		if (!SearchAccount(a->getAccountID())) {

			accFromBank[NumAccount] = a;
			NumAccount++;
			return;
		}
		else {
			cout << "This account already exits in the list" << endl;
		}
	}
	else {
		cout << "Limit exceeded " << "Account ID: " << a->getAccountID() << " cannnot be added" << endl;
	}
}
void Bank::RemoveAccount(int ID) {
	for (int i = 0; i < NumAccount; i++) {
		if (accFromBank[i]->getAccountID() == ID) {
			for (int j = i; j < NumAccount - 1; j++) {
				accFromBank[j] = accFromBank[j + 1];
				
			}
			NumAccount--;
			return;
		}
		else {
			cout << " This ID cannot be found in the list" << endl;
		}
	}
}
void Bank::ListAccount() const {
	for (int i = 0; i < NumAccount; i++) {
		accFromBank[i]->print();
		cout << "*************************" << endl;
	}
}
bool Bank::SearchAccount(int ID) {
	for (int i = 0; i < NumAccount; i++) {
		if (accFromBank[i]->getAccountID() == ID) {
			return true;
		}
	}
	return false;
}

// add, remove, list, search for Customer
void Bank::AddCustomer(Customer* c) {
	if (NumCustomer < 10) {
		if (!SearchCustomer(c->getID())) {

			cusFromBank[NumCustomer] = c;
			NumCustomer++;
			return;
		}
		else {
			cout << "This customer already exits in the list" << endl;
		}
	}
	else {
		cout << "Limit exceeded " << "Customer ID: " << c->getID() << " cannnot be added" << endl;
	}
}
void Bank::RemoveCustomer(int ID) {
	for (int i = 0; i < NumCustomer; i++) {
		if (cusFromBank[i]->getID() == ID) {
			for (int j = i; j < NumCustomer - 1; j++) {
				cusFromBank[j] = cusFromBank[j + 1];

			}
			NumCustomer--;
			return;
		}
		else {
			cout << " This Customer cannot be found in the list" << endl;
		}
	}
}
void Bank::ListCustomer() const {
	for (int i = 0; i < NumCustomer; i++) {
		cusFromBank[i]->print();
		cout << "***********************" << endl;
	}
}
bool Bank::SearchCustomer(int ID) {
	for (int i = 0; i < NumCustomer; i++) {
		if (cusFromBank[i]->getID() == ID) {
			return true;
		}
	}
	return false;
}

//print fucntions
void Bank::printSpecificAccount(int ID)const {
	bool notfound = false;
	for (int i = 0; i < NumAccount; i++) {
		if (accFromBank[i]->getAccountID() == ID) {
			accFromBank[i]->print();
			return;
		}
		notfound = true;
	}
	if(notfound)
		cout << "Account ID: " << ID << " cannot be found in the list" << endl;
}
void Bank::printSpecificCustomer(int ID) const {
	bool notfound = false;
	for (int i = 0; i < NumCustomer; i++) {
		if (cusFromBank[i]->getID() == ID) {
			cusFromBank[i]->print();
			return;
		}
		notfound = true;
	}
	if(notfound)
	cout << "Customer ID: "<<ID<<" cannot be found in the list" << endl;
}

void Bank::printBankInfo()const {
	cout << "Bank ID: " << BankID<<endl;
	cout << "Name: " << name << endl;
	cout << "address: " << address << endl;
	cout << "Telephone number: " << telNumber << endl;
	cout << "Number of Account for " << name << " : " << NumAccount << endl;
	cout << "Number of customer for " << name << " : " << NumCustomer << endl;
}