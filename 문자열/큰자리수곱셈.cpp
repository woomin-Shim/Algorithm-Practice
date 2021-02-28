#include <iostream>
#include <cstring>
using namespace std;

char str[200];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num[200] = { 0, }, num2[200] = { 0, };

	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		num[199 - len + i + 1] = str[i] - '0';
	}

	cin >> str;
	int len2 = strlen(str);
	for (int i = 0; i < len2; i++) {
		num2[199 - len2 + i + 1] = str[i] - '0';
	}

	int result[400] = { 0, };

	for (int i = 199; i > 0; i--) {
		int t = 0;
		for (int j = 199; j > 0; j--) {
			result[i - t] += (num[j] * num2[i]);
			if (result[i] > 9) {
				result[i - 1 - t] += result[i - t] / 10;
				result[i - t] = result[i - t] % 10;
			}
			t++;
		}

	}



	for (int i = 0; i < 200; i++) {
		if (result[i] != 0) {
			for (int j = i; j < 200; j++) cout << result[j];
			return 0;
		}
	}

}