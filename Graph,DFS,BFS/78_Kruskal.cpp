#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int unf[30], sum=0;

struct S {
	int x, y, z;
	S(int a, int b, int c) {
		x=a;
		y=b;
		z=c;
	}
	bool operator <(const S & ss) const {
		return z < ss.z;
	}
};

int find(int n) {
	if(unf[n]==n) return n;
	else {
		return unf[n] = find(unf[n]);
	}
}
void Union(int a, int b, int c) {
	a = find(a);
	b = find(b);
	if(a!=b) {
		unf[a] = b;
		sum += c;
	}

}
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int v, e, a, b, c;
	cin >> v >> e;  //city & road
	for(int i=1; i<=v; i++) unf[i] = i;
	vector<S> vec;
	for(int i=0; i<e; i++) {
		 cin >> a >> b >> c;
		 vec.push_back(S(a, b, c));
	}
	sort(vec.begin(), vec.end());
	
	for(auto pos : vec) {
		Union(pos.x, pos.y, pos.z);
	}
	
	cout << sum;
	
	

	
}
