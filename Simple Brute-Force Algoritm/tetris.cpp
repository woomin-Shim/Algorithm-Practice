#include <iostream>
using namespace std;

//가장 깊은 곳 찾고, 그곳을 1으로 채운다. 그러면 수평선의 개수를 알 수 있다. 
int map[20][20];
int main() {
	int c, r;
	cin >> c >> r;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}

	int big = 0, X = 0;
	for (int i = 1; i <= c; i++) {//row   c:6 r:7
		int cnt = 0;
		for (int j = 1; j <= r; j++) { //column
			if (map[j][i] == 0) {
				cnt++;
			}
			else if (map[j][i] == 1) {
				break;
			}
		}
		if (big < cnt)
			big = cnt, X = i; //가장 깊은곳의 열인덱스
	}

	int idx = 0, idx2 = 0;
	for (int i = 1; i <= r; i++) {
		if (map[i][X] == 1) {
			idx2 = i;
			break;
		}
		else {
			map[i][X] = 1;
			idx++;
		}
	}

	int y = 0;
	for (int i = 1; i <= r; i++) {
		int sum = 0;
		for (int j = 1; j <= c; j++) {
			sum += map[i][j];
		}
		if (sum == c) {
			y++;
		}
	}
	if ((r - idx2 + 1) + 4 > r) {
		X = 0, y = 0;
		cout << X << ' ' << y;
	}
	else
		cout << X << ' ' << y;
}