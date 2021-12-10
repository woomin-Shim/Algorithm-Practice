#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ch[30], cnt=0, tmp=0;
int map[30][30], cost[30][30];
int minn=100000;

void dfs(int v) {
	if(v==n) {
		if(tmp < minn) {
			minn = tmp;
		}
	}
	else {
		for(int i=1; i<=n; i++) {
			if(map[v][i]==1 && ch[i]==0) {
				ch[i]=1;
				tmp += cost[v][i];
				dfs(i);
				ch[i] = 0;
				tmp -= cost[v][i];
			}
		}
	}
}
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	
	int m, a, b, c;
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		cin >> a >> b >> c;
		map[a][b] = 1;
		cost[a][b] = c;
	}
	
	ch[1] = 1;
	dfs(1);
	cout << minn;
}
