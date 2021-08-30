#include <stdio.h>
using namespace std;

int arr[50001];
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j+=i) { //time-complexity!!
			arr[j]++;		    
		}
	}
	
	for(int i=1; i<=n; i++)
		printf("%d ", arr[i]);
}



