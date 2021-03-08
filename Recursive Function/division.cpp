#include <iostream>
using namespace std;
/*자연수 n을 입력 받아 이를 n보다 작은 자연수들의 합으로 나타내는 방법을 모두 출력하는 
프로그램을 재귀 호출을 사용하여 작성*/

//!!!!!! Wrong ---> Time limit exceed

int n;
int arr[100];
int result = 0;

void division(int x, int idx) {  //arr[idx]번째까지의 합이 x라면 print
	if (idx>n)  // *** NOT idx>=n
		return;

	int cnt = 0;
	for (int i = 0; i < idx; i++) {
		cnt += arr[i];
	}

	//if(cnt > n) return;  ??

	if (cnt == n) {
		for (int i = 0; i < idx; i++) {
				if (!(i == idx - 1)) cout << arr[i] << "+";
				else cout << arr[i];
		}
		result++;
		cout << "\n";
	}
	else {
		for (int i = x; i > 0; i--) {   // 0 1 2 3 
			arr[idx] = i;                   // 3 3 3 3 

			
			//if (idx>0 && arr[idx - 1] < arr[idx]) continue;
			division(i, idx + 1);

		}
	}
}
int main() {
	cin >> n;
	division(n-1, 0);
	cout << result;
	return 0;
}