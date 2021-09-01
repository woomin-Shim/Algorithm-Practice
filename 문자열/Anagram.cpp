#include <iostream>
#include <algorithm>  //for using 'exit(0)'
using namespace std;


int arr1[60], arr2[60];  //Ascii array 
int main() {
	//freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	char a[100], b[100];
	int idx, cnt=0, flag=1;
	cin >> a >> b;
		
	for(int i=0; a[i]!='\0'; i++) {
		if(a[i] >= 65 && a[i]<= 90) { //Upper --> 65~90
			arr1[a[i]-64]++;
		}
		else arr1[a[i]-70]++;  //Lower --> 97~122
	}
	
	for(int i=0; b[i]!='\0'; i++) {
		if(b[i] >= 65 && b[i]<= 90) { //Upper --> 65~90
			arr2[b[i]-64]++;
		}
		else arr2[b[i]-70]++;  //Lower --> 97~122
	}
	
	for(int i=0; i<52; i++) {
		if(arr1[i]!=arr2[i]) flag=0;
	}
	if(flag==1) cout << "YES";
	else cout << "NO";
	
}
