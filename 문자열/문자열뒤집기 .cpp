#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[1000];
	cin.getline(s, 1000, '\n');
	int len = strlen(s);
	for (int i = 0; i < len ; i++) {
		cout << s[len - i-1];
	}
}
