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
			for (int i = 0; i < 3; i++) {//in a fib sequnce every third number is even so we go over the odd ones faster
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
		for (int i = 0; i <= num.size() - amount; i++) {
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
}