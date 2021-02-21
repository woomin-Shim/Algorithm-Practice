#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long int A, B;
	int gcd;
	cin >> A >> B;
	long long int A2 = A;
	long long int B2 = B;

	/* Time exeed !!
	for (int i = 1; ;i++) {
		if (i % A == 0 && i % B == 0) {
			cout << i;
			break;
		}
	}
	*/

	while (1) {
		int rest = A%B;
		if (rest == 0) {
			gcd = B;
			break;
		}
		A = B;
		B = rest;
	}

	cout << gcd * (A2 / gcd) * (B2 / gcd) << "\n";
}