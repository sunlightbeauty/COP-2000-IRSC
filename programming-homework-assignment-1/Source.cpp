/*
Program: Gunter's Mountain Shop
Written by Aaliyah Lucien
Last modified: 05/10/2022 10:38 PM
This program outputs the names and prices for sales items at Gunter's Mountain Shop.
*/

#include <iostream>
using namespace std;

int main()
{
	// Here is the logo for Gunter's Mountain Shop. 
	cout << "******************************************" << endl;
	cout << "**" << "\t" << "     //\\" << "                    \t\t" << "**" << endl;
	cout << "**" << "\t" << "    //  \\  //\\" << "                \t\t" << "**" << endl;
	cout << "**" << "\t" << "   //    \\//  \\    //\\" << "         \t\t" << "**" << endl;
	cout << "**" << "\t" << "  //           \\  //  \\      " << "  \t\t" << "**" << endl;
	cout << "**" << "\t" << " //             \\//    \\          " << "\t" << "**" << endl;
	cout << "**" << "\t" << "//                      \\        " << "\t" << "**" << endl;
	cout << "******************************************" << endl;

	cout << "**" << "  Welcome to Gunter's Mountain Shop \t" << "**" << endl;
	cout << "******************************************" << endl;
	cout << "\n";

	// These are the prices for each sales item.
	char dollarSign = '$';
	unsigned short int boots, pullovers, gaiters, cleats;
	boots = 59;
	pullovers = 10;
	gaiters = 12;
	cleats = 14;

	// Here are the names of the sales items listed along with their sales prices.
	cout << "Sales Items\t" << "\t" << "Sales Price" << "\n";
	cout << "Hunter Climbing Boots\t" << dollarSign << boots << "\n";
	cout << "Fleece Pullovers\t" << dollarSign << pullovers << "\n";
	cout << "Snow Gaiters\t" << "\t" << dollarSign << gaiters << "\n";
	cout << "Traction Cleats\t" << "\t" << dollarSign << cleats << "\n";

	return 0;
}
