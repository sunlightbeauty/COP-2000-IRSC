/*
COP 2000 - Introduction to Programming
Program: Seabreeze Bank
Written by: Aaliyah Lucien
Created: 06/16/2022, 4: 13 PM
Last modified: 06/21/2022, 5:01 PM

This program allows the user to choose from two different menus, the first which
gives them the option to enter their savings or checking accounts, and the second, 
which allows the user to withdraw or deposit from either account based on the user's selection. 

	(Pseudocode can be found at the end of the program.)
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char dollarSign = '$';
	int MENU1_SELECTION, MENU2_SELECTION;
	double savings_BALANCE, savingsDeposit, savingsWithdrawl, checking_BALANCE, checkingDeposit, checkingWithdrawl;
	
	//Here are the initial balances for the checking and savings accounts.
	savings_BALANCE = 1000.00;
	checking_BALANCE = 2500.00;

	// The main menu items are displayed here.  
	cout << "*********************************************************" << endl;
	cout << "**              Welcome to Seabreeze Bank              **" << endl;
	cout << "*********************************************************" << endl;
	
	do
	{
		cout << endl;
		cout << "1. \t Savings Account \n";
		cout << "2. \t Checking Account \n";
		cout << "3. \t Quit \n";
		cout << endl;

		//The program prompts the user to select a menu item from the main menu here.
		cout << "Please enter a menu item (1-3) --> ";
		cin >> MENU1_SELECTION;
		cout << endl;
		// The input for the main menu validated here.
		
		while (MENU1_SELECTION <= 0 || MENU1_SELECTION > 3)
		{
			cout << "ERROR. PLEASE ENTER A MENU ITEM FROM 1-3. --> ";
			cin >> MENU1_SELECTION;
			cout << endl;
		}
		
		if (MENU1_SELECTION == 1 || MENU1_SELECTION == 2)
		{
			// The submenu items are displayed here.
			cout << "*********************************************************" << endl;
			cout << endl;
			cout << "1. \t Withdrawl \n";
			cout << "2. \t Deposit \n";
			cout << "3. \t Quit \n";
			cout << endl;
			cout << "*********************************************************" << endl;

		}
		else if (MENU1_SELECTION == 3)
		{
			cout << "Thank you for Banking with Seabreeze! \n";
			cout << endl;
		}
		// VALIDATION OVER.

		// Here are the statements that will execute for each main menu selection.
		switch (MENU1_SELECTION)
		{
			// The following statements will execute when the user chooses "1.  Savings Account."
			case 1:
			{
				// Here, the program prompts the user to select a menu item from the submenu.
				cout << "Your savings account balance is " << dollarSign << showpoint << savings_BALANCE << setprecision(2) << fixed << "." << endl;
				cout << "Would you like to withdraw, deposit, or quit? \n";
				cout << "Please enter a menu item (1-3) --> ";
				cin >> MENU2_SELECTION;
				cout << endl;

				// The user's input is being validated with this while loop.
				while (MENU2_SELECTION <= 0 || MENU2_SELECTION > 3)
				{
					// The submenu items are displayed along with the error message here.
					cout << "ERROR. INVALID ENTRY.\n";
					cout << endl;
					cout << "*********************************************************" << endl;
					cout << endl;
					cout << "1. \t Withdrawl \n";
					cout << "2. \t Deposit \n";
					cout << "3. \t Quit \n";
					cout << endl;
					cout << "*********************************************************" << endl;

					cout << "Please enter a menu item from 1 - 3. --> ";
					cin >> MENU2_SELECTION;
					cout << endl;
				}
				// VALIDATION OVER.


				switch (MENU2_SELECTION)
				{
					// The user can choose to withdraw from the savings account here.
					case 1:
					{
						cout << "Enter the amount you would like to withdraw. --> " << dollarSign;
						cin >> savingsWithdrawl;
						cout << endl;

						// The user input is validated here with these while loops.
						while (savingsWithdrawl <= 0)
						{
							cout << "ERROR. Please enter an amount greater than zero that you would like to withdraw. --> " << dollarSign;
							cin >> savingsWithdrawl;
							cout << endl;
						}

						while (savingsWithdrawl > savings_BALANCE)
						{
							cout << "ERROR. Insufficient funds. Please enter a valid amount. --> " << dollarSign;
							cin >> savingsWithdrawl;
							cout << endl;
						}
						// VALIDATION OVER.

						//The withdrawl amount is removed from the savings balance here.
						savings_BALANCE -= savingsWithdrawl;

						cout << "Your current savings balance is " << dollarSign << savings_BALANCE << setprecision(2) << fixed << ". \n";
						cout << endl;
						cout << "************************************************************";
						cout << endl;
						break;
					}
					// The user can choose to deposit into the savings account here.
					case 2:
					{
						cout << "Enter the amount you would like to deposit. --> " << dollarSign;
						cin >> savingsDeposit;
						cout << endl;

						// The user input is validated here.
						while (savingsDeposit <= 0)
						{
							cout << "ERROR. Please enter an amount greater than zero that you would like to withdraw. --> " << dollarSign;
							cin >> savingsDeposit;
							cout << endl;
						}
						// VALIDATION OVER.

						//The deposit is added toward the savings balance here.
						savings_BALANCE += savingsDeposit;

						cout << "Your current savings balance is " << dollarSign << savings_BALANCE << setprecision(2) << fixed << ". \n";
						cout << endl;
						cout << "************************************************************";
						cout << endl;
						break;
					}
					// The following statements execute when the user chooses to quit.
					default:
					{
						if (MENU2_SELECTION == 3)
						{
							cout << "Quitting to main menu... \n";
							cout << endl;
							cout << "************************************************************";
							cout << endl;
						}
						break;
					}
				}
				break;
			}
			// The following statements will execute when the user chooses "2.  Checking Account."
			case 2:
			{
				// Here, the program prompts the user to select a menu item from the submenu.
				cout << "Your checking account balance is " << dollarSign << showpoint << checking_BALANCE << setprecision(2) << fixed << "." << endl;
				cout << "Would you like to withdraw, deposit, or quit? \n";
				cout << "Please enter a menu item (1-3) --> ";
				cin >> MENU2_SELECTION;
				cout << endl;

				// The user's input is being validated with this while loop.
				while (MENU2_SELECTION < 0 || MENU2_SELECTION > 3)
				{
					// The submenu items are displayed along with the error message here.
					cout << "ERROR. INVALID ENTRY.\n";
					cout << endl;
					cout << "*********************************************************" << endl;
					cout << endl;
					cout << "1. \t Withdrawl \n";
					cout << "2. \t Deposit \n";
					cout << "3. \t Quit \n";
					cout << endl;
					cout << "*********************************************************" << endl;

					cout << "Please enter a menu item from 1 - 3. --> ";
					cin >> MENU2_SELECTION;
					cout << endl;
				}
				// VALIDATION OVER.

				switch (MENU2_SELECTION)
				{
					// The user can choose to withdraw from the checking account here.
					case 1:
					{
						cout << "Enter the amount you would like to withdraw. --> " << dollarSign;
						cin >> checkingWithdrawl;
						cout << endl;

						// The user input is validated here.
						while (checkingWithdrawl <= 0)
						{
							cout << "ERROR. Please enter an amount greater than zero that you would like to withdraw. --> " << dollarSign;
							cin >> checkingWithdrawl;
							cout << endl;
						}

						while (checkingWithdrawl > checking_BALANCE)
						{
							cout << "ERROR. Insufficient funds. Please enter a valid amount. --> " << dollarSign;
							cin >> checkingWithdrawl;
							cout << endl;
						}

						// VALIDATION OVER.

						//The withdrawl amount is removed from the checking balance here.
						checking_BALANCE -= checkingWithdrawl;

						cout << "Your current checking balance is " << dollarSign << checking_BALANCE << setprecision(2) << fixed << ". \n";
						cout << endl;
						cout << "************************************************************";
						cout << endl;
						break;
					}
					// The user can choose to deposit into the checking account here.
					case 2:
					{
						cout << "Enter the amount you would like to deposit. --> " << dollarSign;
						cin >> checkingDeposit;
						cout << endl;

						// The user input is validated here.
						while (checkingDeposit <= 0)
						{
							cout << "ERROR. Please enter an amount greater than zero that you would like to withdraw. --> " << dollarSign;
							cin >> checkingDeposit;
							cout << endl;
						}
						// VALIDATION OVER.

						//The deposit is added toward the checking balance here.
						checking_BALANCE += checkingDeposit;

						cout << "Your current checking balance is " << dollarSign << checking_BALANCE << setprecision(2) << fixed << ". \n";
						cout << endl;
						cout << "************************************************************";
						cout << endl;
						break;
					}
					// The following statements execute when the user chooses to quit.
					default:
					{
						if (MENU2_SELECTION == 3)
						{
							cout << "Quitting to main menu... \n";
							cout << endl;
							cout << "************************************************************";
							cout << endl;
						}
						break;
					}
				}
				break;
			}
			// The following statements will execute when the user chooses "3.  Quit."
			default:
			{
				cout << "************************************************************" << endl;
			}
		}
		// THE END.

	} while (MENU1_SELECTION != 3);

	return 0;
}

/*
A.	Define all the following variables in the program: dollarSign (to display the balances in USD), MENU1_SELECTION, MENU2_SELECTION (integers the user can enter as a menu option),
	savings_BALANCE, savingsDeposit, savingsWithdrawl (used to add or remove from savings balance), checking_BALANCE, checkingDeposit, checkingWithdrawl (used to add or remove 
	from checking balance)
B.	Output "Welcome to Seabreeze" header
B.	Repeat the rest of the program until the user quits the main menu (using a do-while loop)
C.	Validate user input: while MENU1_SELECTION is less than or equal to zero and greater than three, output error message, redisplay the menu and prompt user for valid input
D.	If the user inputs "1" or "2," display the second menu; if the user inputs "3" (chooses to quit) output "Thank you for Banking with Seabreeze!"
E.	Prompt user for input and store value in MENU1_SELECTION
	a.	switch case 1 (the user chooses "1. Savings Account"):
		 i.	Display the savings account balance and ask the user to deposit or withdraw
		ii.	Validate user input: while MENU2_SELECTION is less than or equal to zero and greater than three, output error message, redisplay the menu, and prompt user for valid input
	   iii.	Prompt user for input and store value in MENU2_SELECTION
			1. switch case 1 (the user chooses "1. Withdrawl"):
				a.	Prompt the user to enter the amount of money they would like to withdraw. 
				b.	Validate the user input: while the value of savingsWithdrawl is less than or equal to zero, display error message and prompt the user to enter a value 
					greater than zero; while the savingsWithdrawl is greater than savings_BALANCE, display "insuffucuent funds" message and prompt user to reenter an amount
				c.	Calculate the balance after withdrawl
			2.	switch case 2 (the user chooses "2. Deposit"):
				a.	Prompt the user to enter the amount of money they would like to deposit. 
				b.	Validate the user input: while the value of savingsDeposit is less than or equal to zero, display error message and prompt the user to enter a value 
					greater than zero
				c.	Calculate the balance after the deposit
			3.	default (the user chooses "3. Quit"):
				a.	if MENU2_SELECTION is equal to "3," output "Quitting to main menu..."
	b.	switch case 2 (the user chooses "2. Checking Account"):
		 i.	Display the checking account balance and ask the user to deposit or withdraw
		ii.	Validate user input: while MENU2_SELECTION is less than or equal to zero and greater than three, output error message, redisplay the menu, and prompt user for valid input
	   iii.	Prompt user for input and store value in MENU2_SELECTION
			1. switch case 1 (the user chooses "1. Withdrawl"):
				a.	Prompt the user to enter the amount of money they would like to withdraw.
				b.	Validate the user input: while the value of checkingWithdrawl is less than or equal to zero, display error message and prompt the user to enter a value
					greater than zero; while the checkingWithdrawl is greater than checking_BALANCE, display "insuffucuent funds" message and prompt user to reenter an amount
				c.	Calculate the balance after withdrawl
			2.	switch case 2 (the user chooses "2. Deposit"):
				a.	Prompt the user to enter the amount of money they would like to deposit.
				b.	Validate the user input: while the value of checkingDeposit is less than or equal to zero, display error message and prompt the user to enter a value
					greater than zero
				c.	Calculate the balance after the deposit
			3.	default (the user chooses "3. Quit"):
				a.	if MENU2_SELECTION is equal to "3," output "Quitting to main menu..."

*/