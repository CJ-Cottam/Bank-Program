#pragma once
#include <iostream>
#include <string>
using namespace std;


class Customer_Info
{
private:
	string name; //Customer's name
	int Customer_ID; ; //Customer's ID
	double Balance;  //Customer's Balance
	int PIN; ; //Customer's PIN

public:
	Customer_Info();
	~Customer_Info();
	int getPin(); //Function for retreving the user's PIN
	void Account_Setup(); //Their account setup which is activated at the beginning of the program
	double Deposit(double x); //Function for depositing money
	double Withdraw(double x); //Function for withdrawing money
	void getAccount_Details(); //Function for getting the users details, so customer ID & balance;
	int getCustomer_IDs(); //Function for retreving the user's ID
	int NewPin(int Update_Pin);  //Function for resetting the PIN
	double getBalance(); //Function for retreving the user's balance
	double Withdraw();//The £10 withdraw option
	string getName();
};