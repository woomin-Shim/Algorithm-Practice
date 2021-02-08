#include <iostream>
using namespace std;

/*5x5 2차원 배열이 주어질 때 어떤 원소가
  상하좌우에 있는 원소보다 작을 때 해당 위치에 *을 표시*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[7][7];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i == 0 || i == 6 || j == 6 || j == 0)
				arr[i][j] = 9;
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j + 1] &&
				arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j - 1])
				cout << "*" << ' ';
			else cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}


	/*
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i >= 1 && i <= 5 && j >= 1 && j <= 5) {
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j + 1] &&
					arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j - 1])
					cout << "*" << ' ', j++;
				if (j < 6)
					cout << arr[i][j] << ' ';
			}
		}
		if(i>0) cout << "\n";
	}
	*/

}