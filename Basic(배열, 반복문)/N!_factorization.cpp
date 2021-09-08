#include <iostream>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, tmp, k=2;
	cin >> n;
	vector<int> v(n+1);
	
	for(int i=2; i<=n; i++) {
		tmp = i;
		int j = 2;
		while(tmp!=1) {
			if(tmp%j==0) {
				v[j]++;
				tmp /= j;
			}
			else {
				j++;
			}
		}
	}
	
	cout <<  n << "! = ";
	for(int i=0; i<=n; i++) {
		if(v[i]!=0) cout << v[i] << ' ';
	}
}



