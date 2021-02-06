#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[9], cnt = 0, idx=0, idx2=0;
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	int min = 1000000000, min2=1000000000;
	for (int i = 0; i < 9; i++) {
		if (min > arr[i])
			min = arr[i], idx = i;
	}
	for (int i = 0; i < 9; i++) {
		if (i != idx) {
			if (min2 > arr[i])
				min2 = arr[i], idx2 = i;
		}
	}
	cout << arr[idx2] << "\n" << idx2+1;
}