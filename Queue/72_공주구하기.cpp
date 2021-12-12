#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ch[1001];
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	
	int n, k, pos=0, cnt=0, res=0;
	cin >> n >> k;  //8 3;
	queue<int> Q;
	for(int i=1; i<=n; i++) {
		Q.push(i);
	}
	
	while(!Q.empty()) {
		int x = Q.front();
		for(int i=1; i<k; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		Q.pop();
		if(Q.size()==1) {
			cout << Q.front();
			exit(0);
		}
	}
	
	
}
