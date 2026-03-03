#pragma once
#include <vector>
#include <chrono>
#include <utility>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
namespace helpers {
	int GCD(int num1, int num2);
	bool is_prime(const unsigned long long int num);
	std::vector<bool> sieveB(const unsigned long long int max);
	std::vector<unsigned long long int> sieve_P(const unsigned long long int max);
	bool pali_num(const int num);
	bool pali_str(const std::string& str);
	long long int Nth_prime(const unsigned long long int n);
	std::string sufix(const long long int n);
	void fix_string(std::string& str, const int extra);
	long long int ncr(int top, int bottom);
	long long int count_three_digits(long long int n);
	int month_to_int(const std::string month);
	bool is_leap_year(const int year);
	void vec_times(std::vector<int>& num, const int num_to_times);
	long long int sum_of_proper_divisors(const unsigned long long int num);
	long long int factorial(const int n);
}