#include <iostream>
using namespace std;

/*
분자 분모가 모두 자연수인 두 분수의 합 또한 분자 분모가 자연수인 분수로 표현할 수 있다.
두 분수가 주어졌을 때, 그 합을 기약분수의 형태로 구하는 프로그램을 작성하시오.
*/
int gcd(int a, int b) {
	while (1) {
		int rest = a % b;
		if (rest == 0) {
			return b;
			break;
		}
		a = b;
		b = rest;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, a2, b2;
	
	cin >> a >> a2;
	cin >> b >> b2;

	int down = a2 * b2;
	int up = b * a2 + a * b2;

	int num =gcd(up, down);

	cout << up / num << ' ' << down / num;

	return 0;
}