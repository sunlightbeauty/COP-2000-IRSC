/*
COP 2000 — Introduction to Programming
Program: Gunter's Mountain Shop
Written by: Aaliyah Lucien
Created: 06/06/2022, 4:20 PM
Last modified: 06/08/2022, 9:53 AM

This program gives allows the user to purchase items at Gunter's Mountain Shop. 
The user can select from the menu and choose to purchase items from the main facility or the outlet store.
The cost of each item, the total sale price, and the tax will be calculated.
The user will also be given a student discount if they are eligible.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Here is the logo for Gunter's Mountain Shop.
	cout << "***************************************************" << "\n";
	cout << "**           //\\                                 **" << "\n";
	cout << "**          //  \\  //\\                           **" << "\n";
	cout << "**         //    \\//  \\        //\\               **" << "\n";
	cout << "**        //           \\      //  \\              **" << "\n";
	cout << "**       //             \\    //    \\             **" << "\n";
	cout << "**      //               \\  //      \\            **" << "\n";
	cout << "**     //                 \\//        \\           **" << "\n";
	cout << "**    //                              \\          **" << "\n";
	cout << "**   //                                \\         **" << "\n";
	cout << "***************************************************" << "\n";
	cout << "**       Welcome to Gunter's Mountain Shop       **" << "\n";
	cout << "***************************************************" << "\n";
	cout << endl;

	char dollarSign = '$';

	// Here are the variables for prices of the items at the outlet store.
	double boots, pullovers, gaiters, cleats, sleepingBag;

	boots = 59.99;
	pullovers = 10.50;
	gaiters = 12.25;
	cleats = 14.99;
	sleepingBag = 30.00;

	// Here are the variables for prices of the items at the main facility.
	double stove, spraywipes, magLite, firstaid, afterBite;

	stove = 129.99;
	spraywipes = 11.50;
	magLite = 5.99;
	firstaid = 14.99;
	afterBite = 3.99;

	// Here is the menu.
	int MENU_SELECTION;

	cout << "1." << "\t" << "Shop the Outlet Store in Kenosha" << "\n";
	cout << "2." << "\t" << "Shop the Main Store in Waukesha" << "\n";
	cout << "3." << "\t" << "Quit" << "\n";
	cout << endl;

	cout << "Please enter a menu item (1 - 3) ---> ";
	cin >> MENU_SELECTION;
	cout << endl;

	// Here are the expressions that will execute when the user inputs an option.
	switch (MENU_SELECTION)
	{
		// Here are the names, prices, calculations, purchases, and discount for the outlet store items. 
		case 1:
			int boots_qty, pullovers_qty, gaiters_qty, cleats_qty, sleepingBag_qty;

			// Here, the user will be asked to input the number of each item they would like to purchase.
			cout << "How many pairs of Hunter Climbing Boots would you like to purchase? --> ";
			cin >> boots_qty;
				if (boots_qty < 0)
				{
					boots_qty = 0;
					cout << "Invalid input entered...quantity set to zero..." << "\n";
				}
			cout << endl;

			cout << "How many Fleece Pullovers would you like to purchase? --> ";
			cin >> pullovers_qty;
				if (pullovers_qty < 0)
				{
					pullovers_qty = 0;
					cout << "Invalid input entered...Value set to zero..." << "\n";
				}
			cout << endl;

			cout << "How many Snow Gaiters would you like to purchase? --> ";
			cin >> gaiters_qty;
				if (gaiters_qty < 0)
				{
					gaiters_qty = 0;
					cout << "Invalid input entered...Value set to zero..." << "\n";
				}
			cout << endl;

			cout << "How many pairs of Traction Cleats would you like to purchase? --> ";
			cin >> cleats_qty;
				if (cleats_qty < 0)
				{
					cleats_qty = 0;
					cout << "Invalid input entered...Value set to zero...";
				}
			cout << endl;

			cout << "How many Sleeping Bags would you like to purchase? --> ";
			cin >> sleepingBag_qty;
				if (sleepingBag_qty < 0)
				{
					sleepingBag_qty = 0;
					cout << "Invalid input entered...Value set to zero..." << "\n";
				}
			cout << endl;


			cout << "********************************************************************************" << endl;
			cout << endl;
			
			// Here are the variables for the cost of each item. The sales prices as well as the total sale price with tax are calculated. 
			double boots_sale, pullovers_sale, gaiters_sale, cleats_sale, sleepingBag_sale, totalSale1, tax1, taxSale1;

			boots_sale = boots * boots_qty;
			pullovers_sale = pullovers * pullovers_qty;
			gaiters_sale = gaiters * gaiters_qty;
			cleats_sale = cleats * cleats_qty;
			sleepingBag_sale = sleepingBag * sleepingBag_qty;
			
			totalSale1 = boots_sale + pullovers_sale + gaiters_sale + cleats_sale + sleepingBag_sale;
			tax1 = totalSale1 * 0.07;
			taxSale1 = totalSale1 + tax1;

			// The item names and prices and the total sale price are listed here.
			cout << "Gunter's Outlet Items" << setw(50) << "Sale Price" << "\n";
			
			cout << "Hunter Climbing Boots" << setw(6) << dollarSign << setprecision(4) << boots << fixed;
			cout << setw(36) << "Total: " << dollarSign <<setprecision(2) << boots_sale << fixed << endl;
			
			cout << "Fleece Pullovers" << setw(11) << dollarSign << setprecision(2) << pullovers << fixed;
			cout << setw(36) << "Total: " << dollarSign << setprecision(2) << pullovers_sale << fixed << endl;

			cout << "Snow Gaiters" << setw(15) << dollarSign << setprecision(2) << gaiters << fixed;
			cout << setw(36) << "Total: " << dollarSign << setprecision(2) << gaiters_sale << fixed << endl;
			
			cout << "Traction Cleats" << setw(12) << dollarSign << setprecision(2) << cleats << fixed;
			cout << setw(36) << "Total: " << dollarSign << setprecision(2) << cleats_sale << fixed << endl;
			
			cout << "Sleeping Bags" << setw(14) << dollarSign << setprecision(2) << sleepingBag << fixed;
			cout << setw(36) << "Total: " << dollarSign << setprecision(2) << sleepingBag_sale << fixed << endl;
			
			cout << endl;
			cout << "********************************************************************************" << endl;
			cout << endl;

			cout << "TAX: " << dollarSign << setprecision(2) << tax1 << fixed;
			cout << setw(20) << "TOTAL: " << dollarSign << setprecision(2) << totalSale1 << fixed;
			cout << setw(20) << "TOTAL + TAX: " << dollarSign << setprecision(2) << taxSale1 << fixed << endl;
			cout << endl;

			// Here, the user will be asked if they are a student to check their eligibility for the student discount.
			char answer1;

			cout << "Are you a student? Enter Y (Yes) or N (No) --> ";
			cin >> answer1;
			cout << endl;
				if (answer1 == 'Y' || answer1 == 'y')
				{
					double discount1 = taxSale1 * 0.1;
					double discSale1 = taxSale1 - discount1;

					cout << "You are eligible for our 10% student discount!!" << "\n";
					cout << "DISCOUNT: " << dollarSign << setprecision(2) << discount1 << fixed;
					cout << setw(15) << "TOTAL: " << dollarSign << setprecision(2) << taxSale1 << fixed;
					cout << setw(25) << "TOTAL + DISCOUNT: " << dollarSign << setprecision(2) << discSale1 << fixed << endl;
					cout << endl;
					cout << "Thank you for shopping at Gunter's Mountain Shop!" << endl;
					cout << endl;
					cout << "********************************************************************************" << endl;
				}
				else if (answer1 == 'N' || answer1 == 'n')
				{
					cout << "Sorry, you are not eligible for our student discount." << endl;
					cout << "Thank you for shopping at Gunter's Mountain Shop!" << endl;
					cout << endl;
					cout << "********************************************************************************" << endl;
				}
				else
				{
					cout << "ERROR. INVALID INPUT." << endl;
				}
				
			break;
		
		// Here are the names, prices, calculations, purchases, and discount for the outlet store items. 
		case 2:
			int stove_qty, spraywipes_qty, magLite_qty, firstaid_qty, afterBite_qty;

			// Here, the user will be asked to input the number of each item they would like to purchase.

			cout << "How many Camp Stoves would you like to purchase? --> ";
			cin >> stove_qty;
			if (stove_qty < 0)
			{
				stove_qty = 0;
				cout << "Invalid input entered...quantity set to zero..." << "\n";
			}
			cout << endl;

			cout << "How many Bug Spray Wipes would you like to purchase? --> ";
			cin >> spraywipes_qty;
			if (spraywipes_qty < 0)
			{
				spraywipes_qty = 0;
				cout << "Invalid input entered...quantity set to zero..." << "\n";
			}
			cout << endl;

			cout << "How many Mag Lites would you like to purchase? --> ";
			cin >> magLite_qty;
			if (magLite_qty < 0)
			{
				magLite_qty = 0;
				cout << "Invalid input entered...quantity set to zero..." << "\n";
			}
			cout << endl;

			cout << "How many First Aid Kits would you like to purchase? --> ";
			cin >> firstaid_qty;
			if (firstaid_qty < 0)
			{
				firstaid_qty = 0;
				cout << "Invalid input entered...quantity set to zero..." << "\n";
			}
			cout << endl;

			cout << "How much After Bite would you like to purchase? --> ";
			cin >> afterBite_qty;
			if (afterBite_qty < 0)
			{
				afterBite_qty = 0;
				cout << "Invalid input entered...quantity set to zero..." << "\n";
			}
			cout << endl;

			cout << "********************************************************************************" << endl;
			cout << endl;

			// Here are the variables for the cost of each item. The sales prices as well as the total sale price with tax are calculated. 
			double stove_sale, spraywipes_sale, magLite_sale, firstaid_sale, afterBite_sale, totalSale2, tax2, taxSale2;

			stove_sale = stove * stove_qty;
			spraywipes_sale = spraywipes * spraywipes_qty;
			magLite_sale = magLite * magLite_qty;
			firstaid_sale = firstaid * firstaid_qty;
			afterBite_sale = afterBite * afterBite_qty;

			totalSale2 = stove_sale + spraywipes_sale + magLite_sale + firstaid_sale + afterBite_sale;
			tax2 = totalSale2 * 0.07;
			taxSale2 = totalSale2 + tax2;

			// The item names and prices and the total sale price are listed here.
			cout << "Gunter's Main Facility Items" << setw(35) << "Sale Price" << "\n";

			cout << "Camp Stove" << setw(10) << dollarSign << setprecision(5) << stove << fixed;
			cout << setw(34) << "Total: " << dollarSign << setprecision(2) << stove_sale << fixed << endl;

			cout << "Bug Spray Wipes" << setw(5) << dollarSign << setprecision(2) << spraywipes << fixed;
			cout << setw(35) << "Total: " << dollarSign << setprecision(2) << spraywipes_sale << fixed << endl;

			cout << "Mag Lite" << setw(12) << dollarSign << setprecision(2) << magLite << fixed;
			cout << setw(36) << "Total: " << dollarSign << setprecision(2) << magLite_sale << fixed << endl;

			cout << "First Aid Kit" << setw(7) << dollarSign << setprecision(2) << firstaid << fixed;
			cout << setw(35) << "Total: " << dollarSign << setprecision(2) << firstaid_sale << fixed << endl;

			cout << "After Bite" << setw(10) << dollarSign << setprecision(2) << afterBite << fixed;
			cout << setw(36) << "Total: " << dollarSign << setprecision(2) << afterBite_sale << fixed << endl;

			cout << endl;
			cout << "********************************************************************************" << endl;
			cout << endl;

			cout << "TAX: " << dollarSign << setprecision(2) << tax2 << fixed;
			cout << setw(20) << "TOTAL: " << dollarSign << setprecision(2) << totalSale2 << fixed;
			cout << setw(20) << "TOTAL + TAX: " << dollarSign << setprecision(2) << taxSale2 << fixed << endl;
			cout << endl;

			// Here, the user will be asked if they are a student to check their eligibility for the student discount.

			char answer2;

			cout << "Are you a student? Enter Y (Yes) or N (No) --> ";
			cin >> answer2;
			cout << endl;
				if (answer2 == 'Y' || answer2 == 'y')
				{
					double discount2 = taxSale2 * 0.1;
					double discSale2 = taxSale2 - discount2;

					cout << "You are eligible for our 10% student discount!!" << "\n";
					cout << "DISCOUNT: " << dollarSign << setprecision(2) << discount2 << fixed;
					cout << setw(15) << "TOTAL: " << dollarSign << setprecision(2) << taxSale2 << fixed;
					cout << setw(25) << "TOTAL + DISCOUNT: " << dollarSign << setprecision(2) << discSale2 << fixed << endl;
					cout << endl;
					cout << "Thank you for shopping at Gunter's Mountain Shop!" << endl;
					cout << endl;
					cout << "********************************************************************************" << endl;
				}
				else if (answer2 == 'N' || answer2 == 'n')
				{
					cout << "Sorry, you are not eligible for our student discount." << endl;
					cout << "Thank you for shopping at Gunter's Mountain Shop!" << endl;
					cout << endl;
					cout << "********************************************************************************" << endl;
				}
				else
				{
					cout << "ERROR. INVALID INPUT." << endl;
				}
			break;

		case 3:
			cout << "See you again soon at Gunter's Mountain Shop." << "\n";
			cout << endl;
			cout << "***************************************************" << "\n";
			cout << endl;
			break;

		default:
			cout << "Invalid input. Please enter a menu item from 1 - 3." << "\n";
	}

	return 0;
}