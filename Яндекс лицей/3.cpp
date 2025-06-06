#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>


using namespace std;

int main()
{
	int a = 0;
	cin >> a;

	int first = 0;
	int second = 0;
	int third = 0;
	int fourth = 0;
	int fifth = 1;
	int sixth = 0;
	bool isFifth = false;
	int last = a % 10;

	while (a != 0) {

		if (a % 10 == 3) {
			first++;
		}
		if (a % 10 == last) {
			second++;
		}
		if ((a % 10) % 2 == 0) {
			third++;
		}
		if (a % 10 > 5) {
			fourth += a % 10;
		}
		if ((a % 10 > 7) and (a % 10 != 0)) {
			fifth *= a % 10;
			isFifth = true;
		}
		if (a % 10 == 0 or a % 10 == 5) {
			sixth++;
		}
		a /= 10;
	}



	cout << first << endl << second << endl << third << endl << fourth << endl << fifth << endl << sixth << endl;


}
