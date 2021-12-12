#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Q[100], front=-1, rear=-1, ch[10];
vector<int> map[10];
int main() {
	freopen("input.txt", "rt", stdin);
	cin.tie(0);
	
	int a, b, x;
	for(int i=0; i<6; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	}
	Q[++rear]=1;
	ch[1]=1;
	while(front < rear) {
		x = Q[++front];  //1
		cout << x << ' ';
		for(int i=0; i<map[x].size(); i++) {
			if(ch[map[x][i]]==0) {
				ch[map[x][i]]=1;
				Q[++rear]=map[x][i];
				
			}
		}
		
	}
}
