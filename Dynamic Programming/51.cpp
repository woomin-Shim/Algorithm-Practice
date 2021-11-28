#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);

	int h, w, n, m, max=0, tot=0;
	cin >> h >> w;
	vector<vector<int>> v(h+1, vector<int>(w+1, 0));
	vector<vector<int>> dp(h+1, vector<int>(w+1, 0));
	for(int i=1; i<=h; i++) {
		for(int j=1; j<=w; j++) {
			cin >> v[i][j];
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + v[i][j];
		}
			
	}
	cin >> n >> m;
	
	for(int i=n; i<=h; i++) {
		for(int j=m; j<=w; j++) {
			int tmp = dp[i][j] - dp[i-n][j] - dp[i][j-m] + dp[i-n][j-m];
			if(max < tmp) max = tmp;
		}
	}
	
	cout << max;
}
	 

