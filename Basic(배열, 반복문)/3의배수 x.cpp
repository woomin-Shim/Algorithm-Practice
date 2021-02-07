#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, sum = 0;
	cin >> M;
	for (int i = 1; ; i++) {
		sum += i;
		if (sum >= M) {
			cout << i;
			break;
		}
	}
}