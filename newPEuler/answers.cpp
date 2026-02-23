#include "answers.h"
namespace answers {
	void Q1() {
		long long int num1, num2, maxNum, smallerNum, biggerNum, sumSmall, sumBig, NSmall, NBig, NSame, sumSame, numsGCD;
		cout << "enter 2 numbers to get all the sums of: ";
		cin >> num1 >> num2;
		if (num1 > num2) {//we get the bigger and smaller numbers so later we can calculate the sum
			smallerNum = num2;
			biggerNum = num1;
		}
		else {
			smallerNum = num1;
			biggerNum = num2;
		}
		cout << "enter the max number to sum until: ";
		cin >> maxNum;
		auto start = std::chrono::high_resolution_clock::now();
		if (num1 == num2) {// if they are the same then we ca find the amount of times the num1/num2 goes into maxNum by dividing and from there we can use the sum of an invoice series to calculate
			smallerNum = num1;
			NSmall = (maxNum - 1) / smallerNum;
			sumSmall = (NSmall * (smallerNum + NSmall * smallerNum)) / 2;//note: we still divide by 2 becuase we only count the overlap once
			cout << "the sum of all the sums up until " << maxNum << " is: " << sumSmall << endl;
			return;
		}
		NSmall = (maxNum - 1) / smallerNum;//we find the amount of multipals each number has until maxNum
		NBig = (maxNum - 1) / biggerNum;
		sumSmall = (NSmall * (smallerNum + NSmall * smallerNum)) / 2;//we find the sums using invoice series sum
		sumBig = (NBig * (biggerNum + NBig * biggerNum)) / 2;
		numsGCD = helpers::GCD(num1, num2);//we find the GDC so we can find the part where teh numbers overlap(the smallest number that divids by both num1 and num2)
		NSame = (maxNum - 1) / ((num1*num2)/numsGCD);//we find the amount of overlaps there are
		sumSame = (NSame * (((num1 * num2) / numsGCD) + NSame * (((num1 * num2) / numsGCD)))) / 2;//we calculate the sum of the overlap using invoice series sum
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the sum of all the sums up until " << maxNum << " is: " << sumBig + sumSmall - sumSame << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q2() {
		int maxNum, fibNum = 2, pastFib = 1, fibSum = 2;//we start at 1 and 2 to make the skkipping by 3 easier(thats why the sum is 2)
		cout << "enter the max fib num: ";
		cin >> maxNum;
		auto start = std::chrono::high_resolution_clock::now();
		while (maxNum > fibNum) {//while we havent reached the maxNum
			for (int i = 0; i < 3; ++i) {//in a fib sequnce every third number is even so we go over the odd ones faster
				int temp = fibNum;
				fibNum += pastFib;
				pastFib = temp;
			}
			if (maxNum > fibNum)//if we havent reachedthe max yet we add the curent number
			{
				fibSum += fibNum;
			}
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the sum of the fib nums until: " << maxNum << " is: " << fibSum << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q3() {
		long long int num;
		int maxPrime, curPrime = 0, max = 0;
		std::unordered_map<int, int> pFactors;//i added in that i find all the prime factors and thier power
		cout << "enter the number you want the largest prime factor of: ";
		cin >> num;
		auto start = std::chrono::high_resolution_clock::now();
		if (helpers::isPrime(num)) {
			cout << "the max prime factor is: " << num << endl;
			cout << "the prime factors are: " << num << endl;
			return;
		}
		maxPrime = sqrt(num);
		auto primes = helpers::sieve_P(maxPrime);
		for (auto primeNum : primes) {
			pFactors.insert({ primeNum, 0 });
		}
		while ((curPrime != (primes.size() - 1)) && num != 0) {
			while (num % primes[curPrime] == 0 && num != 0 && primes[curPrime] != 0) {
				num /= primes[curPrime];
				pFactors[primes[curPrime]] = pFactors[primes[curPrime]] + 1;
				max = primes[curPrime]; 
			}
			curPrime += 1;
		}
		if (num > 1)
		{
			pFactors[num] = (num, pFactors[num] + 1);
		}
		if (num > max) {
			max = num;
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the max prime factor is: " << max << endl;
		cout << "the prime factors are:";
		for (auto pair : pFactors) {
			for (int i = 0; i < pair.second; ++i) {
				cout << " " << pair.first;
			}
		}
		cout << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q4() {
		int num_digs, max = 9;
		cout << "enter the amount of digits you want the product of to be a palindrom: ";
		cin >> num_digs;
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = pow(10, num_digs) - 1; i >= 1; i--) {
			for (int j = pow(10, num_digs) - 1; j >= 1; j--) {
				if (helpers::pali_num(j * i)) {
					if (i * j > max) {
						max = i * j;
					}
				}
			}
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the largest palindrom made by the product of 2 numbers with "
			<< num_digs << " digts is: " << max << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q5() {
		int max, cur_gcd, next_gcd;
		long long int cur_lcd;
		cout << "enter the max num you want all the numbers before it to be evenly divisvble by: ";
		cin >> max;
		auto start = std::chrono::high_resolution_clock::now();
		cur_gcd = helpers::GCD(2, 3);
		cur_lcd = 2 * 3 / cur_gcd;
		for (int i = 4; i <= max; ++i) {
			next_gcd = helpers::GCD(cur_lcd, i);
			cur_lcd = cur_lcd * i / next_gcd;
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the lowest number that devides by all the numbers until " << max << " is: " << cur_lcd << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q6() {
		int sum_of_squares, sum_nums, sum_squared, max_num_squared, max_num_squares;
		cout << "enter the number to get the sum of squares until: ";
		cin >> max_num_squares;
		cout << "enter the number to get the sum squared until: ";
		cin >> max_num_squared;
		auto start = std::chrono::high_resolution_clock::now();
		sum_of_squares = ((max_num_squares) * (max_num_squares + 1) * (2 * max_num_squares + 1)) / 6;
		sum_nums = ((max_num_squared) * (max_num_squared + 1)) / 2;
		sum_squared = sum_nums * sum_nums;
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the of the sum of squares until " << max_num_squares << " is: " << sum_of_squares << endl;
		cout << "the sum of all the numbers until " << max_num_squared << " squared is: " << sum_squared << endl;
		cout << "the difference is: " << sum_squared - sum_of_squares << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q7() {
		long long int prime_num, n;
		cout << "enter what number prime you want: ";
		cin >> n;
		auto start = std::chrono::high_resolution_clock::now();
		prime_num = helpers::Nth_prime(n);
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the " << n << "'th prime number is: " << prime_num << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q8() {
		std::string num, copyNum;
		long long int currentSize = 1, maxSize = 0;
		int amount, modAmount = 10, numSize = 0;
		cout << "enter the number u want to examine: ";
		cin >> num;
		copyNum = num;
		cout << "enter the amount of adjacent numbers: ";
		cin >> amount;
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i <= num.size() - amount; ++i) {
			currentSize = 1;
			for (int j = i; j < amount + i; j++) {
				if (num[j] == '0') {
					break;
				}
				currentSize *= (num[j] - 48);
			}
			if (currentSize > maxSize) {
				maxSize = currentSize;
			}
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the max product is: " << maxSize << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q9() {
		double product_of_triplet, b, c, triplet_num = 0;
		cout << "enter the number to get the product of the pythagorean triplet the there sum is the number: ";
		cin >> product_of_triplet;
		auto start = std::chrono::high_resolution_clock::now();
		for (double a = 1; a < product_of_triplet / 3; a++) {
			b = (product_of_triplet * (product_of_triplet / 2 - a)) / (product_of_triplet - a);
			if (b == (int)b)
			{
				c = product_of_triplet - b - a;
				cout << ++triplet_num << helpers::sufix(triplet_num) << " pythagorean triplet\n";
				cout << "a: " << a << " b: " << b << " c: " << c << endl;
				cout << "the product is: " << (long long)(a * b * c) << endl << endl;
			}
		}
		auto stop = std::chrono::high_resolution_clock::now();
		if (triplet_num == 0) {
			cout << "that number doesnt have a pythagorean triplet" << endl;
		}
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q10() {
		long long int sum_prime_max, sum = 0;
		cout << "enter the max number that you want the sum of all primes until: ";
		cin >> sum_prime_max;
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<unsigned long long> primes = helpers::sieve_P(sum_prime_max);
		for (int i = 0; i < primes.size(); ++i) {
			sum += primes[i];
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the sum of all the primes until " << sum_prime_max << " is: " << sum << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q11() {
		int n, m, num_of_adjacent;
		long long int sum_cur = 1, sum_max = 0;
		int** grid;
		cout << "enter grid dimensions: ";
		cin >> n >> m;
		cout << "enter the amount of numbers that you want the product of: ";
		cin >> num_of_adjacent;
		grid = new int* [n - 1];
		for (int i = 0; i < n; ++i) {
			grid[i] = new int[m - 1];
		}
		cout << "enter the grid: \n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> grid[i][j];
			}
		}
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= n - num_of_adjacent; ++j) {
				sum_cur = 1;
				for (int k = 0; k < num_of_adjacent; ++k) {
					sum_cur *= grid[i][j + k];
				}
				if (sum_cur > sum_max) {
					sum_max = sum_cur;
				}
			}
		}
		for (int i = 0; i < n - num_of_adjacent; ++i) {
			for (int j = 0; j <= n; ++j) {
				sum_cur = 1;
				for (int k = 0; k < num_of_adjacent; ++k) {
					sum_cur *= grid[i + k][j];
				}
				if (sum_cur > sum_max) {
					sum_max = sum_cur;
				}
			}
		}
		for (int i = 0; i <= n - num_of_adjacent; ++i) {
			for (int j = 0; j < n; ++j) {
				sum_cur = 1;
				for (int k = 0; k < num_of_adjacent; ++k) {
					sum_cur *= grid[i + k][j];
				}
				if (sum_cur > sum_max) {
					sum_max = sum_cur;
				}
			}
		}
		for (int i = 0; i <= n - num_of_adjacent; ++i) {
			for (int j = 0; j <= n - num_of_adjacent; ++j) {
				sum_cur = 1;
				for (int k = 0; k < num_of_adjacent; ++k) {
					sum_cur *= grid[i + k][j + k];
				}
				if (sum_cur > sum_max) {
					sum_max = sum_cur;
				}
			}
		}
		for (int i = 0; i <= n - num_of_adjacent; ++i) {
			for (int j = num_of_adjacent - 1; j < n; ++j) {
				sum_cur = 1;
				for (int k = 0; k < num_of_adjacent; ++k) {
					sum_cur *= grid[i + k][j - k];
				}
				if (sum_cur > sum_max) {
					sum_max = sum_cur;
				}
			}
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the max product of " << num_of_adjacent << " numbers is: " << sum_max << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q12() {
		int num_of_divisors = 1, curPrime = 0, max_num_of_divisors;
		long long int cur_num = 1, prev_num = 1, max_prime = 100000;
		cout << "enter the amount of divisors that you want a triangular number to have: ";
		cin >> max_num_of_divisors;
		auto start = std::chrono::high_resolution_clock::now();
		auto primes = helpers::sieve_P(max_prime);
		while (true)
		{
			num_of_divisors = 1;
			cur_num += ++prev_num;
			long long temp = cur_num;
			for (int prime : primes) {
				if ((long long)(prime * prime) > temp) {//if the curent amount left is prime
					break;
				}
				if (temp % prime == 0) {
					int p_power = 0;
					while (temp % prime == 0) {
						temp /= prime;
						p_power++;
					}
					num_of_divisors *= (p_power + 1);
				}
			}
			if (temp > 1) {
				num_of_divisors *= 2;
			}
			if (num_of_divisors > max_num_of_divisors)
			{
				break;
			}
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "the first triangular number with " << max_num_of_divisors << " divisors is: " << cur_num << endl;
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
	}
	void Q13() {
		std::string curr, prev;
		int amount;
		cout << "enter the amount of numbers u want: ";
		cin >> amount;
		cout << "enter " << amount << " numbers: ";
		cin >> prev;
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < amount - 1; i++)
		{
			cin >> curr;
			while (curr.size() < prev.size()) {
				curr.insert(curr.begin(), 48);
			}
			for (int j = curr.size() - 1; j >= 0; j--) {
				prev[j] += curr[j] - 48;
				helpers::fix_string(prev, j);
			}
		}
		auto stop = std::chrono::high_resolution_clock::now();
		cout << "---------------------------------------------------------------------\n";
		auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto duration_mil = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		auto duration_sec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		cout << "Time taken: " << (long double)duration_micro.count() << " microseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_mil.count() << " milliseconds" << std::endl;
		cout << "Time taken: " << (long double)duration_sec.count() << " seconds" << std::endl;
		cout << "---------------------------------------------------------------------\n";
		cout << endl << prev << endl;
	}
}