#include <iostream>
using namespace std;
#include "Account.h"
#include "Customer.h"

int Account::AccountIDGenerator = 0; // ID is unique

Account::Account() {
	AccountIDGenerator++;
	AccountID = AccountIDGenerator;
	balance = 0;
	transactionFee = 0;
	customerFromAccount = nullptr;
}
Account::Account(double balance1, double fee, Customer* p) {
	AccountIDGenerator++;
	AccountID = AccountIDGenerator;
	balance = balance1;
	transactionFee = fee;
	customerFromAccount = p;
}
Account::Account(double balance1, double fee) {
	AccountIDGenerator++;
	AccountID = AccountIDGenerator;
	balance = balance1;
	transactionFee = fee;
	customerFromAccount = nullptr;
}
Account::Account(const Account& original) {
	AccountID = original.AccountID;
	balance = original.balance;
	transactionFee = original.transactionFee;
	customerFromAccount = original.customerFromAccount;
}


//getter
int Account::getAccountID() const{
	return AccountID;
}

double Account::getBalance()const {
	return balance;
}
double Account::getTransactionFee()const {
	return transactionFee;
}
Customer* Account::getCustomer()const {
	return customerFromAccount;
}

//setter

void	Account::setBalance(double b) {
	balance = b;
}
void	Account::setTransactionFee(double fee) {
	transactionFee = fee;
}
void	Account::setCustomer(Customer* ptr) {
	customerFromAccount = ptr;
}


