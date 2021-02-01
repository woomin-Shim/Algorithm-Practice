#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, S;
	cin >> N >> S;
	int arr[100][100];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * (1 + i) - 1; j++) {
			arr[i][j] = S++;
			if (S == 10) S = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N - 1; j++) {
			cout << ' ';
		}
		if ((i + 1) % 2 == 0) {//Even
			for (int k = 0; k < 2 * (1 + i) - 1; k++)
				cout << arr[i][k];
		}
		else { //Odd 
			int cnt = 2 * (i + 1) - 1;
			for (int z = cnt - 1; z >= 0; z--)
				cout << arr[i][z];
		}
		cout << "\n";
	}
}