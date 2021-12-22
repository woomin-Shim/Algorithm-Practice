#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int unf[1001];

int find(int v) {
	if(v==unf[v]) return v;
	else {
		return unf[v] = find(unf[v]);
	}
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if(a!=b) unf[a] = b;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m, a, b;
	cin >> n >> m;
	for(int i=1; i<=n; i++) unf[i]=i;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		Union(a, b);
	}
	
	int n1, m1;
	cin >> n1 >> m1;
	if(find(n1)==find(m1)) cout << "YES";
	else cout << "NO";
	
	

	
}
