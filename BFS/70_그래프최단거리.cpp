#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int front=-1, rear=-1, ch[30],cnt[30], n;
vector<int> map[30];
queue<int> Q;
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	
	int a, b, x, m, num=1;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	}
	Q.push(1);
	ch[1]=1;
	while(!Q.empty()) {
		x = Q.front();
		Q.pop();
		for(int i=0; i<map[x].size(); i++) {
			if(ch[map[x][i]]==0) {
				ch[map[x][i]]=1;
				Q.push(map[x][i]);	
				cnt[map[x][i]] = cnt[x]+1; 
			}
		}	
	}
	
	for(int i=2; i<=n; i++) {
		cout << cnt[i] << ' ';
	}
}
