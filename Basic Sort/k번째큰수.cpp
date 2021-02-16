#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	int data[100000] = { 0 };

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> data[i];

	//선택 정렬(내림 차순)
	for (int i = 0; i < k; i++) {
		int idx = i;
		for (int j = i; j < n; j++) {
			if (data[idx] < data[j])
				idx = j;
		}
		int temp = data[i];
		data[i] = data[idx];
		data[idx] = temp;
	}

	cout << data[k - 1];

}