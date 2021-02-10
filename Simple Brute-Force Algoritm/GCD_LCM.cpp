#include <iostream>
using namespace std;

/*두 수의 최대공약수(GCD)와 최소공배수(LCM)구하기*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, rest, n2, m2;
	cin >> n >> m;
	n2 = n, m2 = m;
	
	if (n < m) {
		int temp = m;
		m = n;
		n = temp;
	}
	int gcm = 0;
	/*
	for (int i = 1; i < n; i++) {
		if (n % i== 0 && m%i == 0) gcm = i;
	}
	*/
	while (1) {
		rest = n % m;
		if (rest == 0) break;
		n = m;
		m = rest;
	}
	gcm = m;
	cout << gcm << "\n";

	int LCM = 0;
	rest = gcm * (n2 / gcm) * (m2 / gcm);
	cout << rest;
	
}