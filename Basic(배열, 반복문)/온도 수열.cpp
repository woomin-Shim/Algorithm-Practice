#include <iostream>
#include <vector>
using namespace std;


int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k, sum=0, max=-2147500, cnt=0, idx=1;
	cin >> n >> k;
	vector<int> temp(n);
	for(int i=0; i<n; i++) {
		cin >> temp[i];
	}
	
	for(int i=0; i<=n-k; i++) {
		sum = 0;
		for(int j=i; j<i+k; j++) {
			sum += temp[j];
		}
		if(max < sum) max = sum;
		sum=0;
	}
	

	cout << max;
}

