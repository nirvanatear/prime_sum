#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

const long long MAX_INT = 1000000LL;

long long eratosthenes();
long long rabin_miller();

std::pair<int, long long> refactor(long long d, int prime);
long long powermod(int a, long long d, long long n);
bool rm_primality(long long n, std::vector<int>& A);