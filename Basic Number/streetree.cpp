#include <iostream>
#include <vector>
using namespace std;

/* BOJ 2485
최대공약수를 이용한 문제이다.
가로수의 간격 들을 모두 구한 후 간격끼리의 최대 공약수를 구한다.
제일 첫 가로수와 마지막 가로수 길이의 차를 구해서 최대 공약수로 나누면 있어야 하는 모든 가로수의 수가 나온다.
거기서 n 을 빼주면 새로 심어야 하는 가로수의 수를 알 수 있다.
*/

vector<int> v;
vector<int> v2;

int Gcd(int a, int b) {
	while (1) {
		int rest = a % b;
		if (rest == 0) {
			return b;
			break;
		}
		a = b;
		b = rest;
	}
}

int main() {
	int n;
	long long int tree;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree;
		v.push_back(tree);
		if (i > 0) {
			v2.push_back(v[i] - v[i - 1]);
		}
	}
		
	int gcd = v2[0];
	for (int i = 1; i < v2.size(); i++) {
		gcd = Gcd(gcd, v2[i]);
	}

	cout << (v[n-1] - v[0]) / gcd - n + 1;
	
	
}