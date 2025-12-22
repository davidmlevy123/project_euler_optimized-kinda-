#include <iostream>
#include "answers.h"
#include "Benchmark.h"
#include "answers_test.h"
using std::cout; using std::cin; using std::endl;
int main() {
	int Qnum;
	bool stop = false;
	while (!stop) {
		cout << "enter question number(0 to end,-1 for tests): ";
		cin >> Qnum;
		switch (Qnum) {
		case 0: stop = true; break;
		case 1: answers::Q1(); break;
		case 2: answers::Q2(); break;
		case 3: answers::Q3(); break;
		case 4: answers::Q4(); break;
		case 5: answers::Q5(); break;
		case 6: answers::Q6(); break;
		case 7: answers::Q7(); break;
		case 8: answers::Q8(); break;
		case 9: answers::Q9(); break;
		case 10: answers::Q10(); break;
		case 11: answers::Q11(); break;
		case 12: answers::Q12(); break;
		case -1: {
			int test_num, num_of_tests;
			bool stop_test = false;
			while (!stop_test)
			{
				cout << "---------------- enter question to test(0 to end) -----------------\n\t\t\t\t";
				cin >> test_num;
				switch (test_num) {
				case 0: stop_test = true; break;
				case 1: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q1", answers_for_testing::Q1, num_of_tests); 
					break;
				}
				case 2: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q2", answers_for_testing::Q2, num_of_tests);
					break;
				}
				case 3: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q3", answers_for_testing::Q3, num_of_tests);
					break;
				}
				case 4: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q4", answers_for_testing::Q4, num_of_tests);
					break;
				}
				case 5: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q5", answers_for_testing::Q5, num_of_tests);
					break;
				}
				case 6: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q6", answers_for_testing::Q6, num_of_tests);
					break;
				}
				case 7: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q7", answers_for_testing::Q7, num_of_tests);
					break;
				}
				case 8: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q8", answers_for_testing::Q8, num_of_tests);
					break;
				}
				case 9: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q9", answers_for_testing::Q9, num_of_tests);
					break;
				}
				case 10: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q10", answers_for_testing::Q10, num_of_tests);
					break;
				}
				case 11: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q11", answers_for_testing::Q11, num_of_tests);
					break;
				}
				case 12: {
					cout << "enter amount of tests: ";
					cin >> num_of_tests;
					Utils::Benchmarker::MeasureAndPrint("Q12", answers_for_testing::Q12, num_of_tests);
					break;
				}
				default:
				{
					cout << "not a question with test\n";
					break;
				}//default(switch(2))
				}//switch(2)
			}//while(!stop_test)
			break;
		}//case -1
		default:
		{
			cout << "not a question a answered\n";
			break;
		}//default(switch(1))
		}//switch(Qnum)(1)
	}//while(true)(1)
	return 0;
}//int main