#include <iostream>
using namespace std;


/*백준 1268*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int arr[1001][6];
	int cnt[1001];
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cnt[i] = 0;
	}
	/*int** arr = new int* [n+1];
	for (int i = 1; i <= n; i++)
		arr[i] = new int[6];
		*/
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 5; k++) {
				if (arr[i][k] == arr[j][k]) {
					cnt[i]++;  
					break; //같은 학생을 또 추가하면 안된다. 
				}
			}
		}
	}
	/*
	for (int k = 1; k <= 5; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				else if (arr[i][k] == arr[j][k]) {
					cnt[i]++;
					break;
				}
			}
		}
	}
	*/
	int max = 0, idx=100;
	for (int i = 1; i <= n; i++) {
		if (max < cnt[i])
			max = cnt[i], 
			idx = i;
		else if (max == cnt[i]) {
			if (idx > i)
				idx = i;
		}
	}
	cout << idx;
}	
