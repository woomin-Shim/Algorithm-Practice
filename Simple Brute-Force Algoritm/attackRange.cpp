#include <iostream>
#include <math.h>
using namespace std;

/*유닛의 사거리를 나타내는 기능을 구현
  첫번째 줄에는 디펜스 게임의 맵크기 N, 맵은 NXN형태
  둘째 줄에는 유닛이 설치될 위치 x,y와 유닛의 사거리 R을 입력
  (x,y는 1이상 N이하의 자연수, R은 N/2이하의 자연수)
  유닛의 사거리를 출력 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y, r;
	cin >> n;
	cin >> x >> y >> r;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == x && j == y)	cout << "X ";
			else if (abs(x - i) + abs(y - j) <= r) 
					cout << abs(x - i) + abs(y - j) << ' ';
			else
				cout << 0 << ' ';
		}
		cout << "\n";
	}

}