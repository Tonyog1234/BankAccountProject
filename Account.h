#pragma once
#include <iostream>
using namespace std;
class Customer;

class Account {
protected:
	static int AccountIDGenerator;
	int AccountID;
	double balance, transactionFee;
	Customer *customerFromAccount;

public:
	Account();//default constructor
	Account( double, double, Customer*);//regular constructor // 
	                                          //balance, transactionFee,Customer pointer
	Account(double, double);//regular constructor // balance, transactionFee
	Account(const Account&);// copy constructor
	virtual~Account() {
		delete customerFromAccount;
	}// destuctor

	//getter
	int getAccountID()const;
	double getBalance()const;
	double getTransactionFee()const;
	Customer *getCustomer()const;

	//setter
	//no setter for ID
	void setBalance(double);
	void setTransactionFee(double);
	void setCustomer(Customer*);

	//print function
	virtual void print() const=0;
};