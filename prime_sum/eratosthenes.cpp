//sieve of eratosthenes
//http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include "stdafx.h"
#include "prime_sum.h"

const long long MAX_INT = 1000000000LL;
//vector<bool> isComposite(MAX_INT, false);
bool isComposite[MAX_INT] = { 0 };

long long eratosthenes()
{
	long long prime_sum = 0;
	for (long long i = 2; i * i < MAX_INT; i++){
		if (!isComposite[i]) {
			cout << i;
			for (long long n = i * i; n < MAX_INT; n += i) {
				//cout << n;
				isComposite[n] = 1;
			}
		}
	}


	for (long long i = 2; i < MAX_INT; i++) {
		if (!isComposite[i]) {
			prime_sum += i;
		}
	}

	return prime_sum;
}
