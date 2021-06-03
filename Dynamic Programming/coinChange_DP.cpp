#include <iostream>
using namespace std;
#define MAX 1000
#define INF 987654
#define MIN(a,b) a<b? a:b

int coinChange(int coin[], int n, int m) {
	int c[MAX] = { 0, }, j;

	//minimum of coin change num,  m=coin change
	for (int i = 10; i <= m; i+=10) {
		for (c[i]=INF, j = 0; j < n; j++) {
			if (i >= coin[j] && c[i - coin[j]] + 1 < c[i])
				c[i] = c[i - coin[j]] + 1;
		}
	}
	return c[m];
}

int main() {
	int coin_arr[5] = { 500, 130, 100, 50, 10};
	int n;
	cin >> n;
	int result = coinChange(coin_arr, 5, n);
	cout << "거스름돈" << n << "원에 대한 최적해는 " << result;
}