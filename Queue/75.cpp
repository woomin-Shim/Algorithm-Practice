#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int ch[10001];
struct s {
	int a, b;
	s(int price, int day) {
		a = price;
		b = day;
	}
	bool operator<(const s &t) const{
		return b>t.b;
	}
};

int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	int n, m, d, sum=0;
	cin >> n;
	vector<s> v;
	for(int i=0; i<n; i++) {
		cin >> m >> d;  //price, day
		v.push_back(s(m, d));
	}
	sort(v.begin(), v.end());
	
	for(auto pos : v) {
		cout << pos.a << ' ' << pos.b << '\n';
	}
	
	//a=price, b=day
	priority_queue<int> pq;
	int cnt = v[0].b;  // 3
	while(cnt) {
		for(int i=0; i<v.size(); i++) {
			if(v[i].b==cnt) {
				pq.push(v[i].a);
			
			}
		}
		cnt--;
		if(!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
		//cout << pq.top();
	
	}
	cout << sum;
}
