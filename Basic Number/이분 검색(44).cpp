#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int count(int middle, vector<int> v) {
	int cnt=1, tmp=1;
	for(int i=2; i<=n; i++) {
		if(v[i]-v[tmp] >= middle) {
			cnt++;
			tmp = i;
		}
	}
	return cnt;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int c, tmp, res=0;
	cin >> n >> c;
	vector<int> v(n+1);

	for(int i=1; i<=n; i++) cin >> v[i];
	int lt=1, rt=v[n], mid;
	sort(v.begin(), v.end());

	while(lt <= rt) {
		mid = (lt+rt) / 2;
		
		if(count(mid, v) >= c) {
			lt = mid+1;
			res = mid;
		}
		else rt = mid - 1;
	}
	
	cout << res;

}
	 

