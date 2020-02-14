#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include "Customer_Info.h"
#include "Bank_Manager.h"
//Cameron Cottam 
//Published 14/02/2020
//GitHub
using namespace std;

double loan = 0; // The loan
double rate = 2.5; // The interest rate
int Num_Payments = 0; // Number of payments
double Total_Loan = 0; // The total loan
double Withdraw = 0; // How much the user wants to withdraw
double Deposit = 0; // How much the user wants to Deposit

int Machine = 1; // The ATM machine
int Pin_Att = 0; // For the pin attempts for the bank manager and Customer


double loans(double &loan, Customer_Info Customer[], int &AccountSelect); // Calculating the loan
double interest(double &rate, int &Num_Payments, double &loan, double &Total_Loan); // The interest


int AccountSelect = 0; // Used for selecitng the accounts
void PrintAccounts(int Size_Array, Customer_Info Customer[]); //Displaying the array list of accounts

int main()
{
	int Size_Array = 0; //Array Size
	Bank_Manager Cameron; //Class object of the manager

	srand(time(0)); // srand for customer ID


	cout << "\t\tWelcome to the Bank Of Fortune City!" << endl;
	cout << "How many accounts would you like?" << endl;
	cin >> Size_Array; // User inputs the size of the array

	Customer_Info* Customer = new Customer_Info[Size_Array]; // Class object of the customer and a pointer array for the user to define the size of the array

	for (int i = 0; i < Size_Array; i++)
	{
		Customer[i].Account_Setup();
	}
	
	//The account setup for the customer
	system("cls");


	while (Machine != 0)
	{
		int BankKeyPad = 0; // Keypad on an ATM

		cout << "Please enter a number to the correct action!" << endl; //Display the UI 
		cout << "1 = Deposit \n2 = View AccountDetails \n3 = Withdraw \n4 = Account Assistance \n5 = Loan \n6 = Calculate Interest \n7 = Withdraw 10 " << endl;
		
		cin >> BankKeyPad;

		if (BankKeyPad == 1)
		{
			system("cls");

			cout << "Which account would you like to despoit?" << endl;
			PrintAccounts(Size_Array, Customer);

			cin >> AccountSelect;
			cout << "How much would you like to deposit? " << endl; // This gets the user to enter how much they would like to deposit which is then passed to the Object function
			cin >> Deposit;
			
			Customer[AccountSelect].Deposit(Deposit); // If the keypad num is 1 it will trigger the Deposit function
		}
		else if (BankKeyPad == 2)
		{
			system("cls");
			
			// Since 2 is the account details, I've added a security measure which asks the user to re-enter their pin
			cout << "Which account? " << endl;
			PrintAccounts(Size_Array, Customer);
			
			cin >> AccountSelect;
		
			cout << "Please confirm you're Pin " << endl;
			cin >> Pin_Att; // Gets the user to enter thier pin
			
			if (Pin_Att == Customer[AccountSelect].getPin()) // This is then checked to see if that pin is equalvant to the one in the object.
			{
				system("cls");
				Customer[AccountSelect].getAccount_Details();
			}
			else
			{
				system("cls");
				cout << "Sorry your pin was rejected" << endl;
			}
		}
		else if (BankKeyPad == 3)
		{
			system("cls");
			cout << "----Withdraw------" << endl;
			PrintAccounts(Size_Array, Customer);
			
			cout << "Which account? " << endl;
			cin >> AccountSelect;
			
			cout << "How much would you like to withdraw? " << endl; // This gets the user to enter how much they would like to withdraw which is then passed to the Object function
			cin >> Withdraw;
			
			Customer[AccountSelect].Withdraw(Withdraw);
		}
		else if (BankKeyPad == 4)
		{ //This section is for the bank manager assistance
			//Firstly gets the manager to enter their password before accessing his featrues
			system("cls");
			
			cout << "---------Manager Settings------" << endl;
			cout << "Could the Bank Manager input his Pssword" << endl;
			
			cin >> Pin_Att;

			if (Cameron.getManagers_Pssword() == Pin_Att)
			{
				Cameron.ManagerMen(); // This brings up the managers menu
				cin >> BankKeyPad;
				if (BankKeyPad == 1)
				{
					Cameron.Account_Access(Customer, Size_Array, AccountSelect); //This function has the manager selecting/enter a customer ID
					if (Cameron.Customer_IDs() == Customer[AccountSelect].getCustomer_IDs())
					{
						Customer[AccountSelect].getAccount_Details(); // If the ID matches, it is then moved onto the Customer account details
					}
					else
					{
						system("cls");
						cout << "Incorrect Account information" << endl;
					}
				}
				else if (BankKeyPad == 2)
				{
					//This section has the manager resetting the customers pin
					Cameron.Pin_Reset();
					PrintAccounts(Size_Array, Customer);

					cout << "Which account " << endl;
					cin >> AccountSelect;

					Customer[AccountSelect].NewPin(Cameron.getCustomers_New_Pin());
					cout << "The new pin for account: " << Customer[AccountSelect].getName() << " is " << Customer[AccountSelect].getPin() << endl;
				}
			}
			else
			{
				system("cls");
				cout << "Incorrect password" << endl;
			}
		}
		else if (BankKeyPad == 5)
		{
			system("cls");
			cout << "---------Loans-------" << endl;
			
			PrintAccounts(Size_Array, Customer);
			
			cout << "Which account?" << endl;
			cin >> AccountSelect;
			
			loans(loan, &Customer[AccountSelect], AccountSelect); // The loan function
		}
		else if (BankKeyPad == 6)
		{
			interest(rate, Num_Payments, loan, Total_Loan); // Interest function
		}
		else if (BankKeyPad == 7)
		{
			system("cls");
			cout << "-------Withdraw 10 --------" << endl;
			
			PrintAccounts(Size_Array, Customer);
			
			//This is the fast track option to withdraw £10 automatically through overloading
			cout << "Which account?" << endl;
			
			cin >> AccountSelect;
			
			Customer[AccountSelect].Withdraw();
		}
		else if (BankKeyPad == 8)
		{
			Machine = 0;
			system("cls");
			cout << "Goodbye :)" << endl;
			for (int i = 0; i < Size_Array; i++)
			{
				delete Customer;
			}
		}

	}

}


double loans(double &loan, Customer_Info Customer[], int &AccountSelect) // The loan function passes in the Customer object and the loan value
{
	// We get the user to enter how much they would like to loan as well as displaying the max they can loan up to.
	cout << "How much to loan? \nThis is how much you can loan " << Customer[0].getBalance() * 2 << endl;
	cin >> loan;
	
	if (loan > (Customer[AccountSelect].getBalance() * 2) || Customer[AccountSelect].getBalance() == 0) //If the loan is larger than the max or equal to 0 it is rejected
	{
		system("cls");
		cout << "Sorry you're loan is denied because it is more than doubled you're balance" << endl;
		loan = 0;
	}
	else //Otherwise it's accepted
	{
		system("cls");
		cout << "Loan accepted " << endl;
	}

	//This is the fast track option to withdraw £10 automatically through overloading
	cout << "Loan: " << loan << endl;
	return loan;
}

double interest(double &rate, int &Num_Payments, double &loan, double &Total_Loan)
{
	system("cls");
	double interest_ = 0;
	
	//We ask the user to enter the number of payments they would like  to pay in. So, 1 is for 12 month plan and 2 is for a 6 month plan.
	cout << "How many payments do you want to make? \n1 for 12 \n2 for 6 " << endl;
	cin >> Num_Payments;
	
	if (Num_Payments == 1)
	{
		//We calculate the interest by dividing the rate by the month and multiplying it by the loan
		interest_ = (rate / 12) * loan;
		Total_Loan = interest_ + loan;
	}
	else
	{
		interest_ = (rate / 6) * loan;
		Total_Loan = interest_ + loan;
	}
	
	system("cls");
	
	//Displays the total loan.
	cout << "So the interest alone is " << interest_ << endl;
	cout << "Total loan: " << Total_Loan << endl;
	return Total_Loan;
}


void PrintAccounts(int Size_Array, Customer_Info Customer[]) // Displaying the Accounts
{
	for (int i = 0; i < Size_Array; i++)
	{
		cout << "Account " << i << ": " << Customer[i].getName() << endl;
	}
}