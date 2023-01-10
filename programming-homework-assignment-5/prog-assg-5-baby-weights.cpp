/*
COP 2000 - Introduction to Programming 
Program: Baby Weights
Written by: Aaliyah Lucien
Created: 07/4/2022, 9:13 PM
Last modified: 07/5/2022, 8:13 PM
*/

#include <iostream>
#include <iomanip>
using namespace std;

// This function displays the program's title, intructions for entering weights, and the developer's name.
void welcome()
{
	cout << "**************************************************************************************" << endl;
	cout << setw(32) << "~" << " BABY WEIGHT PROGRAM " << "~" << endl;
	cout << setw(28) << "" << "Please enter five baby weights." << endl;
	cout << setw(14) << "" << "Please enter a real number weight (must be greater than zero)." << endl;
	cout << endl;
	cout << setw(24) << "" << "Program developed by: AALIYAH LUCIEN " << endl;
	cout << "**************************************************************************************" << endl;
}

// This function is used to validate the users input in the getBabyWeight() function.
void inputValidate(double &inputWeight)
{
	while (inputWeight <= 0)
	{
		cout << " ERROR. Please re-enter a valid weight (must be greater than 0) --> ";
		cin >> inputWeight;
		cout << endl;
	}
}

// This function is used to collect the weights of each baby that the user enters.
void getBabyWeight(double &babyWeight)
{
	cout << " Please enter the baby's weight --> ";
	cin >> babyWeight;
	cout << endl;
	inputValidate(babyWeight);
}

// This function is used to find the lowest weight of the five baby weights the user entered.
void findLowest(double weight1, double weight2, double weight3, double weight4, double weight5)
{
	double lowest1, lowest2, lowest3, lowest4, lowest5;
	lowest1 = weight1 < weight2 && weight1 < weight3 && weight1 < weight4 && weight1 < weight5;
	lowest2 = weight2 < weight1 && weight2 < weight3 && weight2 < weight4 && weight2 < weight5;
	lowest3 = weight3 < weight1 && weight3 < weight2 && weight3 < weight4 && weight3 < weight5;
	lowest4 = weight4 < weight1 && weight4 < weight2 && weight4 < weight3 && weight4 < weight5;
	lowest5 = weight5 < weight1 && weight5 < weight2 && weight5 < weight3 && weight5 < weight4;

	if (lowest1 == false && lowest2 == false && lowest3 == false && lowest4 == false && lowest5 == false)
	{
		cout << " TIE!! No lowest birth weight... \n";
		cout << endl;
	}
	else if (lowest1 ==true)
	{
		cout << " Baby #1 has the lowest birth weight at  " << weight1 << "." << endl;
	}
	else if (lowest2 == true)
	{
		cout << " Baby #2 has the lowest birth weight at  " << weight2 << "." << endl;
	}
	else if (lowest3 == true)
	{
		cout << " Baby #3 has the lowest birth weight at  " << weight3 << "." << endl;
	}
	else if (lowest4 == true)
	{
		cout << " Baby #4 has the lowest birth weight at  " << weight4 << "." << endl;
	}
	else if (lowest5 == true)
	{
		cout << " Baby #5 has the lowest birth weight at  " << weight5 << "." << endl;
	}

}

// This function is used to find the highest weight of the five baby weights the user entered.
void findHighest(double weight1, double weight2, double weight3, double weight4, double weight5)
{
	double highest1, highest2, highest3, highest4, highest5;
	
	highest1 = weight1 > weight2 && weight1 > weight3 && weight1 > weight4 && weight1 > weight5;
	highest2 = weight2 > weight1 && weight2 > weight3 && weight2 > weight4 && weight2 > weight5;
	highest3 = weight3 > weight1 && weight3 > weight2 && weight3 > weight4 && weight3 > weight5;
	highest4 = weight4 > weight1 && weight4 > weight2 && weight4 > weight3 && weight4 > weight5;
	highest5 = weight5 > weight1 && weight5 > weight2 && weight5 > weight3 && weight5 > weight4;

	if (highest1 == false && highest2 == false && highest3 == false && highest4 == false && highest5 == false)
	{
		cout << " TIE!! No highest birth weight... \n";
		cout << endl;
	}
	else if (highest1 == true)
	{
		cout << " Baby #1 has the highest birth weight at " << weight1 << "." << endl;
	}	
	else if (highest2 == true)
	{
		cout << " Baby #2 has the highest birth weight at " << weight2 << "." << endl;
	}
	else if (highest3 == true)
	{
		cout << " Baby #3 has the highest birth weight at " << weight3 << "." << endl;
	}
	else if (highest4 == true)
	{
		cout << " Baby #4 has the highest birth weight at " << weight4 << "." << endl;
	}
	else if (highest5 == true)
	{
		cout << " Baby #5 has the highest birth weight at " << weight5 << "." << endl;
	}

}

//This function is used to calculate the average of all five baby weights that the user entered in the getBabyWeight() function.
double weightAverage(double weight1, double weight2, double weight3, double weight4, double weight5)
{
	double average = (weight1 + weight2 + weight3 + weight4 + weight5) / 5;
	return average;
}

int main()
{
	welcome();

	// The variables for each baby weight are defined here.
	double baby1, baby2, baby3, baby4, baby5;

	
	// The function getBabyweight() is called to prompt the user to enter a weight for each baby.
	getBabyWeight(baby1);
	cout << endl;

	getBabyWeight(baby2);
	cout << endl;

	getBabyWeight(baby3);
	cout << endl;

	getBabyWeight(baby4);
	cout << endl;

	getBabyWeight(baby5);
	cout << endl;

	//The function findLowest() is called to find the lowest baby weight and displays it on the screen.
	findLowest(baby1, baby2, baby3, baby4, baby5);

	//The function findHighest() is called to find the highest baby weight and displays it on the screen.
	findHighest(baby1, baby2, baby3, baby4, baby5);

	/*
		The function weightAverage() is called to find the average of all five baby weights.
		The average weight is displayed on the screen after the function call.
	*/
	double avgWeight = weightAverage(baby1, baby2, baby3, baby4, baby5);
	cout << " The average baby weight is: "<< avgWeight << ".";
	cout << endl;
	
	return 0;
}