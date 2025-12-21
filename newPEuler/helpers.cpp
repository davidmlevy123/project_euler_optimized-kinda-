#include "helpers.h"
namespace helpers {
	int GCD(int num1, int num2) {
		while (num1 != 0) {
			int temp = num1;
			num1 = num2 % num1;
			num2 = temp;
		}
		return num2;
	}
	bool isPrime(unsigned long long int num) {
		if (num == 2 || num == 3) {
			return true;
		}
		else if (num % 2 == 0 || num % 3 == 0 || num <= 1) {
			return false;
		}
		for (int i = 5; i * i <= num; i+=6) {
			if (num % i == 0 || num % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
	std::vector<bool> sieveB(unsigned long long int maxP) {
		std::vector <bool> primes(maxP + 1, true);
		primes[0] = primes[1] = false;
		for (unsigned long long int p = 2; p * p <= maxP; ++p) {
			if (primes[p]) {
				for (int i = p * p; i <= maxP; i += p) {
					primes[i] = false;
				}
			}
		}
		return primes;
	}
	std::vector<unsigned long long int> sieve_P(unsigned long long int max) {
		std::vector<bool> isPrime = sieveB(max);
		std::vector<unsigned long long int> primes;
		for (long long int i = 0; i<= max; ++i) {
			if (isPrime[i]) {
				primes.push_back(i);
			}
		}
		return primes;
	}
	bool pali_num(int num) {
		std::string Snum = std::to_string(num);
		return pali_str(Snum);
	}
	bool pali_str(std::string& str) {
		for (int i = 0; i < str.size() / 2; ++i) {
			if (str[i] != str[str.size() - i - 1]) {
				return false;
			}
		}
		return true;
	}
	long long int Nth_prime(long long int n) {
		auto primes = sieve_P(n * log(n) + n * log(log(n)));
		return primes[n - 1];
	}
	std::string sufix(int n) {
		if (n == 1) {
			return "st";
		}
		else if (n == 2) {
			return "nd";
		}
		else if (n == 3) {
			return "rd";
		}
		else
		{
			return "th";
		}

	}

}
