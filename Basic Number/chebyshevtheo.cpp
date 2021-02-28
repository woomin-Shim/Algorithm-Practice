#include <iostream>
#include <math.h>
using namespace std;

/* 베르트랑-체비쇼프 정리는 임의의 자연수 n에 대하여 n보다 크고 2n보다 작거나 같은 소수는
* 적어도 하나 존재한다는 내용을 담고 있다.
* n이 주어졌을 떄 n보다 크고, 2n 보다 작거나 같은 소수의 개수를 구하는 프로그램 작성 
*/

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int n;

	while (1) {
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		for (int i = n+1; i <= 2 * n; i++) {
			if (isPrime(i))
				cnt++;
		}
		cout << cnt << "\n";
	}



}