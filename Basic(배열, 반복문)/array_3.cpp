#include <iostream>
using namespace std;

int main() {
	int n, c,  x, y, num=1;
	cin >> n;

	int** arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[n];
	
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			arr[i][j] = 0;
		}
	} */

	for (int i = 0; i < n; i++) {
		x = i;
		y = 0;
		for (int j = 0; j <= i; j++) {
			arr[y][x] = num;
			num++;
			y++;
			x--;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++)
			cout << arr[i][j] << ' ';
		cout << "\n";
	}
	
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

}
