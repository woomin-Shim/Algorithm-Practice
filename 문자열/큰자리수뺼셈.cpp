#include <iostream>
#include <cstring>
using namespace std;

/*두 자연수가 주어질 때 그들의 뺄셈을 계산하는 프로그램을 작성하시오. 
각 수는 1 이상 10의 100승 미만의 범위를 가진다.  */
char str[105];
int main() {
	cin.getline(str, 1000, '\n');
	int first[105] = { 0, };
	int f_len = strlen(str);
	/*            101 102 103 104
	   ...0 0 0 0  1    2   3   4   */
	for (int i = 0; i < f_len; i++) {
		first[104 - f_len + i + 1] = str[i] - '0';  //문자열을 정수형으로 변경시키기 위해 -'0'
	}

	cin >> str;
	int second[105] = { 0, };
	int s_len = strlen(str);
	for (int i = 0; i < s_len; i++) {
		second[104 - s_len + i + 1] = str[i] - '0';
	}

	int compare = -1;
	if (f_len > s_len) {
		compare = 1;
	}
	else if (f_len < s_len) {
		compare = 0;
	}
	else {  //same length
		for (int i = 0; i < 105; i++) {
			if (first[i] > second[i]) {
				compare = 1;
				break;
			}
			else if (first[i] < second[i]) {
				compare = 0;
				break;
			}
		}
	}

	int big[105] = { 0, }, small[105] = { 0, };
	bool flag = false; //to distinguish negative, positive
	if (compare == 1) {
		for (int i = 0; i < 105; i++) big[i] = first[i];
		for (int i = 0; i < 105; i++) small[i] = second[i];
	}
	else if (compare == 0) {
		for (int i = 0; i < 105; i++) big[i] = second[i];
		for (int i = 0; i < 105; i++) small[i] = first[i];
		flag = true;
	}
	else {
		cout << 0;
		return 0;
	}

	int result[105] = { 0, };

	for (int i = 104; i > 0; i--) {
		if (big[i] >= small[i]) {
			result[i] = big[i] - small[i];
		}
		else if (big[i] < small[i]) {
			big[i - 1]--;
			big[i] += 10;
			result[i] = big[i] - small[i];
		}
	}

	if (flag) cout << "-";  //negative
	for (int i = 0; i < 105; i++) {
		if (result[i] != 0) {
			for (int j = i; j < 105; j++) {
				cout << result[j];
			}
			return 0;
		}
	}
}