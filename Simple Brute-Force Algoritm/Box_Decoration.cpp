#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, num;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = 0;
		cin >> num;
		arr[num]++;
	}

	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < 2) sum += arr[i];
		else sum += 2;
	}

	if (sum >= 6)
		cout << "YES\n";
	else
		cout << "NO\n";
}