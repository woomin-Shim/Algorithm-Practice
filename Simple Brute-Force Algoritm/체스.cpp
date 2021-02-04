#include <iostream>
using namespace std;

/*체스에서 룩은 기물로 막혀있지 않으면 룩의 위치에서 같은 열,행에 해당하는 칸 중 하나로 이동가능
  8X8 체스판의 상태를 입력한다, 0은 기물이 없는상태, 1은 킹, 2는 상대 룩(최대 2개), 
  3은 그 외 다른 기물
  만약 킹이 잡힐 가능성이 있으면 1, 없으면 0을 출력 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[9][9], ky=0, kx=0, ry, rx, cnt=1, ry2, rx2, result=0;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) { //King Coordinate
				ky = i;
				kx = j;
			}
			if (arr[i][j] == 2) { //rook Coordinate
				ry = i, rx = j;
				cnt++;
			}
			if (cnt == 2) {
				if (arr[i][j] == 2)
					ry2 = i, rx2 = j;
			}
		}
	}
	for (int i = rx + 1; i < 9; i++) {
		if (arr[ry][i] == 1) result = 1;
		else if (arr[ry][i] == 3) break;
	}
	for (int i = rx - 1; i > 0; i--) {
		if (arr[ry][i] == 1)result = 1;
		else if (arr[ry][i] == 3) break;
	}
	for (int i = ry + 1; i < 9; i++) {
		if (arr[i][rx] == 1) result = 1;
		else if (arr[i][rx] == 3) break;
	}
	for (int i = ry - 1; i > 0; i--) {
		if (arr[i][rx] == 1) result = 1;
		else if (arr[i][rx] == 3) break;
	}

	cout << result;
}