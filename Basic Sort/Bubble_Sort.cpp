#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, data[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1; j++) {  //j가 어디까지 훓는지 *
			if (data[j] > data[j + 1]) {
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << data[i] << ' ';
	}
}