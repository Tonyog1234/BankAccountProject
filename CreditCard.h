#pragma once
#include <iostream>
#include<string>
using namespace std;
#include "Account.h"
class Customer;

class CreditCard:public Account {
private:
	string type = "Credit Card Account";
	int NumCard;
	double minPayment, interest;
public:
	CreditCard();
	CreditCard(int, double, double, double, double);
	CreditCard(const CreditCard&);
	~CreditCard();

	//getter
	int getNumCard()const;
	double getMinPayment() const;
	double getInterest() const;

	//setter
	void setNumCard(int);
	void setMinPayment(double);
	void setInterest(double);

	//print
	void print() const;



};