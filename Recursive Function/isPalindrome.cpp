#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char s[], int start, int end) {
	// if s[] is from the start to the end of a palindrome == true,  else == false

	//cout << start << ' ' << end << "\n";  (기저조건 확인하기 위해 debuging) 

	if (start == end) {
		return true;
	}
	else {
		if (s[start] == s[end]) {
			return isPalindrome(s, start + 1, end - 1);
		}
		else
			return false;
	}
}
int main() {
	char s[10000];
	cin.getline(s, 10000, '\n');

	int len = strlen(s);
	
	if (isPalindrome(s, 0, len-1))
		cout << "YES";
	else
		cout << "NO";
}