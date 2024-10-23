#include <iostream>
#include<string>
using namespace std;
#include "Account.h"
#include "Saving.h"
#include "Customer.h"


Saving::Saving() :Account(){
	interestRate = 0;
	nTransaction = 0;
}
Saving::Saving( int t,double interest, double balance, double fee):Account(balance, fee) {
	nTransaction = t;
	interestRate = interest;
	
}
Saving::Saving(const Saving& original) {
	nTransaction = original.nTransaction;
	interestRate = original.interestRate;
	nTransaction = original.nTransaction;
	AccountID = original.AccountID;
	balance = original.balance;
	transactionFee = original.transactionFee;
	customerFromAccount = original.customerFromAccount;
}
Saving::~Saving() {
	//do nothing
}

//getter
int Saving::getNumtransaction() const{
	return nTransaction;
}
double Saving::getInterestRate() const {
	return interestRate;
}
string Saving::getType()const {
	return type;
}
//setter
void Saving::setTransaction(int a) {
	nTransaction = a;
}
void Saving::setInterest(double i) {
	interestRate = i;
}
void Saving::print() const {
	cout <<"Account type: " << type << endl;
	cout << "Account ID: " << AccountID << endl;
	cout << "Balance: " << balance << endl;
	cout << "Transaction Fee: " << transactionFee << endl;
	cout << "Maximum number of transaction: " << nTransaction << endl;
	cout << "Interest rate: " << interestRate << endl;
	cout << "Information about customer who own this saving account: " << endl;
	customerFromAccount->print();
}