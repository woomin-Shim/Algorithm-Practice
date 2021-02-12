#include <iostream>
using namespace std;

/*N까지의 수 중에서 약수의 개수가
  홀수인 숫자들의 개수 출력*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, odd_cnt=0;
	cin >> N;
	int* arr = new int[N+1];
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) cnt++;
		}
		arr[i] = cnt;
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i] % 2 != 0)
			odd_cnt++;
	}
	cout << odd_cnt;
	delete[] arr;
}