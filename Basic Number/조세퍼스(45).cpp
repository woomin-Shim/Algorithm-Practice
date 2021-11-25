#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, k, cnt=0, res=0, bp=0;
	cin >> n >> k;   // 8  3 
	vector<int> v(n+1), p(n+1);

	while(1) {
		for(int i=1; i<=n; i++) {
			if(p[i] == 0) cnt++;
			if(cnt==k) {
				p[i]=1;
				cnt=0;
				bp++;  //break point 
			}
		}
		if(bp==n-1) break;
	}
	
	for(int i=1; i<=n; i++) {
		if(p[i]==0) {
			cout << i;
			exit(0);
		}
	}
	

}
	 

