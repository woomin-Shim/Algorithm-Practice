#include <iostream>
using namespace std;

/*행렬에 쓰여진 81개의 자연수가 주어질 때 
  이들 중 최대값을 찾고 몇행 몇열인지 출력 
  최대값이 여러값일 경우 행열이 가장 작은 곳으로 출력*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[9][9];
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	}

	int big = 0, ry, rx; //ry 행, rx열 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] > big) {
				big = arr[i][j]; //Max
			}
		}
	}
	int mat_i[9] = { 9 }, mat_j[9] = { 9 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j]==big) {
				mat_i[i] = i;
				mat_j[j] = j;
			}
		}
	}
	int min_i = 100, min_j = 100;
	for (int i = 0; i < 9; i++) {
		if (min_i > mat_i[i])
			min_i = mat_i[i];
		if (min_j > mat_j[i])
			min_j = mat_j[i];
	}
	cout << big << "\n";
	cout << min_i+1 << ' ' << min_j+1;

}