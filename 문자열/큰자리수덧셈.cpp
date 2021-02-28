#include <iostream>
#include <cstring>
using namespace std;

char str[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num[105] = { 0, }, num2[105] = { 0, };

	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		num[104 - len + i + 1] = str[i] - '0';
	}

	cin >> str;
	//cin.getline(str, 105, '\n');
	int len2 = strlen(str);
	for (int i = 0; i < len2; i++) {
		num2[104 - len2 + i + 1] = str[i] - '0';
	}

	int result[105] = { 0, };
	for (int i = 104; i > 0; i--) {
		int sum = num[i] + num2[i];
		if (sum >= 10) {
			num[i - 1]++;
			result[i] = sum % 10;
		}
		else if (sum < 10) {
			result[i] = sum;
		}
	}

	for (int i = 0; i < 105; i++) {
		if (result[i] != 0) {
			for (int j = i; j < 105; j++) cout << result[j];
			return 0;
		}
	}
}