#include <iostream>
using namespace std;
int n, cnt=0;
int arr[100];

void getResult(int sum, int idx) {  // 지금까지의 합을 sum에 저장  
	if (arr[0]!=n && sum == n) {
		for (int i = 0; i < idx; i++) {
			if (i == idx - 1)
				cout << arr[i] << ' ';
			else
				cout << arr[i] << "+";
		}
		cnt++;
		cout << "\n";
	}
	else {
		int num = n - sum;   
		
		for (int i = num; i > 0; i--) {
			arr[idx] = i;
			if (idx!=0 && arr[idx - 1] < arr[idx]) continue;

			getResult(sum + i, idx + 1);
		}
	}
}
int main() {
	cin >> n;
	getResult(0, 0);
	cout << cnt;
}