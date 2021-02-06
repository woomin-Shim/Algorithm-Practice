#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, c, big = 0, max = 0;
	cin >> n;
	while (n--) {
		int result = 0;
		cin >> a >> b >> c;
		if (a == b && b == c)
			result = 10000 + (a * 1000);
		else if (a == b)
			result = 1000 + (a * 100);
		else if (b == c)
			result = 1000 + (b * 100);
		else if (a == c)
			result = 1000 + (c * 100);
		else {
			big = a;
			if (b > a && b > c)
				big = b;
			else if (c > a && c > b)
				big = c;
			result = big * 100;
		}
		if (max < result)
			max = result;
	}	
	cout << max;
}