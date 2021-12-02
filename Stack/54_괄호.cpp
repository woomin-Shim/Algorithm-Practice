#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	stack<int> st;
	string s;
	int tot=0;
	getline(cin, s);
	
	for(int i=0; i<s.length(); i++) {
		if(s[i]=='(') {
			st.push(1);
		}
		else {
			if(st.empty()) {
				cout << "NO";
				return 0;
			}
			else {
				st.pop();
			}
		}
	}
	
	if(st.empty()) {
		cout << "YES";
	}
	else cout << "NO";
	
	

	
}
	 

