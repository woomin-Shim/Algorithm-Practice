#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ch[30], tmp=0;
vector<pair<int,int>> map[30];
int res=100000;

void dfs(int v, int sum) {
	if(v==n) {
		if(sum<res) res=sum;
	}
	else {
		for(int i=0; i<map[v].size(); i++) {
			if(ch[map[v][i].first]==0) {
				ch[map[v][i].first]=1;
				dfs(map[v][i].first, sum+map[v][i].second);
				ch[map[v][i].first]=0;
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
		map[a].push_back({b, c});
	}
	
	ch[1] = 1;
	dfs(1, 0);
	cout << res;
}
