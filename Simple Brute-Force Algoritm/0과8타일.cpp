#include <iostream>
using namespace std;

/*N:행, M:열
  N과M이 주어지면 각 행과열에 맞게 0과 8을 입력하면
  좌우로 뒤집어진 행렬을 출력*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--)
			cout << arr[i][j] << ' ';
		cout << "\n";
	}
		
}