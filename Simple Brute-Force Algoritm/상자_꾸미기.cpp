#include <iostream>
using namespace std;

/*면이 6개인 상자가 있다. 이를 여러가지 색종이를 붙여 꾸밀려고하는데
  단, 인접한 면은 같은 색의 종이를 붙일 수 없다.또한 한면에는 한장의 색종이만 붙임
  조건을 만족하면 yes 만족하지 않으면 no 
  입력-> 색종이의 개수 N, 각각 색종이의 색깔을 나타내는 N개의 숫자 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum = 0;
	string s;
	cin >> n;
	int* arr = new int[n];
	int* cnt = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i+1 == arr[j]) cnt[i]++;
			if (cnt[i] > 2)
				cnt[i] = 2;
		}
		sum += cnt[i];
	}
	
		if (sum >= 6) 
			cout << "YES\n";
		else 
			cout << "NO\n";

		delete[] arr, delete[] cnt;
	
}