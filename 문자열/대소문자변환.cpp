#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[1001];
	fgets(str, 1001, stdin);
	//cin.getline(str, 1001, '\n');
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (isalpha(str[i])) {
			if (str[i] < 97) {
				str[i] = str[i] + 32;
			}
			else if (str[i] >= 97) {
				str[i] = str[i] - 32;
			}
		}
	}

	for (int i = 0; i < len; i++) {
		cout << str[i];
	}
}