/*
Assignment: Lab 7
Author: Ryan Bezold
Last Modified: 3/16/2019
Description: Write the functions detailed below. Use the main() provided below to test the functions. See the notes
on the website on Implementing Functions for tips on interpreting these descriptions and writing the
functions. Also review the notes on Functions covered in class.
*/

#include <iostream>

using namespace std;

const int MAX_FRACTIONS = 10, MIN_FRACTIONS = 1;

struct fraction
{
	int      numerator;
	int      denominator;
	float    decimal;
};

//-------------------------
//       askFraction
//-------------------------
fraction askFraction()
{
	fraction F;

	F.denominator = 0;

	cout << "Enter the numerator value: ";
	cin >> F.numerator;

	while (F.denominator == 0)
	{
		cout << "Enter the denomenator value: ";
		cin >> F.denominator;
	}

	F.decimal = 0.0;

	return F;
}

//-------------------------
//       calcDecimal
//-------------------------
void calcDecimal(fraction & F)
{
	if (F.denominator == 0)
		F.decimal = 0.0;
	else
	{
		F.decimal = float(F.numerator) / float(F.denominator);
	}
}

//-------------------------
//       printFraction
//-------------------------
void printFraction(fraction & F)
{
	cout << F.numerator << " / " << F.denominator << " (" << F.decimal << ")";
}

//-----------------------------
//       askFractionList
//-----------------------------
void askFractionList(fraction Fractions[], int & numFractions)
{
	
	while (numFractions < MIN_FRACTIONS || numFractions > MAX_FRACTIONS)
	{
		cout << "How many fractions? ";
		cin >> numFractions;

		if (numFractions < MIN_FRACTIONS || numFractions > MAX_FRACTIONS)
		{
			cout << "Enter a number between 1 and 10" << endl;
		}
	}

	for (int i = 0; i < numFractions; i++)
	{
		cout << "For fraction " << i+1 << endl;
		Fractions[i] = askFraction();
		calcDecimal(Fractions[i]);
	}
}

//-----------------------------
//       printFractionList
//-----------------------------
void printFractionList(fraction Fractions[], int numFractions)
{
	for (int i = 0; i < numFractions; i++)
	{
		printFraction(Fractions[i]);
		cout << endl;
	}
}

//-----------------------------
//       findMaxFraction
//-----------------------------
int findMaxFraction(fraction Fractions[], int numFractions)
{
	int Max = 0;

	if (numFractions == 0)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < numFractions; i++)
		{
			if (Fractions[i].decimal >= Fractions[Max].decimal)
				Max = i;
		}
		return Max;
	}
}

int main()
{
	fraction Fractions[MAX_FRACTIONS];
	int numFractions = -1;
	int maxFraction_Index;

	askFractionList(Fractions, numFractions);
	printFractionList(Fractions, numFractions);

	cout << "The highest value fraction is: ";

	maxFraction_Index = findMaxFraction(Fractions, numFractions);
	printFraction(Fractions[maxFraction_Index]);
	cout << endl;
	system("Pause");
}