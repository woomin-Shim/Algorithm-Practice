#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[101], tmp[101];
int p1=1, p2=1, p3=1, n;

void rec(int lt, int rt) {  //1 8
	if(lt < rt) {
		int mid = (lt+rt) / 2;
		rec(lt, mid);
		rec(mid+1, rt);
		p1=lt;
		p2=mid+1;
		p3=lt;
		while(p1<=mid && p2<=rt) {
			if(v[p1] < v[p2]) tmp[p3++] = v[p1++];
			else tmp[p3++] = v[p2++];
		}
		while(p1<=mid) tmp[p3++] = v[p1++];
		while(p2<=rt) tmp[p3++] = v[p2++];
		for(int i=lt; i<=rt; i++) {
			v[i] = tmp[i];
		}
	}
}
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> v[i];   //2 4 6 8 
	}
	
	rec(1, n); //left, right
	for(int i=1; i<=n; i++) {
		cout << v[i] << ' ';
	}
}
