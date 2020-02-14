#include "Customer_Info.h"


void Customer_Info::Account_Setup() //This function is the setup for the account
{
	system("cls");
	
	cout << "Welcome to the Fortune Bank" << endl;
	cout << "Please enter you're name " << endl;
	
	cin >> name;
	cout << "To set up you're account, please create a pin " << endl;
	cin >> PIN;

	Customer_ID = rand() % 10000 + 1;
	system("cls");
}


double Customer_Info::Deposit(double x) //The Deposit function
{
	Balance = Balance + x;
	system("cls");
	
	cout << "You have deposit  " << x << " into you're account."<< endl;
	return Balance;
}

void Customer_Info::getAccount_Details() //Getting the account details
{
	cout << "--------Account Details---------" << endl;
	cout << "Account Name " << name << endl;
	cout << "Balance " << Balance << endl;
	cout << "Account ID " << Customer_ID << endl;
}



int Customer_Info::NewPin(int Update_Pin) //Updating the new pin
{
	PIN = Update_Pin;
	return PIN;
}



int Customer_Info::getPin() //This gets the new npin
{
	PIN;
	return PIN;
}

double Customer_Info::Withdraw(double x) //This is the withdraw function
{

	while (x > Balance)
	{
		if (x > Balance)
		{
			system("cls");
			cout << "Your withdrawing more money than you have please re-enter the value" << endl;
			cin >> x;
		}
	}

	Balance = Balance - x;
	cout << "You've withdrawn " << x << endl;

	return Balance;
}

int Customer_Info::getCustomer_IDs() //Gets the customers id
{
	Customer_ID;
	return Customer_ID;
}

double Customer_Info::getBalance() //Gets the balance
{
	Balance;
	return Balance;
}



double Customer_Info::Withdraw() //Withdraw function for only withdrawing the £10
{
	system("cls");
	Balance = Balance - 10;
	cout << "You've withdrawn " << 10 << endl;

	return Balance;
}


Customer_Info::Customer_Info()
{
	Balance = 0;
	PIN = 0;
	Customer_ID = 0;
}

Customer_Info::~Customer_Info()
{

}

string Customer_Info::getName()
{
	name;
	return name;
}