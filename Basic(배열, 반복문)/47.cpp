#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, cnt=0;
	cin >> n;
	vector<vector<int>> v(n+2, vector<int>(n+2, 0));
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> v[i][j];
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(v[i][j] > v[i-1][j] && v[i][j] > v[i+1][j] && v[i][j] > v[i][j-1] && v[i][j] > v[i][j+1] )
				cnt++;
		}
	}
	
	cout << cnt;
	/*
	for(int i=0; i<=n+1; i++) {
		for(int j=0; j<=n+1; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	
	
}
	 

