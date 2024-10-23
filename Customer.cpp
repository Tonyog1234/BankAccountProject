
#include <iostream>
#include <string>
using namespace std;
#include"Account.h"
#include"Customer.h"
#include "Saving.h"
#include "Chequing.h"
#include "CreditCard.h"
int Customer::customerIDGen = 100;

Customer::Customer() {
	customerIDGen++;
	customerID = customerIDGen;
	fname = "";
	lname = "";
	address = "";
	telNumber = "";
	email = "";
	NumAccount = 0;
	acc = new Account * [10];
	for (int i = 0; i < 10; i++) {
		acc[i] = nullptr;
	}
}
Customer::Customer (string fname1, string lname1, string a, string tellphone, string e) {
	customerIDGen++;
	customerID=customerIDGen;
	fname = fname1;
	lname = lname1;
	address = a;
	telNumber = tellphone;
	email = e;
	NumAccount = 0;
	acc = new Account * [10];//assume size 0f 10
	for (int i = 0; i < 10; i++) {
		acc[i] = nullptr;
	}
}
Customer::Customer(const Customer& c) {
	customerID = c.customerID;
	fname = c.fname;
	lname = c.lname;
	address = c.address;
	telNumber = c.telNumber;
	email = c.email;
	NumAccount = c.NumAccount;
	acc = new Account *[10];
	for (int i = 0; i < NumAccount; i++) {
		acc[i] = c.acc[i];
	}
}
Customer::~Customer() {
	delete[]acc;
}

	//getter
int Customer::getID()const {
	return customerID;
}
int Customer::getNumAccount()const {
	return NumAccount;
}
string Customer::getFname()const {
	return fname;
}
string Customer::getLname()const {
	return lname;
}
string Customer::getAddress()const {
	return address;
}
string Customer::getTelNumber()const {
	return telNumber;
}
string Customer::getEmail()const {
	return email;
}
string Customer::getFullName()const {
	return fname + " " + lname+" ";
}
	//setter

void Customer::setFname(string first) {
	fname = first;
}
void Customer::setLname(string  last) {
	lname = last;
}
void Customer::setAddress(string a) {
	address = a;
}
void Customer::setTelNumber(string tel) {
	telNumber = tel;
}
void Customer::setEmail(string e) {
	email = e;
}

/// add, remove ,list
void Customer::AddAccount( Account* a) {
	if (NumAccount < 10) {
		if (!SearchAccount(a->getAccountID())) {
			acc[NumAccount] = a;
			NumAccount++;
			return;
		}
		else {
			cout << "Account already exits on the list" << endl;
		}

	}
	else {
		cout << "Limit exceeded, Account ID: " << a->getAccountID() << " can't be added" << endl;
	}
}
void Customer::RemoveAccount(int ID) {
	for (int i = 0; i < NumAccount; i++) {
		if (acc[i]->getAccountID() == ID) {
			for (int j = i; j < NumAccount - 1; j++) {
				acc[j] = acc[j + 1];
			}
			NumAccount--;
			return;
		}
	}
	cout << "Account ID: " << ID << " cannnot be found" << endl;
}
void Customer::ListAccount() {
	cout << "List of account for customer: " << getFullName() << endl;
	for (int i = 0; i < NumAccount; i++) {
		
		acc[i]->print();
		cout << "****************************" << endl;
	} 
}
bool Customer::SearchAccount(int ID) {
	for (int i = 0; i < NumAccount; i++) {
		if (acc[i]->getAccountID() == ID) {
			return true;
		}
	}
	return false;
}
void Customer::print() const {
	
	cout << "Customer ID: " << customerID << endl;
	cout << "Name: " << fname << " " << lname << endl;
	cout << "Address: " << address << endl;
	cout << "Telephone number: " << telNumber << endl;
	cout << "Email: " << email << endl;
}