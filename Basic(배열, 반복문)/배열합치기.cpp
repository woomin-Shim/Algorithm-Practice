#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, arr1[100], arr2[100], result[200];
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr1[i];
	cin >> m;
	for(int i=0; i<m; i++) cin >> arr2[i];
	
	int p1=0, p2=0, p3=0, tmp;
	
	while(p1<n && p2<m) {
		if(arr1[p1] < arr2[p2]) {
			tmp = arr1[p1++];
		}
		else {
			tmp = arr2[p2++];
		}
		result[p3++] = tmp;
	}
	
	while(p1<n) result[p3++] = arr1[p1++];
	while(p2<m) result[p3++] = arr2[p2++];
	
	for(int i=0; i<n+m; i++) cout << result[i] << ' ';
	
}
	 




