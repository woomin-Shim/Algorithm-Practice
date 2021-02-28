#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100000];
	cin.getline(str, 100000, '\n');
	int len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		int ascii = int(str[i]);
		if (ascii != 32)
			cout << str[i];
		//if (!(str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122))
			//str[i] = '\0';
	}
	return 0;
}