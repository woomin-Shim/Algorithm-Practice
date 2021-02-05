#include <iostream>
using namespace std;

int map[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, x, y;
	cin >> N >> M;
	cin >> x >> y;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}
	int cnt = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i == x && j == y) continue;
			else {
				if (map[i][j] == 1)
					cnt++;
			}
		}
	}
	if (map[x][y] == 1) cout << "game over\n";
	else cout << cnt;
}