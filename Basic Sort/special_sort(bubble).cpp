#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//special sort(left:less than zero, right:+), order does not change 
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,cnt=0;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-i-1; j++) {
			if((v[j]>0 && v[j+1]<0) && v[j] > v[j+1]) {
				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
	for(int i=0; i<n; i++) cout << v[i] << ' ';
}



