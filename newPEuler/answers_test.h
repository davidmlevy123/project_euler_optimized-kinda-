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
	std::string Q13() {
		std::string total[100] = {
			"37107287533902102798797998220837590246510135740250",
			"46376937677490009712648124896970078050417018260538",
			"74324986199524741059474233309513058123726617309629",
			"91942213363574161572522430563301811072406154908250",
			"23067588207539346171171980310421047513778063246676",
			"89261670696623633820136378418383684178734361726757",
			"28112879812849979408065481931592621691275889832738",
			"44274228917432520321923589422876796487670272189318",
			"47451445736001306439091167216856844588711603153276",
			"70386486105843025439939619828917593665686757934951",
			"62176457141856560629502157223196586755079324193331",
			"64906352462741904929101432445813822663347944758178",
			"92575867718337217661963751590579239728245598838407",
			"58203565325359399008402633568948830189458628227828",
			"80181199384826282014278194139940567587151170094390",
			"35398664372827112653829987240784473053190104293586",
			"86515506006295864861532075273371959191420517255829",
			"71693888707715466499115593487603532921714970056938",
			"54370070576826684624621495650076471787294438377604",
			"53282654108756828443191190634694037855217779295145",
			"36123272525000296071075082563815656710885258350721",
			"45876576172410976447339110607218265236877223636045",
			"17423706905851860660448207621209813287860733969412",
			"81142660418086830619328460811191061556940512689692",
			"51934325451728388641918047049293215058642563049483",
			"62467221648435076201727918039944693004732956340691",
			"15732444386908125794514089057706229429197107928209",
			"55037687525678773091862540744969844508330393682126",
			"18336384825330154686196124348767681297534375946515",
			"80386287592878490201521685554828717201219257766954",
			"78182833757993103614740356856449095527097864797581",
			"16726320100436897842553539920931837441497806860984",
			"48403098129077791799088218795327364475675590848030",
			"87086987551392711854517078544161852424320693150332",
			"59959406895756536782107074926966537676326235447210",
			"69793950679652694742597709739166693763042633987085",
			"41052684708299085211399427365734116182760315001271",
			"65378607361501080857009149939512557028198746004375",
			"35829035317434717326932123578154982629742552737307",
			"94953759765105305946966067683156574377167401875275",
			"88902802571733229619176668713819931811048770190271",
			"25267680276078003013678680992525463401061632866526",
			"36270218540497705585629946580636237993140746255962",
			"24074486908231174977792365466257246923322810917141",
			"91430288197103288597806669760892938638285025333403",
			"34413065578016127815921815005561868836468420090470",
			"23053081172816430487623791969842487255036638784583",
			"11487696932154902810424020138335124462181441773470",
			"63783299490636259666498587618221225225512486764533",
			"67720186971698544312419572409913959008952310058822",
			"95548255300263520781532296796249481641953868218774",
			"76085327132285723110424803456124867697064507995236",
			"37774242535411291684276865538926205024910326572967",
			"23701913275725675285653248258265463092207058596522",
			"29798860272258331913126375147341994889534765745501",
			"18495701454879288984856827726077713721403798879715",
			"38298203783031473527721580348144513491373226651381",
			"34829543829199918180278916522431027392251122869539",
			"40957953066405232632538044100059654939159879593635",
			"29746152185502371307642255121183693803580388584903",
			"41698116222072977186158236678424689157993532961922",
			"62467957194401269043877107275048102390895523597457",
			"23189706772547915061505504953922979530901129967519",
			"86188088225875314529584099251203829009407770775672",
			"11306739708304724483816533873502340845647058077308",
			"82959174767140363198008187129011875491310547126581",
			"97623331044818386269515456334926366572897563400500",
			"42846280183517070527831839425882145521227251250327",
			"55121603546981200581762165212827652751691296897789",
			"32238195734329339946437501907836945765883352399886",
			"75506164965184775180738168837861091527357929701337",
			"62177842752192623401942399639168044983993173312731",
			"32924185707147349566916674687634660915035914677504",
			"99518671430235219628894890102423325116913619626622",
			"73267460800591547471830798392868535206946944540724",
			"76841822524674417161514036427982273348055556214818",
			"97142617910342598647204516893989422179826088076852",
			"87783646182799346313767754307809363333018982642090",
			"10848802521674670883215120185883543223812876952786",
			"71329612474782464538636993009049310363619763878039",
			"62184073572399794223406235393808339651327408011116",
			"66627891981488087797941876876144230030984490851411",
			"60661826293682836764744779239180335110989069790714",
			"85786944089552990653640447425576083659976645795096",
			"66024396409905389607120198219976047599490197230297",
			"64913982680032973156037120041377903785566085089252",
			"16730939319872750275468906903707539413042652315011",
			"94809377245048795150954100921645863754710598436791",
			"78639167021187492431995700641917969777599028300699",
			"15368713711936614952811305876380278410754449733078",
			"40789923115535562561142322423255033685442488917353",
			"44889911501440648020369068063960672322193204149535",
			"41503128880339536053299340368006977710650566631954",
			"81234880673210146739058568557934581403627822703280",
			"82616570773948327592232845941706525094512325230608",
			"22918802058777319719839450180888072429661980811197",
			"77158542502016545090413245809786882778948721859617",
			"72107838435069186155435662884062257473692284509516",
			"20849603980134001723930671666823555245252804609722",
			"53503534226472524250874054075591789781264330331690" };
		std::string curr, prev;
		prev = total[0];
		int amount = 100;
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < amount - 1; i++)
		{
			curr = total[i + 1];
			while (curr.size() < prev.size()) {
				curr.insert(curr.begin(), 48);
			}
			for (int j = curr.size() - 1; j >= 0; j--) {
				prev[j] += curr[j] - 48;
				helpers::fix_string(prev, j);
			}
		}
		return prev.substr(0, 10);
	}
	long long int Q14() {
		long long int cur_num, max_num = 1000000, cur_sum, max_sum = 0;
		std::vector<long long int> num_length;
		num_length.push_back(0);
		auto start = std::chrono::high_resolution_clock::now();
		for (long long int i = 1; i < max_num; ++i) {
			cur_num = i;
			cur_sum = 1;
			while (cur_num > 0) {
				if (cur_num == 1) {
					cur_sum = 1;
					break;
				}
				if (num_length.size() > cur_num / 2) {
					if (((cur_num & 1) == 0) && num_length[cur_num / 2]) {
						cur_sum += num_length[cur_num / 2];
						break;
					}
					else if (num_length.size() > 3 * i + 1)
					{
						if (((cur_num & 1) != 0) && num_length[3 * cur_num + 1]) {
							cur_sum += num_length[3 * cur_num + 1];
							break;
						}
					}
				}
				if ((cur_num & 1) == 0)//if even
				{
					cur_num /= 2;
					cur_sum += 1;
				}
				else {
					cur_num = 3 * cur_num + 1;
					cur_sum += 1;
				}//else
			}//while
			num_length.push_back(cur_sum);
		}//for
		std::vector<long long int>::iterator index_iterator = std::max_element(num_length.begin(), num_length.end());
		int index = std::distance(num_length.begin(), index_iterator);
		return index;
	}
	long long int Q15() {
		int x1 = 0, x2 = 0, y1 = 20, y2 = 20;
		int top_of_ncr = x2 - x1 + y2 - y1;
		int bottom_of_ncr = x2 - x1;
		long long ans = helpers::ncr(top_of_ncr, bottom_of_ncr);
		return ans;
	}
	long long int Q16() {
		int base = 2, exponent = 1000, sum_of_digs = 0;
		std::string ans = "1";
		for (int i = 0; i < exponent; ++i) {
			int extra = 0;
			std::string cur;
			for (int j = ans.size() - 1; j >= 0; --j) {
				int cur_digit_value = (ans[j] - '0') * base + extra;
				cur.insert(cur.begin(), cur_digit_value % 10 + '0');
				extra = cur_digit_value / 10;
			}
			while (extra > 0) {
				cur.insert(cur.begin(), extra % 10 + '0');
				extra /= 10;
			}
			ans = cur;
		}
		for (char digit : ans) {
			sum_of_digs += digit - 48;
		}
		return sum_of_digs;
	}
	long long int Q17() {
		int max_num = 1000 , save_max_num;
		long long int total_sum = 0;
		save_max_num = max_num;
		int powers[] = { 0,8,7,7,8,11,11,10,10,9,9,9 };//goes untill decilion(10^33)
		if (max_num == 0) {
			total_sum = 4;
		}
		else {
			for (int i = 1; i <= max_num; ++i)
			{
				int cur_num = i, index = 0;
				while (cur_num > 0) {
					int last_three = cur_num % 1000;
					if (last_three > 0) {
						int last_three_count = helpers::count_three_digits(last_three);
						total_sum += last_three_count + powers[index];
						if (index == 0 && i > 1000 && last_three < 100) {
							total_sum += 3;//and for thousand
						}
					}
					cur_num /= 1000;
					index++;
				}
			}
		}
		return total_sum;
	}
	long long int Q19() {
		int end_date_day = 31, end_date_year = 2000, month_num, day_of_weak = 0, count = 0, month_num_days;
		std::string month = "Dec";
		int month_lengths[] = { 0,31,-1,31,30,31,30,31,31,30,31,30,31 };
		month_num = helpers::month_to_int(month);
		if (month_num == -1) {
			cout << "bad month\n";
			return -1;
		}
		month_num_days = month_lengths[month_num];
		if (month_num_days == -1) {
			if (helpers::is_leap_year(end_date_year)) {
				month_num_days = 29;
			}
			else {
				month_num_days = 28;
			}
		}
		int cur_year = 1900, cur_day = 2, cur_month = 1, cur_month_days, cur_day_in_month = 1;
		while (cur_year != end_date_year || cur_day_in_month != end_date_day || cur_month != month_num) {
			if (cur_day_in_month == 1 && cur_day == 1 && cur_year != 1900) {
				count++;
			}
			cur_month_days = month_lengths[cur_month];
			if (cur_month_days == -1) {
				if (helpers::is_leap_year(cur_year)) {
					cur_month_days = 29;
				}
				else {
					cur_month_days = 28;
				}
			}
			if (cur_day_in_month == cur_month_days) {
				if (cur_month == 12) {
					cur_month = 1;
					cur_year++;
				}
				else {
					cur_month++;
				}
				cur_day_in_month = 0;
			}
			if (cur_day == 7) {
				cur_day = 1;
				cur_day_in_month++;
			}
			else {
				cur_day++;
				cur_day_in_month++;
			}//else
		}//while
		return count;
	}
}