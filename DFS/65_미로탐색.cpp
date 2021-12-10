#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[10][10], ch[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt=0;

void dfs(int x, int y) {  // 1 1 
	if(x==7 && y==7) cnt++;
	else {
		for(int i=0; i<4; i++) {
			int xx = x+dx[i];
			int yy = y+dy[i];
			if(xx < 1 || xx > 7 || yy < 1 || yy > 7) continue;
			if(map[xx][yy]==0 && ch[xx][yy]==0) {
				ch[xx][yy]=1;
				dfs(xx, yy);
				ch[xx][yy]=0;
			}
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	for(int i=1; i<=7; i++) {
		for(int j=1; j<=7; j++) {
			cin >> map[i][j];
		}
			
	}
	
	ch[1][1]=1;
	dfs(1, 1);
	cout << cnt;
	
}
