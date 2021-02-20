#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c, k;
	cin >> r >> c;   // 7  6 
	cin >> k;

	int coordinate[2] = { 1, 0 };
	int n = 1, num=0;
	if (k > r * c) {
		cout << 0;
	}
	else {
		while (1) {
			for (int i = 0; i < c; i++) {
				coordinate[1] += n;  //한칸씩 위로, 아래로 
				num++;
				if (k == num) {
					cout << coordinate[0] << ' ' << coordinate[1] << "\n";
					return 0;
				}
			}
			r -= 1;
			c -= 1;
			for (int i = 0; i < r; i++) { // 오른쪽으로, 왼쪽으로 
				coordinate[0] += n;
				num++;
				if (k == num) {
					cout << coordinate[0] << ' ' << coordinate[1] << "\n";
					return 0;
				}
			}

			n *= -1; //부호를 변경시켜 위, 아래, 오른쪽, 왼쪽으로 가도록 
		}
	}
}