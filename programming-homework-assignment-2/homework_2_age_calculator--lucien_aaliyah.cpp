/*
COP 2000 — Introduction to Programming
Program: Age Calculator
Written by Aaliyah Lucien
Created: 10/20/2022, 8:33 PM
Last modified: 10/22/2022, 5:34 PM

This program caluculates the age of the user based on the user input.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	int birthYear;
	int currYear = 2022;
	char ch;

	// This is the program's name header.
	cout << "************************************" << endl;
	cout << "*** \t AGE CALCULATOR \t ***" << "\n";
	cout << "************************************" << endl;

	// Here, the user enters their name and it is displayed afterward.
	cout << "Please enter your full name: " << "\n";
	getline(cin, name);
	cout << "Press the Enter key to continue." << endl;
	cout << " ";
	cin.get();

	cout << "Please enter your birth year: " << endl;
	cin >> birthYear;
	cin.ignore();
	cout << "Press the Enter key to continue." << endl;
	cout << " ";
	cin.get();

	// Here, the user's age is calculated.
	int age = currYear - birthYear;

	// Here, the user is greeted and presented with their calculated age.
	cout << "Hi " << name << "! " << "You are " << age << " years old!" << endl;

	return 0;
}