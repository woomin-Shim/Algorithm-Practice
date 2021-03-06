#include <iostream>
using namespace std;

int getPower(int n, int m) {
	// return n^m

	if (m == 0)
		return 1;
	else
		return getPower(n, m - 1) * n;
}
int main() {
	int n, m;
	cin >> n >> m;

	cout << getPower(n, m);
}