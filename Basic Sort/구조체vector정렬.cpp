#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Loc {
	int x, y, z;
	Loc(int a, int b, int c) {
		x=a;
		y=b;
		z=c;
	}
	bool operator<(const Loc &L)const {
		if(x!=L.x) return x<L.x; //ASC
		if(y!=L.y) return y<L.y;
		if(z!=L.z) return z<L.z;
	}
};

int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	vector<Loc> XY;
	XY.push_back(Loc(2, 3, 5));
	XY.push_back(Loc(3, 6, 7));
	XY.push_back(Loc(2, 3, 1));
	XY.push_back(Loc(5, 2, 3));
	XY.push_back(Loc(3, 1, 6));
	sort(XY.begin(),XY.end());
	for(auto pos : XY) cout << pos.x << ' ' << pos.y << ' ' << pos.z << '\n';
}
