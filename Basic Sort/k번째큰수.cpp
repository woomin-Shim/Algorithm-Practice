#include <iostream>
using namespace std;

/*첫째 줄에 자연수 N, K가 주어지고 (1<=N<=100,000, 1<=K<=10)
  두번째 줄에 N개의 자연수가 주어진다.
  K번째로 큰 수를 출력. 단, k가 1이라면 가장 큰수를 출력. */

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;

	cin >> n >> k;
	int* data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	
	int cnt = 0, result=0;
	for (int i = 0; i < n; i++) {
		cnt++;
		for (int j = 0; j < n - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
			if (cnt == k)
				result = data[n - i-1];
			
		}
	}
	
		cout << result << ' ';



}