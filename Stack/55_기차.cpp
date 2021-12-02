#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int arr[40];

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	stack<int> s;
	vector<char> v;
	
	int n, num, cnt=1;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> num;
		s.push(num);
		v.push_back('P');
		while(1) {
			if(s.empty()) break;
			if(s.top() == cnt) {
				s.pop();
				v.push_back('O');
				cnt++;
			}
			else break;
		}
	}	
	
	if(!s.empty()) {
		cout << "impossible";
		return 0;
	}
	
	for(int i=0; i<v.size(); i++) {
		cout << v[i];
	}
	
	
}
	 

