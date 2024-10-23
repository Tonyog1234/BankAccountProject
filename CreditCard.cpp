#include <iostream>
#include<string>
using namespace std;
#include "Account.h"
#include "CreditCard.h"
#include "Customer.h"

CreditCard::CreditCard():Account() {
	NumCard = 0;
	minPayment = 0;
	interest = 0;
}
CreditCard::CreditCard(int num, double min, double i, double balance, double fee):Account(balance, fee) {
	NumCard = num;
	minPayment = min;
	interest = i;

}
CreditCard::CreditCard(const CreditCard& c) {
	NumCard = c.NumCard;
	minPayment = c.minPayment;
	interest = c.interest;

	AccountID = c.AccountID;
	balance = c.balance;
	transactionFee = c.transactionFee;
	customerFromAccount = c.customerFromAccount;
}
CreditCard::~CreditCard() {
	//nothing
}

//getter
int CreditCard::getNumCard()const {
	return NumCard;
}
double CreditCard::getMinPayment() const {
	return minPayment;
}
double CreditCard::getInterest() const {
	return interest;
}

//setter
void CreditCard::setNumCard(int a) {
	NumCard = a;
}
void CreditCard::setMinPayment(double b) {
	minPayment = b;
}
void CreditCard::setInterest(double c) {
	interest = c;
}

//print
void CreditCard::print() const {
	cout << "Account type: " << type << endl;
	cout << "Account ID: " << AccountID << endl;
	cout << "Balance: " << balance << endl;
	cout << "Transaction Fee: " << transactionFee << endl;
	cout << "Number of cards associated with bank: " << NumCard << endl;
	cout << "Minimum payment: " << minPayment << endl;
	cout << "Interest rate: " << interest << endl;
	cout << "Information about customer who own this credit card account: " << endl;
	customerFromAccount->print();
}