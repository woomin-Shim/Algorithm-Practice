#include <iostream>
using namespace std;

/*행렬을 뒤집는다. 뒤집을 원소가 1이면 0으로 만들고 ,0이면 1로만든다.
  첫번째 뒤집을 때는 1행1열을 1로, i번째 뒤집을때는 i행 i열을 뒤집어야 한다.
  N을 입력하였을 때 나오는 맵을 출력 */
int map[11][11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt=1;
	cin >> n;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= 10; i++)
			map[i][cnt] += 1;
		for (int j = 1; j <= 10; j++) {
			if (j == k) continue;
			map[cnt][j] += 1;
		}
		cnt++;
	}
	
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (map[i][j] == 2) cout << 0 << ' ';
			else cout << map[i][j] << ' ';
		}
		cout << "\n";
	}

}