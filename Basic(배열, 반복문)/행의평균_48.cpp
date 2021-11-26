#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);

	vector<vector<int>> v(9, vector<int>(9, 0));
	int tmp, tot, avg, res;
	
	for(int i=0; i<9; i++) {
		tot = 0, avg=0;
		
		for(int j=0; j<9; j++) {
			cin >> v[i][j];
			tot += v[i][j];   
		}
		avg = (tot/9.0) + 0.5;
		cout << avg << ' ';
		
		int min = 217000;
		for(int j=0; j<9; j++) {
			int sub = abs(avg - v[i][j]);
			if(sub < min) {
				min = sub;
				res = v[i][j];
			}
			else if(sub==min) {
				res = (res>v[i][j])? res : v[i][j];
			}
		}
		cout << res << '\n';	
	}
}
	 

