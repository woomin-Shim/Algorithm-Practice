#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int data[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];

	for (int i = 0; i<n; i++) {
		//i가 가리키고 있는 값을 넣어야 한다. 단, i왼쪽은 모두 정렬 
		
		//j의 범위는 i부터 첫번째 숫자까지(0번째 숫자 x : 앞의 숫자와 비교하기 때문에)
		for (int j = i; j > 0; j--) {
			if (data[j] < data[j - 1]) {
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
			else break;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << data[i] << ' ';
	}
}