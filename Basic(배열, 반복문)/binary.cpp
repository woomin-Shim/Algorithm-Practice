#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	while (n > 0) {
		int rest = n % 2;
		v.push_back(rest);
		n /= 2;
	}
	for (int i = v.size()-1; i >=0; i--)
		cout << v[i];
}