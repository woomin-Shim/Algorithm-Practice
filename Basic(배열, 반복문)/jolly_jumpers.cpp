#include <iostream>
#include <vector>
using namespace std;


int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, num, pre, tmp=0, flag=0, idx=0;
	cin >> n;
	vector<int> v(n), sub(n), cnt(n);
	
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	for(int i=1; i<n; i++) {
		sub[idx] = v[i] - v[i-1];
		if(sub[idx]<0) sub[idx] *= -1;
		idx++;  
	}
	
	for(int i=0; i<idx; i++) {
		//cout << sub[i] << ' ';	
		for(int j=1; j<=n-1; j++)
			if(sub[i] == j) cnt[j]++;
	}
	
	for(int i=1; i<=n-1; i++) {
		//cout << cnt[i] << ' ';
		if(cnt[i] == 1) flag=1;
		else  {
			flag=0;
			break;
		}
	}
	
	if(flag==1) cout << "YES";
	else cout << "NO";
}

