#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[21][21], ch[10], n, cnt=0;
/*
0 1 1 1 0
1 0 1 0 1
0 0 0 1 0
0 1 0 0 1
0 0 0 0 0
*/
void dfs(int r) {
	if(r == n) cnt++;
	else {
		for(int i=1; i<=n; i++) {
			if(map[r][i]==1 && ch[i]==0) {
				ch[i] = 1;
				dfs(i);
				ch[i] = 0;
			}   
		}
	}
}
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int a, b, m;
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	
	ch[1] = 1;
	dfs(1);
	
	cout << cnt;
}
