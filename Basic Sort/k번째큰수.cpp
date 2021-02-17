#include <iostream>
using namespace std;

int arr[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//선택 정렬(내림 차순)
	for (int i = 0; i < k; i++) {
		int idx = i;
		for (int j = i; j < n; j++) {
			if (arr[idx] < arr[j])
				idx = j;
		}
		int temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}

	cout << arr[k-1];

}