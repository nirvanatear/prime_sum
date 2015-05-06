// prime_sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "prime_sum.h"

int main()
{
	long long prime_sum = eratosthenes();
	cout << prime_sum << "\n";

	prime_sum = rabin_miller();
	cout << prime_sum << "\n";

	cin.get();
	cin.get();
	return 0;
}

