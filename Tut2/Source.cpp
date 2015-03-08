#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction(int , int);
	~Fraction();
	void setNumerator(int);
	int getNumerator();
	void setDenominator(int);
	int getDenominator();
	void display(int, int);
	void add(int , int , int , int);
	void subtract(int, int, int, int);
	void multiply(int, int, int, int);
	void divide(int, int, int, int);
	int gcd(int, int);

private:
	int numerator;
	int denominator;
	int sum, difference, product, div;

};

//#include<iostream>
//using namespace std;

//#include "Fraction.h"
Fraction::Fraction(int n , int d)
{
	setNumerator(n);
	setDenominator(d);
}

Fraction::~Fraction()
{
}

void Fraction::setNumerator(int n)
{
	numerator = n;
	sum = 1; 
	difference = 1;
	product = 1;
	div = 1;
}

int Fraction :: getNumerator()
{
	return numerator;
}

void Fraction :: setDenominator(int d)
{
	denominator = d;
}

int Fraction :: getDenominator()
{
	return denominator;
}

void Fraction::add(int aNum, int bNum, int aDenom, int bDenom)
{
	int rNum, rDenom, divisor;
	if (aDenom == bDenom)
	{
		rNum = aNum + bNum;
		rDenom = aDenom;
		 
	}
	else
	{
		rNum = aNum * bDenom + aDenom * bNum;
		rDenom = aDenom * bDenom;
	}

	divisor = gcd(rNum, rDenom);
	rNum= rNum /divisor;
	rDenom = rDenom / divisor;

	cout << "The sum of the two fraction numbers is ";
	display(rNum, rDenom);
}

void Fraction::subtract(int aNum, int bNum, int aDenom, int bDenom)
{
	int rNum, rDenom, divisor;
	if (aDenom == bDenom)
	{
		rNum = aNum - bNum;
		if (rNum < 0)
			rNum = -1 * rNum;
		rDenom = aDenom;
	}
	else
	{
		rNum = aNum * bDenom - aDenom*bNum;
		if (rNum < 0)
			rNum *= -1;
		rDenom = aDenom * bDenom;
	}

	divisor = gcd(rNum, rDenom);
	rNum = rNum / divisor;
	rDenom = rDenom / divisor;
	cout << "The difference of the two fraction numbers is ";
	display(rNum, rDenom);

}

void Fraction::multiply(int aNum, int bNum, int aDenom, int bDenom)
{
	int rNum, rDenom, divisor;
	rNum = aNum * bNum;
	rDenom = aDenom * bDenom;
	divisor = gcd(rNum, rDenom);
	rNum = rNum / divisor;
	rDenom = rDenom / divisor;
	cout << "The product of the two fraction numbers is ";
	display(rNum, rDenom);
}

void Fraction::divide(int aNum, int bNum, int aDenom, int bDenom)
{
	int rNum, rDenom, divisor;
	rNum = aNum * bDenom;
	rDenom = aDenom * bNum;

	divisor = gcd(rNum, rDenom);
	rNum = rNum / divisor;
	rDenom = rDenom / divisor;
	cout << "The fraction number we got by dividing the two fraction numbers is ";
	display(rNum, rDenom);

}

int Fraction::gcd(int rNum, int rDenom)
{
	int a = rNum;
	int b = rDenom;
	int swap;

	do
	{
		if (a < b)
		{
			swap = b;
			b = a;
			a = swap;
		}

		swap = a % b;
		a = b;
		b = swap;
	} while (a % b == 0);
	return a;
}

void Fraction::display(int a, int b)
{
	cout << a << "/" << b << "\n";
}

