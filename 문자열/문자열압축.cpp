#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[1001];
	int cnt[1001];
	fgets(s, 1001, stdin);
	int len = strlen(s);
	int sum = 1;
	for (int i = 0; i < len; i++) {
		if (s[i] == s[i + 1]) {
			sum++;
		}
		else {
			if (sum == 1)
				cout << s[i];
			else {
				cout << sum << s[i];
				sum = 1;
			}
		}
	}
}