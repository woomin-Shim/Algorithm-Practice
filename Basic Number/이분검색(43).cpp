#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1001], n;

int count(int middle) {
		int sum = 0, cnt=0;
		for(int i=0; i<n; i++) {
			if(sum+a[i] > middle) { //1 3 
				cnt++;
				sum=a[i];
			}
			else {
				sum = sum+a[i];  // 1 3 6 10 16 21 
			}
		}
		if(sum <= middle) cnt++;
		return cnt;
}
	
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int m, lt=1, rt=0, mid, res=0, max=-2147;
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> a[i];  //1 2 3 4 5 6 7 8 9 
		rt = rt + a[i];	
		if(a[i] > max) max = a[i];
	}

	
	while(lt <= rt) {
		mid = (lt+rt) / 2;
		
		if(mid>=max && count(mid) <= m) { 
			res = mid;
			rt = mid - 1;
		}
		else {
			lt = mid+1;
		}
		
	}
	
	cout << res;
	
	
}
	 

