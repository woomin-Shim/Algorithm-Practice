#include <iostream>
using namespace std;

//소인수 분해하기 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 2; n != 1;) {  //n>1
		if (n % i == 0) {
			cout << i << ' ';
			n /= i;
		}
		else i++;
	}
	cout << "\n";
	return 0;

}