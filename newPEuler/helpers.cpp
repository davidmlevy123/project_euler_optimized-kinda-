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
	bool is_prime(unsigned long long int num) {
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
		std::vector<bool> is_prime = sieveB(max);
		std::vector<unsigned long long int> primes;
		for (long long int i = 0; i<= max; ++i) {
			if (is_prime[i]) {
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
	void fix_string(std::string& str, int place) {
		if (place < 0) {
			str.insert(str.begin(), '1');
			return;
		}
		else if (str[place] <= '9') {
			return;
		}
		int int_value = str[place] - 48;
		str[place] = int_value % 10 + 48;
		if (place == 0) {
			str.insert(str.begin(), '1');
			return;
		}
		str[place - 1] += 1;
		fix_string(str, place - 1);
	}
	long long int ncr(int top, int bottom) {
		long long int ans = 1;
		if (bottom > top - bottom) {
			bottom = top - bottom;//n(ncr)k=n(ncr)(n-k)
		}
		for (int i = 1; i <= bottom; ++i) {
			ans *= top - i + 1;
			ans /= i;
		}
		return ans;
	}
	long long int count_three_digits(long long int n) {
		int one_dig[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
		int teens[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
		int two_digits[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
		int num_of_letters = 0;
		if (n >= 100) {
			num_of_letters += one_dig[n / 100] + 7;//7 for one hundred
			if (n % 100 != 0) {
				num_of_letters += 3;//and
			}
		}
		n = n % 100;
		if (n >= 10 && n < 20)
		{
			num_of_letters += teens[n - 10];
		}
		else {
			num_of_letters += two_digits[n / 10];
			num_of_letters += one_dig[n % 10];
		}
		return num_of_letters;
	}

}
