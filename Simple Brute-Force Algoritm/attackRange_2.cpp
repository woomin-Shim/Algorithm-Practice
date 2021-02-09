#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y, r;
	int arr[105][105] = { 0, };

	cin >> n;
	cin >> x >> y >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int first = x - i;
			int second = y - j;
			if (first < 0) first *= -1;
			if (second < 0)second *= -1;

			int dist = first + second;
			if (dist == 0) arr[i][j] = -1;
			else if(dist <= r) arr[i][j] = dist;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == -1) cout << "x ";
			else cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}