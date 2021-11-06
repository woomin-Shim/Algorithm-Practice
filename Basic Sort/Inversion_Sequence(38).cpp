#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, n, idx=0;
	
	cin >> n;
	vector <int> is(n+1), os(n+1);  // inversion sequence, original sequence

	for(i=1; i<=n; i++) cin >> is[i];
	
	for(i=n; i>0; i--) {
		int idx = i;
		for(j=0; j<is[i]; j++) {
			os[idx] = os[idx+1];
			idx++;
		}
		os[idx] = i;
	}
	
	for(i=1; i<=n; i++) cout << os[i] << ' ';
	
	
}
	 




