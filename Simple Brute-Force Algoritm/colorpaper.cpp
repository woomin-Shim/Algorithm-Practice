#include <iostream>
using namespace std;

//BOJ 10163
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, c, d;
	int map[102][102];
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++)
			map[i][j] = 0;
	}
	cin >> n;
	int m = n;
	int cnt = 1;
	while (n--) {
		cin >> a >> b >> c >> d;
		for (int i = a; i < a+d; i++) {
			for (int j = b; j < b + c; j++) {
				map[i][j] = cnt;
			}
		}
		cnt++;
	}

	
	int count[102];
	for (int i = 0; i < 102; i++) count[i] = 0;

	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			for(int k=0; k<=m; k++) {
				if (arr[i][j] == k+1) 
					count[k]++;
				
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << count[i] << "\n";
	}

	/*
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
	*/
}