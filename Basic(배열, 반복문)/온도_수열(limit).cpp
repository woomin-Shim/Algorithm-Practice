#include <iostream>
#include <vector>
using namespace std;

//time limit 1sec (complexity O(N))
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k, sum=0, max=-2147000, cnt=0, idx=1;
	cin >> n >> k;
	vector<int> temp(n);
	for(int i=0; i<n; i++) {
		cin >> temp[i];
	}
	
	for(int i=0; i<n; i++) {
		if(i<k) sum+=temp[i];
		else sum += temp[i] - temp[i-k];
		if(i>=k && max < sum) {
			max = sum;	
		}
	}
	cout << max;
}

