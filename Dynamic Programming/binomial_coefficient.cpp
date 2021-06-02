#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 100

int min(int a, int b) {
	return (a < b) ? a : b;
}
//이항 계수
int bin_coef_DP(int n, int k) {
	int c[MAX][MAX];
	int m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i,k); j++)
			if (j == 0 || j == i) 
				c[i][j] = 1;
			else 
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	return c[n][k];
}

int main() {
	int result = bin_coef_DP(6, 3);
	cout << result;
}