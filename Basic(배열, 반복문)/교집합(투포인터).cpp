#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	
	cin >> n;
	vector <int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	
	cin >> m;
	vector <int> b(m);
	for(int i=0; i<m; i++) cin >> b[i];
	
	vector <int> result(n+m);
	
	sort(a.begin(), a.end());   //2 3 5 7 10
	sort(b.begin(), b.end());   //3 5 10 12 17
	
	int p1=0, p2=0, p3=0, cnt=0;
	
	while(p1<n && p2<m) {
		if(a[p1] < b[p2]) p1++;
		else if(a[p1]==b[p2]) {
			result[p3++] = a[p1];
			p1++;
			p2++;
		}
		else p2++;
	}
	
	for(int i=0; i<p3; i++) cout << result[i] << ' ';
}
	 




