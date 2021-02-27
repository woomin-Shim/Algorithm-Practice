#include <iostream>
using namespace std;

int info[105][3];  // number, strike, ball 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> info[i][0] >> info[i][1] >> info[i][2];
	}


	for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			for (int c = 1; c <= 9; c++) {

				if (a != b && a != c && b != c) {
					bool isTrue = true;
					for (int i = 0; i < n; i++) {
						int strike = 0, ball = 0;
						int first = info[i][0] / 100;
						int second = (info[i][0] / 10) % 10;
						int third = info[i][0] % 10;

						if (a == first) strike++;
						if (b == second) strike++;
						if (c == third) strike++;

						if (a == second || a == third) ball++;
						if (b == first || b == third) ball++;
						if (c == first || c == second) ball++;

						if (info[i][1] != strike || info[i][2] != ball) isTrue = false;
					}
					if (isTrue == true) result++;
				}

			}
		}
	}
	cout << result << "\n";
	return 0;
}



