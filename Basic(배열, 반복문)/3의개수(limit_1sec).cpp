#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, cnt=0, left, right, cur=0, k=1;
	cin >> n;
	int tmp = n;
	while(left != 0) {
		cur = tmp%10;
		left = tmp/10;
		tmp /= 10;
		right = n%k;
		
		if(cur > 3) cnt += (left+1)*k;
		else if(cur < 3) cnt += left*k;
		else if(cur==3) cnt += (left*k)+(right+1);
		
		k *= 10;
	}
	
	cout << cnt;
}



