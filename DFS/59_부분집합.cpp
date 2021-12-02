#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[20];
 
void dfs(int L) {
	if(L == n+1) {
		for(int i=1; i<=n; i++) {
			if(arr[i]==1) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
	else {
		arr[L] = 1;
		dfs(L+1);
		arr[L] = 0;
		dfs(L+1);
	}
}
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	dfs(1);
}
	 
