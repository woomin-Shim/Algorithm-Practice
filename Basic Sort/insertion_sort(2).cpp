#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int s, n, i, j;
	cin >> n;
	vector<int> v(n);
	
	for(i=0; i<n; i++) {
		cin >> v[i];
	}
	
	for(i=1; i<n; i++) {    // 2 3 #1# 5 10 9 8
		int tmp = v[i];
		for(j=i-1; j>=0; j--) {
			if(tmp < v[j]){
				v[j+1] = v[j];
			}
			else break;
		}
		v[j+1] = tmp;
	}
	
	for(i=0; i<n; i++) cout << v[i] << ' ';
}




