#pragma once
#include <iostream>
#include<string>
using namespace std;
#include "Account.h"
class Customer;

class Chequing : public Account {
private:
	bool privilege;
	double overdraft;
	string type = "Chequing Account";
public:
	Chequing();//default constructor
	Chequing(double, double, double);//regular constructor // overdraft, balance, transactionFee
	Chequing(const Chequing&);
	~Chequing();//destructor

	//getter
	double getOverdraft() const;
	string getType() const;

	//setter
	void setOverdraft(double);
	void setPrivilege(bool);

	//print
	void print() const;

};