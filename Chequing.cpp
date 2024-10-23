#include <iostream>
#include<string>
using namespace std;
#include "Account.h"
#include "Chequing.h"
#include "Customer.h"

Chequing::Chequing():Account() {
	privilege = true;
	overdraft = 0;

}
Chequing::Chequing(double overdraft, double balance, double fee) :Account(balance, fee){
	privilege = true;
	overdraft = overdraft;
}
Chequing::Chequing(const Chequing& c) {
	privilege = c.privilege;
	overdraft = c.overdraft;
	AccountID = c.AccountID;
	balance = c.balance;
	transactionFee = c.transactionFee;
	customerFromAccount = c.customerFromAccount;
}
Chequing::~Chequing() {
	//nothing
}

//getter
double Chequing::getOverdraft() const {
	return overdraft;
}
string Chequing::getType() const {
	return type;
}

//setter
void Chequing::setOverdraft(double o) {
	overdraft = o;
}
void Chequing::setPrivilege(bool p) {
	privilege = p;
}

//print
void Chequing::print() const {
	cout << "Account type: " << type << endl;
	cout << "Account ID: " << AccountID << endl;
	cout << "Balance: " << balance << endl;
	cout << "Transaction Fee: " << transactionFee << endl;
	cout << "Overdraft limit: " << overdraft << endl;
	if (privilege) {
		cout << "You can write a cheque from this chequing account" << endl;
	}
	else {
		cout << "You are forbidden to write a cheque from this chequing account" << endl;
	}


	cout << "Information about customer who own this chequing account: " << endl;
	customerFromAccount->print();
}