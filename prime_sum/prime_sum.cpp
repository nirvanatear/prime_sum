// prime_sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "prime_sum.h"

int main()
{
	long long prime_sum = eratosthenes();
	cout << "\n" << prime_sum;
	cin.get();
	cin.get();
	return 0;
}

