#include <iostream>
#include <math.h>
using namespace std;;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, cnt;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		cnt = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) cnt++;
		}
		if (cnt == 2) cout << i << ' ';
	}
}