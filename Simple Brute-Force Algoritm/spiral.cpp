#include <iostream>
using namespace std;

int arr[30][30];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num = 0, row = 0, column = -1, buho = 1;
	cin >> n; 

	int x = n, y = n;
	while (1) {
		for (int i = 0; i < x; i++) {
			num++;
			column += buho;
			arr[row][column] = num;
			
			
		}
		x--;
		y--;
		
		for (int j = 0; j < y; j++) {
			num++;
			row += buho;
			arr[row][column] = num;
						
		}
		
		buho *= -1;

		if (x<0 || y<0) break;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}