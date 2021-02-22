#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[1001];
	string str;
	//fgets(s, 1001, stdin);   abcba-> len=6;
	cin.getline(s, 1001, '\n');  //len = 5;
	int len = strlen(s);
	
	for (int i = 0; i < len; i++) {
		if (s[i] == s[len - i - 1])
			str = "yes";
		else
			str = "no";
	}
	cout << str;
}
//a a b b f c b b a a
//  0 1 2 3 4 5 6 7 8 9