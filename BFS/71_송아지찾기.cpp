#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ch[10001], dx[3]={1, -1, 5}, cost[10001];
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	
	int s, e;
	cin >> s >> e;
	queue<int> Q;
	Q.push(s);
	ch[s]=1;
	while(1) {
		int x = Q.front(); //5
		Q.pop();
		for(int i=0; i<3; i++) {
			int tmp = x+dx[i]; //6 4 10
			if(ch[tmp]==0) {
				ch[tmp]=1;
				Q.push(tmp);
				cost[tmp] = cost[x]+1;
			}
			if(tmp==e) {
				cout << cost[tmp];
				exit(0);
			}
		}
	}

}
