#include <iostream>
using namespace std;

int arr[101];
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, flag, res=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	for(int i=0; i<n; i++) {
		flag = 0;
		for(int j=i+1; j<n; j++) {
			if(arr[i] > arr[j]) flag=1;
			else {
				flag=0;
				break;
			}
		}
		if(flag==1) res++;
	}
	cout << res;
}
