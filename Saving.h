#pragma once
#include <iostream>
#include<string>
using namespace std;
#include "Account.h"
class Customer;

class Saving : public Account {
private:
	int nTransaction;
	double interestRate;
	string type = "Saving account";
public:
	Saving();//default constructor
	Saving(int,double, double ,double);//regualr constructor //interest, balance , transactionFee
	Saving(const Saving&);//copy constructor
	~Saving();//destructor

	//getter
	int getNumtransaction()const;
	double getInterestRate()const;
	string getType()const;
	//setter
	void setTransaction(int);
	void setInterest(double);

	//print
	 void print() const;
};