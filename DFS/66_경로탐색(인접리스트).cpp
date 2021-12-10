#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ch[30], cnt=0;
vector<int> map[30];

void dfs(int v) {
	if(v==n) cnt++;
	else {
		for(int i=0; i<map[v].size(); i++) {
			if(ch[map[v][i]]==0) {
				ch[map[v][i]]=1;
				dfs(map[v][i]);
				ch[map[v][i]]=0;
			}
		}
	}
}
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	
	int m, a, b;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		map[a].push_back(b); //2 3 4 
	}
	
	ch[1]=1;
	dfs(1);
	
	cout << cnt;
	
}
