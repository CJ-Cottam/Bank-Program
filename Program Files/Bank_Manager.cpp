#include "Bank_Manager.h"
#include "Customer_Info.h"
int Bank_Manager::Account_Access(Customer_Info List[], int Size_Array, int &x) // This function is used for accessing the accounts 
{
	system("cls");
	cout << "----------Account Access-------" << endl;
	
	for (int i = 0; i < Size_Array; i++)
	{
		cout << "Number " << i << " " << List[i].getCustomer_IDs() << endl;
	}

	cout << "Please enter the which account by number " << endl;
	cin >> x;

	cout << "Please enter the Customers ID." << endl;
	cin >> Customer_ID;
	
	system("cls");
	return Customer_ID, x;
}

int Bank_Manager::Customer_IDs() //Gets the customer ID that we enter and is used in an if statement to check if it's the right one
{
	Customer_ID;
	return Customer_ID;
}


int Bank_Manager::getManagers_Pssword() //This gets the managers password
{
	Mananger_Pssword;
	return Mananger_Pssword;
}


void Bank_Manager::ManagerMen() // Manager main menu
{

	system("cls");
	cout << "Welcome " << BankManager_Name << endl;
	cout << "Bank ID " << Manager_ID << endl;
	cout << "What action would you like to perform?" << endl;
	cout << "1: View account \n2: Reset pin" << endl;
	

}


int Bank_Manager::Pin_Reset() //This function resets the users pin
{
	system("cls");
	
	cout << "Enter new PIN " << endl;
	cin >> PIN;
	return PIN;
}

int Bank_Manager::getCustomers_New_Pin() //Gets the freshly created pin, we made
{
	PIN;
	return PIN;
}