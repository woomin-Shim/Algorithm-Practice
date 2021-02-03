#include <iostream>
#include <math.h>
using namespace std;

/*n까지의 소수들 모두 구하기
  제곱근까지만 구하여도 소수를 판별가능하다.
  예를 들어 25는 5*5, 1*25인 반면 16은 4*4, 2*8로 제곱근보다 작은수에서 나눠지게 됨 
  */

bool isPrime(int num) {
	if (num <= 1) return false;
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		if (isPrime(i))
			cout << i << ' ';
	}

}