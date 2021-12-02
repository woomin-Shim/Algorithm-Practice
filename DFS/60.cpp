#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, sum, tot=0;
int ch[20], a[20];
bool flag =false;

 
void dfs(int L) {
	if(flag==true) return;
	if(L==n+1) {
		for(int i=1; i<=n; i++) {
			if(ch[i]==1) {
				tot += a[i];
			}
		}
		if(tot==(sum-tot)) cout << tot, flag = true;
		tot = 0;
	}
	else {
		ch[L] = 1;
		dfs(L+1);
		ch[L] = 0;
		dfs(L+1);
	}
}
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	dfs(1);
	if(flag) cout << "YES";
	else cout << "NO";
}
	 
