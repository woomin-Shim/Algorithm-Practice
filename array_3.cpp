#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, plus = 1, plus2 = 0;
	int jnum = 0, inum = 1;
	cin >> n;
	int arr[5][5];
	arr[0][0] = 1;
	for (int i = 0; i < n; i++) {
		jnum += plus;
		arr[i][0] = jnum;
		plus++;
		plus2 =i+1;
		inum = arr[i][0];
		for (int j = 1; j < n - i; j++) {
			inum = inum + plus2;
			arr[i][j] = inum;
			plus2++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}