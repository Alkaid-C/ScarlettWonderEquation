#include<math.h>
#include <iostream>
#include <stdio.h>
#include<vector>
using namespace std;
bool theEquation(unsigned long int p);
long double takeFrac(long double input);
unsigned long int FindNextPrime(unsigned long int input, vector<unsigned long int>& PrimeList);
bool NotPrime(unsigned long int input, vector<unsigned long int>& PrimeList);
int main()
{
	vector<unsigned long int> PrimeList;
	PrimeList.push_back(2);
	unsigned long int p = 2;
	while (p <= 7931034000)//World population
	{
		if (theEquation(p) == true)
			cout << "Solution discovered: " << p << endl;
		p = FindNextPrime(p, PrimeList);
	}
	cout << "7,931,034,000 Checked. No new solution is found." << endl;
}
bool theEquation(unsigned long int p)
{
	long double leftSide = takeFrac(1 / takeFrac(sqrt(p)));
	long double rightSide = sqrt(p) - 15) / 37;
	if (fabs(leftSide - rightSide) < 0.0000001)
		return true;
	else
		return false;
}
long double takeFrac(long double input)
{
	return input- (unsigned long int)input;
}
unsigned long int FindNextPrime(unsigned long int input, vector<unsigned long int>& PrimeList)
{
	input++;

	while (NotPrime(input, PrimeList))
	{
		if (input % 1000000000 == 0)//Report Progress Regularly
			cout << input/ 1000000000 << " billion checked. No new solution is found." << endl;
		input++;
	}
	return input;
}
bool NotPrime(unsigned long int input, vector<unsigned long int>& PrimeList)
{
	for (unsigned long int i = 0; i < PrimeList.size(); i++)
	{
		if (PrimeList.at(i) > sqrt(input))
		{
			PrimeList.push_back(input);
			return false;
		}
		if (input% PrimeList.at(i) == 0)
		{
			return true;
		}
	}
	PrimeList.push_back(input);
	return false;
}
