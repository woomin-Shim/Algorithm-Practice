#include <iostream>
using namespace std;

int getDigitSum(int n) {
	//return the sum of each digit of number n

	if (n / 10 == 0)  //if(n <= 0 && n <= 9)
		return n;
	else
		return getDigitSum(n / 10) + (n % 10);
}
int main() {
	int n;

	cin >> n;

	cout << getDigitSum(n);
}