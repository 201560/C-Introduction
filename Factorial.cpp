#include <iostream>
using namespace std;
unsigned long long factorial(unsigned long long n) {
	if (n > 1) {
		return n * factorial(n - 1);
	}
	else {
		return 1;
	}
}

int main () {
	int number;
	cin >> number;
	cout << factorial(number) << endl;
	return 0;
}
