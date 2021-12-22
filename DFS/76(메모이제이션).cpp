#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, r;
int dy[21][21];

int dfs(int a, int b) {
	if(dy[a][b]>0) return dy[a][b];
	if(a==b || b==0) return 1;
	else {
		return dy[a][b] = dfs(a-1, b-1) + dfs(a-1,b);
	}
}
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> r;
	cout << dfs(n, r);
}
