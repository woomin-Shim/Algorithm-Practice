#include <iostream>
using namespace std;

//Time Limit 1second
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, d=9, c=1, res=0, sum=0;
	cin >> n;
	
	while(sum+d<n) {
		res = res + (c*d);
		c++;
		sum += d;
		d *= 10;
	}
	res = res+(n-sum)*c;
	
	cout << res;
	
}




