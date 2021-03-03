#include <iostream>
#include <cstring>
using namespace std;


int main() {
	char str[100][100], tmp[100];
	int n;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (strcmp(str[i], str[j]) > 0) {
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << str[i] << '\n';
	}
	
}