#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, k, pos=0, res, tmp=0, idx, tot=0;
	cin >> n;
	vector<int> v(n+1);
	for(int i=1; i<=n; i++) {
		cin >> v[i];
		tot += v[i];
	}
	cin >> k;
	
	if(k>=tot) {
		cout << "-1";
		return 0;
	}
	
	while(1) {
		pos++;
		if(pos>n) pos=1;
		if(v[pos]==0) continue;
		v[pos]--;
		tmp++;
		if(tmp==k) break;
	}
	
	while(1) {
		pos++;
		if(pos>n) pos=1;
		if(v[pos]!=0) break;
	}
	cout << pos;
}
	 

