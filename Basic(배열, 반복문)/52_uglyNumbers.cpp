#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector <int> v(n,1);
	
	int p1=0, p2=0, p3=0;
	for(int i=1; i<n; i++) {
		int min = 0;
		if(v[p1]*2 < v[p2]*3) {
			min = v[p1]*2;
		}
		else min = v[p2]*3;
		if(v[p3]*5 < min) min = v[p3]*5;
		
		v[i] = min;
		if(v[p1]*2 == min) p1++;
		if(v[p2]*3 == min) p2++;
		if(v[p3]*5 == min) p3++;
	}
	
	cout << v[n-1];
}
	 

