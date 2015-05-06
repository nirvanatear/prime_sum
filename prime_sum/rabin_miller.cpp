//rabin-miller
//http://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
//since n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
//significantly slower than sieve

#include "stdafx.h"
#include "prime_sum.h"

std::pair<int, long long> refactor(long long d, int prime){
	int s = 0;
	while (d % prime == 0){
		d = d / prime;
		s++;
	}
	return std::make_pair(s, d);
}

long long powermod(int a, long long d, long long n){
	long long x = 1;
	for (long long i = 0; i < d; i++) {
		long tmp = x*a; 
		if (tmp >= n) {
			x = (tmp % n);
		}
		else {
			x = x * a;
		}
	}
	return x;
}

bool probably_prime(long long n, int a){
	//write n - 1 as 2s*d with d odd by factoring powers of 2 from n - 1
	std::pair<int, long long> answer = refactor(n - 1, 2);
	int s = answer.first; long long d = answer.second;

	//x <- a^d mod n
	long long x = powermod(a, d, n);

	//return 1: we determine it has to be composite
	//return 0: strong witness of prime
	if ((x == 1) | (x == n - 1)) return 1;
	for (int i = 0; i < s - 1; i++){
		x = (x * x) % n;
		if (x == 1) return 0;
		if (x == n - 1) return 1;
	}
	return 0;
}

bool rm_primality(long long n, std::vector<int>& A ){
	for (unsigned int i = 0; i < A.size(); i++){
		if (!probably_prime(n, A[i])) return 0;
	}
	return 1;
}

long long rabin_miller(){
	std::vector<int> A = { 2, 7, 61 };
	long long prime_sum = 2+3+5+7+61;

	for (long long n = 2; n <= MAX_INT; n++){
		if ((n % 2 != 0) & (n % 3 != 0) &(n % 5 != 0) &(n % 7 != 0)) {
			if (rm_primality(n, A)) {
				//cout << n << '\n';
				prime_sum += n;
			}
		}
	}

	return prime_sum;
}

