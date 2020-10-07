#include"My_library_Bank_ATM.h";

void main()
{

	AccountInfo tabClients[200];
	short NbClients;
	short index, choice;
	   
	do
	{
		DisplayTitle("Banque Royale", "Automatic Banking Machine");
		NbClients=ReadAllAccounts(tabClients);
		//NbClients=ReadNbClients();
		index = CheckClient(tabClients, NbClients);
		DisplayMenu();
		choice = ReadChoice();
		
		switch (choice)
		{
		case 1:

			AddDeposit(tabClients, index, ReadAmount("deposited", 2, 20000));
			DisplayAccountInfo(tabClients, index);
			break;

		case 2:

			WithdrawAmount(tabClients, index, ReadAmount("withdrawn", 20, 500));
		    DisplayAccountInfo(tabClients, index);
			break;
		
		case 3:

			DisplayAccountInfo(tabClients, index);
			break;
		}
		
		ReWriteTextFile(tabClients, NbClients);
		DisplayText("Thank you for using our service");
		system("pause");

	} while ((choice == 1)||(choice == 2)||(choice == 3));

}