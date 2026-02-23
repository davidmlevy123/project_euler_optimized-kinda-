#pragma once
#include <iostream>
#include <chrono>
#include "helpers.h"
using namespace std;
namespace answers_for_testing {
	long long int Q1() {
		long long maxNum = 1000, sumSmall, sumBig, NSmall, NBig, NSame, sumSame, numsGCD;
		int num1 = 3, num2 = 5, smallerNum, biggerNum;
		if (num1 > num2) {//we get the bigger and smaller numbers so later we can calculate the sum
			smallerNum = num2;
			biggerNum = num1;
		}
		else {
			smallerNum = num1;
			biggerNum = num2;
		}
		if (num1 == num2) {// if they are the same then we ca find the amount of times the num1/num2 goes into maxNum by dividing and from there we can use the sum of an invoice series to calculate
			smallerNum = num1;
			NSmall = (maxNum - 1) / smallerNum;
			sumSmall = (NSmall * (smallerNum + NSmall * smallerNum)) / 2;//note: we still divide by 2 becuase we only count the overlap once
			return sumSmall;
		}
		NSmall = (maxNum - 1) / smallerNum;//we find the amount of multipals each number has until maxNum
		NBig = (maxNum - 1) / biggerNum;
		sumSmall = (NSmall * (smallerNum + NSmall * smallerNum)) / 2;//we find the sums using invoice series sum
		sumBig = (NBig * (biggerNum + NBig * biggerNum)) / 2;
		numsGCD = helpers::GCD(num1, num2);//we find the GDC so we can find the part where teh numbers overlap(the smallest number that divids by both num1 and num2)
		NSame = (maxNum - 1) / ((num1 * num2) / numsGCD);//we find the amount of overlaps there are
		sumSame = (NSame * (((num1 * num2) / numsGCD) + NSame * (((num1 * num2) / numsGCD)))) / 2;//we calculate the sum of the overlap using invoice series sum
		return sumBig + sumSmall - sumSame;
	}
	long long int Q2() {
		int maxNum = 4000000, fibNum = 2, pastFib = 1;
		long long int fibSum = 2;//we start at 1 and 2 to make the skkipping by 3 easier(thats why the sum is 2)
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
		return fibSum;
	}
	long long int Q3() {
		long long int num = 600851475143;
		int maxPrime, curPrime = 0, max = 0;
		maxPrime = sqrt(num);
		auto primes = helpers::sieve_P(maxPrime);
		while ((curPrime != (primes.size() - 1)) && num != 0) {
			while (num % primes[curPrime] == 0 && num != 0 && primes[curPrime] != 0) {
				num /= primes[curPrime];
				max = primes[curPrime];
			}
			curPrime += 1;
		}
		if (num > max) {
			max = num;
		}
		return max;
	}
	long long int  Q4() {
		int num_digs = 3, max = 9;
		for (int i = pow(10, num_digs) - 1; i >= 1; i--) {
			for (int j = pow(10, num_digs) - 1; j >= 1; j--) {
				if (helpers::pali_num(j * i)) {
					if (i * j > max) {
						max = i * j;
					}
				}
			}
		}
		return max;
	}
	long long int Q5() {
		int max = 20, cur_gcd, next_gcd;
		long long int cur_lcd;
		cur_gcd = helpers::GCD(2, 3);
		cur_lcd = 2 * 3 / cur_gcd;
		for (int i = 4; i <= max; ++i) {
			next_gcd = helpers::GCD(cur_lcd, i);
			cur_lcd = cur_lcd * i / next_gcd;
		}
		return cur_lcd;
	}
	long long int Q6() {
		int sum_of_squares, sum_nums, sum_squared, max_num = 100;
		sum_of_squares = ((max_num) * (max_num + 1) * (2 * max_num + 1)) / 6;
		sum_nums = ((max_num) * (max_num + 1)) / 2;
		sum_squared = sum_nums * sum_nums;
		return sum_squared - sum_of_squares;
	}
	long long int Q7() {
		long long int prime_num, n = 10001;
		prime_num = helpers::Nth_prime(n);
		return prime_num;
	}
	long long int Q8() {
		std::string num = "73167176531330624919225119674426574742355349194934969835203127745063262395783180169848018694788518438586156078911294949545950173795833195285320880551112540698747158523863050715693290963295227443043557668966489504452445231617318564030987111217223831136222989342338030813533627661428280644448664523874930358907296290491560440772390713810515859307960866701724271218839987979087922749219016997208880937766572733300105336788122023542180975125454059475224352584907711670556013604839586446706324415722155397536978179778461740649551492908625693219784686224828397224137565705605749026140797296865241453510047482166370484403199890008895243450658541227588666881178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
		long long int currentSize = 1, maxSize = 0;
		int amount = 13;
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
		return maxSize;
	}
	long long int Q9() {
		double product_of_triplet = 1000, b, c;
		for (double a = 1; a < product_of_triplet / 3; a++) {
			b = (product_of_triplet * (product_of_triplet / 2 - a)) / (product_of_triplet - a);
			if (b == (int)b)
			{
				c = product_of_triplet - b - a;
				return (long long)(a * b * c);
			}
		}
		return -1;
	}
	long long int Q10() {
		long long int sum_prime_max = 2000000, sum = 0;
		std::vector<unsigned long long> primes = helpers::sieve_P(sum_prime_max);
		for (int i = 0; i < primes.size(); ++i) {
			sum += primes[i];
		}
		return sum;
	}
	long long int Q11() {
		int n = 20, m = 20, num_of_adjacent = 4;
		long long int sum_cur = 1, sum_max = 0;
		int grid[20][20] = {
							{8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
							{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
							{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
							{52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
							{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
							{24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
							{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
							{67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
							{24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
							{21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
							{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
							{16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
							{86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
							{19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
							{4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
							{88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
							{4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
							{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
							{20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
							{1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}
		};
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
		return sum_max;
	}
	long long int Q12() {
		int num_of_divisors = 1, curPrime = 0, max_num_of_divisors = 500;
		long long int cur_num = 1, prev_num = 1, max_prime = 100000;
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
		return cur_num;
	}
}