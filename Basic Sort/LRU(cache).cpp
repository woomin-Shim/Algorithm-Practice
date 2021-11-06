#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, s, n, num;
	
	cin >> s >> n;
	vector <int> v(s);
	
	
	for(i=0; i<n; i++) {
		cin >> num;
		int pos = -1;
		for(j=0; j<s; j++)  {
			if(v[j]==num) pos=j;
		}
		
		if(pos==-1) { //miss
			for(j=s-1; j>0; j--) {
				v[j] = v[j-1];
				//for(int k=0; k<s; k++) cout << v[k] << ' ';
				//cout << '\n';
			}
			//cout << '\n';
			v[j] = num;	
		}
		else { //hit
			for(j=pos; j>0; j--) {
				v[j] = v[j-1];
				//for(int k=0; k<s; k++) cout << v[k] << ' ';
			}
			//cout << "\n";
			v[j] = num;
		}
	}
	
	for(i=0; i<s; i++) cout << v[i] << ' ';
}
	 




