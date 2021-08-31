#include <iostream>
using namespace std;

int arr[10];
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int tmp, max=0, res=0;
	char num[101];
	cin >> num;
	
	for(int i=0; num[i]!='\0'; i++) {
		tmp = num[i]-48;
		arr[tmp]++;
	}
	
	for(int i=1; i<10; i++) {
		if(max < arr[i]) {
			max = arr[i];
			res = i;
		}
		else if(max==arr[i]) {
			if(i>res) res = i;
		}	
	}
	
	cout << res;
}




