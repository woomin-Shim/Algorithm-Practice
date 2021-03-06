#include <iostream>
using namespace std;

void printBinary(int n) {
	if (n == 0)
		cout << "0";
	else if (n == 1)
		cout << "1";
	else {
		printBinary(n / 2);
		cout << n % 2;
	}
}
int main() {
	int n;
	cin >> n;
	printBinary(n);
}