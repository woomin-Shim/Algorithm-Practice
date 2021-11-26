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

	int n,j, tot=0;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<int> front(n), right(n);
	
	for(int i=0; i<n; i++) 	cin >> front[i];  //2 0 3 1  00 01 02 03
	for(int i=0; i<n; i++) 	cin >> right[i];  //1 1 2 3  00 01 02 03 
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(right[n-i-1] < front[j]) {
				v[i][j] = right[n-i-1];
			}
			else {
				v[i][j] = front[j];
			}
			tot += v[i][j];
		}
	}
	
	cout << tot << '\n';

}
	 

