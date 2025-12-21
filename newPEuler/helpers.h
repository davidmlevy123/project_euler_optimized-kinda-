#pragma once
#include <vector>
#include <chrono>
#include <utility>
#include <unordered_map>
#include <string>
#include <iostream>
namespace helpers {
	int GCD(int num1, int num2);
	bool isPrime(unsigned long long int num);
	std::vector<bool> sieveB(unsigned long long int max);
	std::vector<unsigned long long int> sieve_P(unsigned long long int max);
	bool pali_str(std::string& str);
	bool pali_num(int num);
	long long int Nth_prime(long long int n);
	std::string sufix(int n);
}