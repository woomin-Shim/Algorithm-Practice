#include <iostream>
using namespace std;

int NtoM(int n, int m) {
	// return the sum from n to m

	if (n == m)
		return n;
	else
		return NtoM(n, m - 1) + m;
}
int main() {
	int n, m;

	cin >> n >> m;

	cout << NtoM(n, m);
}