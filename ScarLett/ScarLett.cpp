#include<math.h>
#include <iostream>
using namespace std;
bool theEquation(unsigned long int p);
long double takeFrac(long double input);
unsigned long int FindNextPrime(unsigned long int input);
bool NotPrime(unsigned long int input);
int main()
{
	unsigned long int p = 2;
	while (p<= 7931034000)//Total population 
	{
		if (theEquation(p))
			cout << "Solution discovered: " << p << endl;
		p = FindNextPrime(p);
	}
	cout << p << "checked. No new solution is found.";//Among 7.9 billons people live on the Earth, 521 is the only solution
}
bool theEquation(unsigned long int p)
{
	long double leftSide = takeFrac(1 / takeFrac(sqrt(p)));
	long double rightSide = (sqrt(p) - 15) / 37;
	if (fabs( leftSide - rightSide) < 0.0000001)
		return true;
	else
		return false;
}
long double takeFrac(long double input)
{
	return input- (unsigned long int)input;
}
unsigned long int FindNextPrime(unsigned long int input)
{
	input++;
	while (NotPrime(input))	
	{
		input++;
	}
	return input;
}
bool NotPrime(unsigned long int input)
{
	unsigned int i = 2;
	while (i <= sqrt(input))
	{
		if (input % i == 0)
			return true;
		i++;
	}
	return false;
}
