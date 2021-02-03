#include <iostream>
using namespace std;

/*k번째로 작은 N의 약수 구하기*/
int main() {
	int N, K, cnt=0;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			cnt++;
			if (cnt == K)
				cout << i;
		}
		if (cnt == 0) cout << 0;
	}
}