#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum=0, score=0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			score++;
			sum += score;
		}
		else
			score = 0, sum += score;
	}
	cout << sum << "\n";


}