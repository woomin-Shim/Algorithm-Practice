#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	vector <int> v(n);
	
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	int lt=0, rt=n-1, mid;
	while(lt <= rt) {
		mid = (lt+rt)/2;
		
		if(v[mid] == m) {
			cout << mid+1;
			return 0;
		}
		else if(v[mid] > m) rt = mid-1;
		else if(v[mid] < m) lt = mid+1;
	}	
}
	 

