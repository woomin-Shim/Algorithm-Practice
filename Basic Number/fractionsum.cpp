#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, a2, b2;
	int gcd;

	cin >> a >> b;
	cin >> a2 >> b2;
	int n1 = b;
	int n2 = b2;

	while (1) {
		int rest = b % b2;
		if (rest == 0) {
			gcd = b2;
			break;
		}
		b = b2;
		b2 = rest;
	}
	int lcm = gcd * (n1 / gcd) * (n2 / gcd);
	
	int num1 = lcm / n1;
	int num2 = lcm / n2;

	int add1 = num1 * a;
	int add2 = num2 * a2;

	cout << add1 + add2 << ' ' << lcm; 
}