#include <iostream>
using namespace std;
/*두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램(내림차순)*/

int n, k;
int arr[100];
bool TF[100];


void tobin(int x, int y) {  // x번째 for문에 1 or 0 
	if (y == 0) {
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
		cout << "\n";
	}
	else {
		for (int i = x; i < n; i++) {
			arr[i] = 1;
			tobin(i+ 1, y - 1);
			arr[i] = 0;
		}
	}
	
}
int main() {
	cin >> n >> k;
	tobin(0, k);
}