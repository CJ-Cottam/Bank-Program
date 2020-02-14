#pragma once
#include <string>
#include <iostream>
#include "Customer_Info.h"
using namespace std;
class Bank_Manager: 
	public Customer_Info
{
private:
	int Customer_ID; // For getting the customers ID
	int PIN; // Their pin
	string BankManager_Name = "Cameron"; //The managers name
	int Manager_ID = 1345; //Managers ID
	int Mananger_Pssword = 212; //Managers Password

public:
	void ManagerMen(); //Manager main menu
	int Account_Access(Customer_Info List[], int Size_Array, int &x); //Function for getting access to the customers account
	int Pin_Reset(); //Function for resetting the PIN
	int getManagers_Pssword(); //Gets the managers pin
	int getCustomers_New_Pin(); //Assigns the newly created pin to the users pin
	int Customer_IDs();
};

