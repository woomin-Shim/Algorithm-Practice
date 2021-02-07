#include <iostream>
using namespace std;

/*각 열마다 1*4의 격자가 들어갈 수 있는지 먼저 검사 후 
  들어가지 못하면 0을 출력하고 들어가게 되면 그 열을 1로 채우고 
  모든 행렬을 검사하여 만족하는 수평선의 개수를 세면 된다. 
  중요한 것은 1로 채우고 난후 수평선의 개수를 세고 다시 1로 채운 부분을 0으로 초기화해야함 */
int map[20][20];
int arr[20];
int num[20];
int main() {
	int c, r;
	cin >> c >> r;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}

	int X = 0, Y = 0;
	for (int i = 1; i <= c; i++) {//row   c:6 r:7
		int cnt = 0;
		for (int j = 1; j <= r; j++) { //column
			if (map[j][i] == 1) {
				break;
			}
			else {
				cnt++;
			}
			arr[i] = cnt;   // 2 2 2 7 4 2
		}
	}

	for (int i = 1; i <= c; i++) {
		if (arr[i] < 4) {
			X = 0; Y = 0;
		}
		else {
			for (int j = 1; j <= arr[i]; j++)
				map[j][i] = 1;
			for (int k = 1; k <= r; k++) {  //1로 채우고 수평선의 개수를 num[]에 담는다. 
				int sum = 0;
				for (int p = 1; p <= c; p++) {
					sum += map[k][p];
				}
				if (sum == c) num[i]++;
			}
			for (int j = 1; j <= arr[i]; j++)  //1로 채웠던 부분을 0으로 다시 초기화 
				map[j][i] = 0;
		}
	}
	int big = num[0];
	for (int i = 1; i <= c; i++) {
		if (big < num[i])
			big = num[i], X = i;
	}
	
	cout << X << ' ' << big << "\n";
}