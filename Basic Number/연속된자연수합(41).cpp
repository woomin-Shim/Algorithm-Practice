#include <iostream>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, tot=0, num=2, min, cnt=0;
	cin >> n;   //15
	
	while(tot < n) {
		tot=0;
	
		for(int i=1; i<=num; i++) tot += i;
		
		min = n - tot;  //15 - 3 = 12
		
		if(min%num==0) {
			int plus = min/num;
			for(int i=1; i<=num; i++) {
				if(i<num) cout << i+plus << '+';
				else cout << i+plus << '=' << n;
			}
			cout << '\n';
		
			cnt++;
		}
		num++;
	}
	cout << cnt;

}
	 

