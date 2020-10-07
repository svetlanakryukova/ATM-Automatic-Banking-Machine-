#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/* Declaration the Structure */

struct AccountInfo 
{
	char AccountNumber[6];
	string Name;
	char Pin[20];
	int Balance;
};

/* function for storing file contents in an array of accounting structures. it returns the size of the array */

short ReadAllAccounts(AccountInfo tabAccounts[]) 
{
	fstream myFile;
	myFile.open("Bank_ATM_Base.txt", ios::in);

	short i = 0, nbclient;

	while (!myFile.eof())
	{
		
		myFile.getline(tabAccounts[i].AccountNumber,6);
		getline(myFile, tabAccounts[i].Name);
		myFile.getline(tabAccounts[i].Pin,20);
		myFile >> tabAccounts[i].Balance;
		myFile.ignore();
		i++;
	}
	
	nbclient = i;
	myFile.close();

	return nbclient;

}

/*function to display title*/

void DisplayTitle(string title1, string title2) 
{
	system("cls");
	cout << "\t\t";
	for (short i = 0; i < title1.length(); i++)
	{
		cout << (char)toupper(title1[i]);
	}

	cout << "\n\t\t";
	for (short i = 0; i < title1.length(); i++)
	{
		cout << "-";
	}

	cout << "\n\t";
	for (short i = 0; i < title2.length(); i++)
	{
		cout << (char)toupper(title2[i]);
	}

	cout << "\n\t";
	for (short i = 0; i < title2.length(); i++)
	{
		cout << "-";
	}
	cout << "\n\n";
}


/*function for Display the found client name*/

void DisplayNameClient(AccountInfo tabClients[], short index) 
{
	cout << "\n\tWelcome " << tabClients[index].Name << endl;
}


/*function for password verification */

void CheckPin(AccountInfo tabClients[], short index) 
{
	char Pin[20];
	short j = 0;
	do
	{
		cout << "Enter your pin : ";
		cin >> Pin;

		if (strcmp(tabClients[index].Pin, Pin)==0)
		{
			j = 1;
		}

	} while (j == 0);

}


/*function for display main menu*/

void DisplayMenu() 
{
	cout << "\nChoose your Transaction\n";
	cout << "\t1 - For Deposit\n";
	cout << "\t2 - For Withdrawal\n";
	cout << "\t3 - For Consultation\n";
}


/*function for display any text*/

void DisplayText(string text) 
{
	cout << "\n" << text << "\n" << endl;
}


/*function for search a client in an array*/

short CheckClient(AccountInfo tabClients[], short NbClients) 
{
	short j = 0, index;
	char  AccountNb[6];

	do
	{
		cout << "Enter your account number : ";
		cin >> AccountNb;

		for (short i = 0; i < NbClients; i++)
		{
			if (strcmp(tabClients[i].AccountNumber,AccountNb)==0) /* check Account Number of client in array*/
			{
				j = 1;
				index = i; 
				DisplayNameClient(tabClients, index);
				CheckPin(tabClients, index);
				continue;
			}

		}

	} while (j != 1); /*if the client is not found in the array, re-request the account number */

	return index; /* index of client in array*/

}


/*function to read the transaction number*/

short ReadChoice() 
{
	short tmp;
	do
	{
		cout << "Enter your choice (1-3) : ";
		cin >> tmp;

	} while (tmp < 1 || tmp>3);

	return tmp;
}


/*function for reading the amount entered by the client*/

int ReadAmount(string text, short min, short max) 
{
	int amount;
	do
	{
		cout << "\nEnter the amount that will be " << text << " $  : ";
		cin >> amount;

	} while (amount<min || amount>max);

	return amount;
}


/*function to Deposit the balance of a bank client*/

void AddDeposit(AccountInfo tabClients[], short index, int amount) 
{

	tabClients[index].Balance = tabClients[index].Balance + amount;
	DisplayText("--- the transaction has been completed successful ---");
		
}


/*function for withdrawing cash from a bank client’s account*/

void WithdrawAmount(AccountInfo tabClients[], short index, int amount) 
{
	if ((amount % 20 == 0) && (tabClients[index].Balance > amount))
	{
		tabClients[index].Balance = tabClients[index].Balance - amount;
		DisplayText("--- the transaction has been completed successful ---");
		
	}
	else
	{
		DisplayText("--- the transaction has been declined ---");
	
	}

}


/*function for displaying information about the bank's client*/

void DisplayAccountInfo(AccountInfo tabClients[], short index) 
{
	cout << "Account information"<< endl;
	cout << "\tAccountNumber : " << tabClients[index].AccountNumber << endl;
	cout << "\tClient        : " << tabClients[index].Name << endl;
	cout << "\tPIN           : " << tabClients[index].Pin << endl;
	cout << "\tBalance       : " << tabClients[index].Balance << endl;
}


/*function to save an array to a text file*/

void ReWriteTextFile(AccountInfo tabClients[], short Nb) 
{
	fstream myFile;
	myFile.open("Bank_ATM_Base.txt", ios::out | ios::trunc);
	
	for (short i = 0; i < Nb-1; i++)
	{
		myFile << tabClients[i].AccountNumber << endl;
		myFile << tabClients[i].Name << endl;
		myFile << tabClients[i].Pin << endl;
		myFile <<tabClients[i].Balance << endl;
	}
	myFile.close();
}

