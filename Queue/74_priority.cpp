#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	
	priority_queue<int> pq;
	int n;
	while(1) {
		cin >> n;	
		if(n==0) {
			if(pq.empty()) cout << "-1";
			else {
				cout << pq.top()*-1 << '\n';
				pq.pop();
			}
		}
		else pq.push(-n);
		if(n==-1) exit(0);
	}
}
