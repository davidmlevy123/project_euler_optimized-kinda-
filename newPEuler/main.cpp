#include <iostream>
#include "answers.h"
using std::cout; using std::cin; using std::endl;
int main() {
	int Qnum;
	bool stop = false;
	while (!stop) {
		cout << "enter question number(0 to end): ";
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
		default:
		{
			cout << "not a question a answered\n";
			break;
		}
		}
		
	}

	

}