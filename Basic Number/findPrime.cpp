#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num, cnt=0;
	cin >> n;

	while (n--) {
		cin >> num;
		if(isPrime(num)) {
				cnt++;
		}		
	}
	cout << cnt;
}