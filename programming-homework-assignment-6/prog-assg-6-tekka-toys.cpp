/*
COP 2000 - Introduction to Programming
Program: Tekka Toys
Written by: Aaliyah Lucien
Created: 7/22/2022, 12:28 AM
Last modified: 7/31/2022, 3:05 PM

This program allows users to look for a toy of their choice in the inventory for the Tekka Toys shop.
The inventory is loaded and the user can search for a stuffed or plastic toy of  their choice. 
If the toy the user chose is found, the quantity available will be displayed.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//This function will be used in the sortInput function to swap the array elements in the bubble sort.
void swap(string &toy1st, string &toy2nd)
{
	string temp = toy1st;
	toy1st = toy2nd;
	toy2nd = temp;
}

// This function will be used in the function ckInventory to search for the toy that the user is seeking.
int binSearch(string inventory[10][3], string toyChoice)
{	
	int first = 0; 
	int last = 9;
	int middle;
	int position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (inventory[middle][0] == toyChoice) // If the user choice equal to the middle
		{
			found = true;
			position = middle;
		}
		else if (inventory[middle][0] > toyChoice) // If the middle is in the lower half
			last = middle - 1;
		else // If the middle is in the upper half
			first = middle + 1;
	}
	return position;
}

bool readFile(string inventory[10][3], int inventory2[10][2])
{
	ifstream inputFile, inputFile2;
	inputFile.open("20181_COP2000_inventoryData.txt"); // Opening 20181_COP2000_inventoryData.txt file.
	inputFile2.open("20181_COP2000_inventoryData2.txt"); // Opening 20181_COP2000_inventoryData2.txt file.

	bool SUCCESS = true;

	if (inputFile.fail() || inputFile2.fail())
	{
		SUCCESS = false;
	}
	// Here, the data from 20181_COP2000_inventoryData.txt is being read into the inventory array.
	while (inputFile)
	{
		for (int rowcnt = 0; rowcnt < 10; rowcnt++)
		{
			for (int colcnt = 0; colcnt < 3; colcnt++)
				inputFile >> inventory[rowcnt][colcnt];
		}
	}
	inputFile.close(); // inputFile is closed and the data has been read into inventory.

	// Here, the data from 20181_COP2000_inventoryData2.txt is being read into the inventory2 array.
	while (inputFile2)
	{
		for (int rowcnt = 0; rowcnt < 10; rowcnt++)
		{
			for (int colcnt = 0; colcnt < 2; colcnt++)
				inputFile2 >> inventory2[rowcnt][colcnt];
		}
	}
	inputFile2.close(); // inputFile is closed and the data has been read into inventory.
	
	return SUCCESS;
}

/*
	This function will sort the arrays passed into array parameters inventory and inventory2 and
	output them into two new files, newInventory.txt and newInventory2.txt
*/
void sortInput(string inventory[10][3], int inventory2[10][2])
{
	// The inventory and inventory2 arrays are being sorted.
	for (int start = 0; start < 10; start++)  // Sorting inventory and inventory2 from first to last element
	{
		for (int index = 0; index < 10; index++) // Stepping through arrays from first to last element
		{
			if (inventory[index][0] > inventory[start][0])
			{
				// Swap inventory elements.
				swap(inventory[index][0], inventory[start][0]);
				swap(inventory[index][1], inventory[start][1]);
				swap(inventory[index][2], inventory[start][2]);

				// Swap inventory2 elements.
				swap(inventory2[index][0], inventory2[start][0]);
				swap(inventory2[index][1], inventory2[start][1]);
			}
		}
	}

	// The sorted arrays will be written to two new files: newInventory.txt and newInventory2.txt
	ofstream outFile, outFile2;
	outFile.open("newInventory.txt"); // The newInventory.txt file has been created and opened.
	// Here, the inventory array is being written to the newInventory.txt file.
	for (int rowcnt = 0; rowcnt < 10; rowcnt++)
	{
		for (int colcnt = 0; colcnt < 3; colcnt++)
		{
			outFile << inventory[rowcnt][colcnt] << "\t";
			if ((colcnt + 1) % 3 == 0)
			{
				outFile << endl;
			}
		}
	}
	outFile.close(); // oututFile is closed and the array has been written into newInventory.txt.

	outFile2.open("newInventory2.txt"); // The newInventory.txt file has been created and opened.
	// Here, the inventory array is being written to the newInventory.txt file.
	for (int rowcnt = 0; rowcnt < 10; rowcnt++)
	{
		for (int colcnt = 0; colcnt < 2; colcnt++)
		{
			outFile2 << inventory2[rowcnt][colcnt] << "\t";
			if ((colcnt + 1) % 2 == 0)
			{
				outFile2 << endl;
			}
		}
	}
	outFile2.close(); // oututFile is closed and the array has been written into newInventory.txt.
}

// This function will display the Tekka Toys welcome screen and the toys options menu to the user.
void showMenu(string inventory[10][3])
{
	/*
	Here is the Tekka Toys welcome screen which greets the user and
	instructs them to check the inventory using the menu.
	*/
	cout << " **************************************** " << endl;
	cout << " *" << setw(30) << "Welcome to Tekka Toys" << setw(9) << "*" << endl;
	cout << " *" << setw(32) << "Please follow the menu " << setw(7) << "*" << endl;
	cout << " *" << setw(26) << "below to check " << setw(13) << "*" << endl;
	cout << " *" << setw(27) << "our inventory..." << setw(12) << "*" << endl;
	cout << " **************************************** " << endl;
	cout << endl;

	// The names of the toys are listed with a for loop.
	cout << " We have the following toys: ";
	for (int rowcnt = 0; rowcnt < 9; rowcnt++)
		cout << inventory[rowcnt][0] << ", ";
	cout << inventory[9][0] << "." << endl;
	cout << endl;

	/*
	Here is the main menu in which the user can select the type of toy they would like
	to purchase or to exit the program.
	*/
	cout << "  Please check our inventory if you are interested... " << endl;
	cout << "\t 1. Stuffed Toy \n";
	cout << "\t 2. Plastic Toy \n";
	cout << "\t 3. Exit \n";
	cout << endl;
}

void ckInventory(string inventory[10][3], int inventory2[10][2], int toyType)
{
	string toyChoice;

	cout << " Which toy would you like to check the quantity of? \n";
	cout << " Please type the name in all lowercase letters. --> ";

	cin >> toyChoice;

	if (toyType == 1) // If the user chooses stuffed toys
	{
		int searchResult = binSearch(inventory, toyChoice); // Searching for the toy choice
		cout << endl;
		cout << " The toy you seek is a stuffed " << toyChoice << "... \n";
		if (searchResult == -1 || inventory2[searchResult][0] == 0) // If the toy is not found or is not stuffed
		{
			cout << " Sorry. The toy you entered is not in our inventory. Please try again...\n";
			cout << endl;
		}
		if (inventory[searchResult][1] == "yes")
		{
			cout << " We have " << inventory2[searchResult][0] << " in-stock. \n";
			cout << endl;
		}
	}
	if (toyType == 2) // If the user chooses plastic toys
	{
		int searchResult = binSearch(inventory, toyChoice); 
		cout << endl;
		cout << " The toy you seek is a plastic " << toyChoice << "... \n";
		if (searchResult == -1 || inventory2[searchResult][1] == 0)
		{
			cout << " Sorry. The toy you entered is not in our inventory. Please try again..." << endl;
			cout << endl;
		}
		if (inventory[searchResult][2] == "yes")
		{
			cout << " We have " << inventory2[searchResult][1] << " in-stock. \n";
			cout << endl;
		}
	}
}

int main()
{
	string toyNameType[10][3];
	int toyQty[10][2];
	int MENU_SELECTION;

	readFile(toyNameType, toyQty); // The input file is being read.

	// If the input file is successfully opened and read, continue the program.
	if (readFile(toyNameType, toyQty) == true)
	{
		cout << "THE FILES HAVE BEEN SUCCESSFULLY READ. \n";
		cout << endl;

		sortInput(toyNameType, toyQty); // The data in the input file is being sorted and loaded to a new file.

		do // As long as the user does not exit, the statements with this loop will repeat.
		{
			showMenu(toyNameType); // The welcome screen, list of toys, and the main menu are displayed.

			cout << " --> ";
			cin >> MENU_SELECTION;

			switch (MENU_SELECTION)
			{
				case 1: // The user chooses stuffed toys
				{
					ckInventory(toyNameType, toyQty, MENU_SELECTION);
					break;
				}
				case 2: // The user chooses plastic toys
				{
					ckInventory(toyNameType, toyQty, MENU_SELECTION);
					break;
				}
				case 3:
					break;
				default:
				{
					while (MENU_SELECTION > 3 || MENU_SELECTION < 1)
					{
						cout << "ERROR. PLEASE RE-ENTER AN INTEGER FROM 1 - 3. --> ";
						cin >> MENU_SELECTION;
					}
				}
			}
		} while (MENU_SELECTION != 3);
	}

	// If the input files failed to be opened and read, exit the program. 
	if (readFile(toyNameType, toyQty) == false) 
	{
		cout << "ERROR. THE FILE HAS NOT OPENED OR DOES NOT EXIST.";
	}
	return 0;
}