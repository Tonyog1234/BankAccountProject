

#include <iostream>
using namespace std;
#include<string>
#include "Account.h"
#include "Customer.h"
#include "Saving.h"
#include "Chequing.h"
#include "CreditCard.h"
#include "Bank.h"
int main()
{
    //Test Saving class
    //Saving object
    Saving* s1 = new Saving(20,4.2, 1000, 0.5);//nTransaction, interest, balance, transactionFee
    Saving* s2 = new Saving(10,3.4, 2000, 1);
    Saving* s3 = new Saving(5,2.5, 1500, 1.2);
    Saving* s4 = new Saving(7, 1.1, 1200, 0.75);//To test setter
    //Customer object
    Customer* c1 = new Customer("Tony", "Kao", "1234 rue bishop", "514-222-3333", "tony09@gmail.com");
    Customer* c2 = new Customer("John", "Longo", "1111 rue Mackay", "514-111-1234", "John@gmail.com");
    Customer* c3 = new Customer("Jeff", "Zhong", "1000 rue Cresent", "426-222-3333", "jeff@gmail.com");
    Customer* c4 = new Customer("Lebron", "James", "1400 rue Font", "514-000-1111", "james@gmail.com");
    s1->setCustomer(c1);//verify Account setter
    c1->AddAccount(s1);//add this account to customer

    s2->setCustomer(c2);
    c2->AddAccount(s2);

    s3->setCustomer(c3);
    c3->AddAccount(s3);

    s4->setCustomer(c4);
    c4->AddAccount(s4);

    s1->print();
    cout << "***************************" << endl;
    s2->print();
    cout << "***************************" << endl;
    s3->print();
    cout << "***************************" << endl;
   
    s4->print();
    cout << "***************************" << endl;
    
    s4->setInterest(2.0);//verify Saving setter
    s4->setTransaction(10);//verify Saving setter
    s4->setBalance(1000);//verify Account setter
    s4->setTransactionFee(0.5);//verify Account setter
    s4->setCustomer(c3);//verify Account setter
    cout << "\nAfter testing setter" << endl;
    s4->print();
    cout << endl;
    cout << "********Test Chequing Class*********" << endl;

    //test Chequing class
    Chequing* ch1 = new Chequing(500, 5000, 0.1);
    Chequing* ch2 = new Chequing(600, 6000, 0.3);
    Chequing* ch3 = new Chequing(700, 7000, 0.2);

    ch1->setCustomer(c1);
    c1->AddAccount(ch1);

    ch2->setCustomer(c2);
    c2->AddAccount(ch1);

    ch3->setCustomer(c3);
    c3->AddAccount(ch1);

    ch1->print();
    cout << "***************************" << endl;
    ch2->print();
    cout << "***************************" << endl;
    ch3->print();
    cout << "***************************" << endl;

    //verify Chequing setter
    ch1->setOverdraft(100);
   
    ch1->setPrivilege(false);
    cout << "\nAfter testing chequing setter" << endl;
    ch1->print();

    cout << "\n********Test CreditCard Class*********" << endl;

    CreditCard* cc1 = new CreditCard(2, 1000, 2.1, 5000, 0.5);
    CreditCard* cc2 = new CreditCard(3, 2000, 2.2, 3000, 0.1);
    CreditCard* cc3 = new CreditCard(4, 3000, 2.3, 4000, 0.2);

    cc1->setCustomer(c4);
    c4->AddAccount(cc1);

    cc2->setCustomer(c1);
    c1->AddAccount(cc2);

    cc3->setCustomer(c2);
    c2->AddAccount(cc3);

    cc1->print();
    cout << "***************************" << endl;
    cc2->print();
    cout << "***************************" << endl;
    cc3->print();
    cout << "***************************" << endl;

    //verify Credit card setter
    cc1->setNumCard(5);
    cc1->setInterest(1.2);
    cc1->setMinPayment(1000.01);

    cout << "\nAfter testing CreditCard setter" << endl;
    cc1->print();
    cout << "***************************" << endl;

    cout << "\n********Test Customer Class*********" << endl;

    cout << "Number of account for customer " <<c1->getFullName()<<": " << c1->getNumAccount() << endl;
    cout << "Number of account for customer " << c2->getFullName() << ": " << c2->getNumAccount() << endl;
    cout << "Number of account for customer " << c3->getFullName() << ": " << c3->getNumAccount() << endl;
    cout << "Number of account for customer " << c4->getFullName() << ": " << c4->getNumAccount() << endl;
    cout << "***************************" << endl;
    c1->ListAccount();
    c1->AddAccount(s1); //won't be able to add, bc s1 already exist in the list

    c1->RemoveAccount(ch1->getAccountID());//chequing account should be removed, Account ID 5
    c1->RemoveAccount(ch3->getAccountID());// won't be found in the list

    cout << "\nAfter testing RemoveAccount()" << endl;
    c1->ListAccount();

    //test listAccount() for other customer object
    c2->ListAccount();
    cout << "***************************" << endl;
    c3->ListAccount();
    cout << "***************************" << endl;
    c4->ListAccount();
    cout << "********Test customer setter*********" << endl;

    //test customer setter
    c1->setAddress("0000 rue sherbrook");
    c1->setEmail("chris@gmail.com");
    c1->setFname("Chris");
    c1->setLname("Paul");
    c1->setTelNumber("514-000-4444");
    c1->print();

    cout << "\n********Test Bank class*********" << endl;
    Bank* b1 = new Bank("BMO", "9876 rue catherine", "426-765-9876");
    Bank* b2 = new Bank("TD", "6453 rue catherine", "111-456-9666");
    Bank* b3 = new Bank("RBC", "1222 rue catherine", "222-765-9876");

    //verify Bank setter
    b1->printBankInfo();
    cout << "***************************" << endl;
    b2->printBankInfo();
    cout << "***************************" << endl;
    b3->printBankInfo();

    b1->setAddress("9999 rue sherbrook");
    b1->setName("Dejardin");
    b1->setTelNumber("555-666-7777");

    cout << "\n********After Test Bank setter*********" << endl;
    b1->printBankInfo();

    //Add account to bank
    cout << "\n********Add account to bank*********" << endl;
    b1->AddAccount(s1);
    b1->AddAccount(s2);
    b1->AddAccount(ch1);
    b1->AddAccount(cc1);

   
    b1->ListAccount();
    b1->AddAccount(s1);//already exits in the list

    //Remoce account from bank
    cout << "\n********Remove account from bank*********" << endl;
    b1->RemoveAccount(ch1->getAccountID());// Chequing account should be removed.
    b1->ListAccount();

    //Add customer to bank
    cout << "\n********Add customer to bank*********" << endl;
    b1->AddCustomer(c1);
    b1->AddCustomer(c2);
    b1->AddCustomer(c3);
    b1->AddCustomer(c4);


    b1->ListCustomer();
    b1->AddCustomer(c1);//already exits in the list

    //Remoce customer from bank
    cout << "\n********Remove customer to bank*********" << endl;
    b1->RemoveCustomer(c1->getID());// customer ID 101 should be removed.
    b1->ListCustomer();

    cout << "\n********Test specific print function*********" << endl;
    b1->printSpecificAccount(s1->getAccountID());
    cout << "***************************" << endl;
    b1->printSpecificAccount(ch1->getAccountID());//can't be found
    cout << "***************************" << endl;
    b1->printSpecificCustomer(c2->getID());
    cout << "***************************" << endl;
    b1->printSpecificCustomer(c1->getID());

    cout << "***************************" << endl;
    b1->printBankInfo();//see number of account and customer the bank has after adding and removing
    
    return 0;
}



