// Prob27_Quadratic_primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Euler discovered the remarkable quadratic formula:

n^2+n+41
It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40,40^2+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.

The incredible formula n^2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n^2+an+b, where |a|<1000 and |b|≤1000

where |n| is the modulus/absolute value of n
e.g. |11|=11 and |−4|=4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.

::: make the sieve ...1 to 2000, just to be sure
do the equation while the result of the quardatic formula is less than 2000...

*/

#include "pch.h"
#include <iostream>

int IsPrime(unsigned long long int n)
{
	int i;
	unsigned long long root;
	if (n == 1) return 0;
	root = sqrtl(n);
	for (i = 2; i <= root && n % i > 0; i++);
	return i > root;
}

int main()
{
	unsigned int a, b, ctr, longestprimes = 0, n;
	for (a = 1; a < 1000; a++)
	{
		for (b = 1; b <= 1000; b++)
		{
			n = 0;
			ctr = 0;
			while (IsPrime(n * n + a * n + b))
			{
				n++;
				ctr++;
			}
			if (ctr > longestprimes)
			{
				longestprimes = ctr;
				printf("\n%5d %5d %5d", a, b, ctr);
			}
		}
	}
	printf("\nHello World!");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
