#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int num = n / 2;
	/*
	int width = n * 2 - 1;
	int k = width / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= width; j++) {
			if (j == k || j == (width - k) || (i == n / 2 && j > k && j < width - k))
				cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
		k--;
	}
	*/

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << ' ';
		}
		/*if (i == num) {
			for (int z = 0; z < n; z++)
				cout << "*";
		} */
		for (int k = 0; k < i+1; k++) {
			if (i==num) {
				if (i % 2 == 0) {
					for (int i = 0; i <= n; i++) cout << "*";
					break;
				}
				else
				{
					for (int i = 0; i < n; i++) cout << "*";
					break;
				}
			}
			else {
				if (k == 0 || k == i) cout << "* ";
				else cout << "  ";
			}
		}
		cout << "\n";
	}
}