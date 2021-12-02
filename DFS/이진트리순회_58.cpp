#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//후위 순회 
void dfs(int num) {
	if(num > 7) return;
	else {
		dfs(num * 2);
		dfs(num*2+1);
		cout << num << ' ';
				
	}
}
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	dfs(1);
}
	 
