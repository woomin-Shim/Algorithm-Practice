#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			cnt++;
	}
	if (cnt == 2) cout << "YES\n";
	else cout << "NO\n";
}