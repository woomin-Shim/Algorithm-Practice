#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num=1, result = 2, cnt=0, i=1;
	cin >> n;

	while (1) {
		if (num == n)break;
		num++;

		cnt++;
		if (cnt == (6 * i)+1) {
			cnt = 0;
			result++;
			i++;
		}

	
	}
	if (n == 1) cout << 1;
	else cout << result;
	


}