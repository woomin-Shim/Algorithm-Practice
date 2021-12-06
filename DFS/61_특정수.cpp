#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[20], cnt=0, tot=0; 
void dfs(int l, int sum) {
	if(l==n+1) {
		if(sum==m) {
			cnt++;
		}
	}
	else {
		dfs(l+1, sum+a[l]);
		dfs(l+1, sum-a[l]);
		dfs(l+1, sum);
	}
}
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	dfs(1, 0); //level, sum
	
	cout << cnt;
}
