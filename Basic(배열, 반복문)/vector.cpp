#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	
//	vector<int> v[3];
//	v[0].push_back(1);
//	v[0].push_back(2);
//	v[0].push_back(3);
//	v[1].push_back(11);
//	v[1].push_back(22);
//	v[1].push_back(33);
//	
//	cout << v[0][1] << ' ' << v[1][2];
	
	vector<pair<int,int>> graph[3];
	graph[0].push_back({1, 2});
	graph[0].push_back({3, 4});
	graph[1].push_back({5, 6});
	graph[1].push_back(make_pair(7,8));
	
	cout << graph[0][0].first << ' ' << graph[0][1].second;
}
