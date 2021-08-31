#include <stdio.h>
using namespace std;

int arr[101];
int digit_sum(int x) {
	int sum=0, tmp=0;
	while(x>0) {
		tmp = x % 10;
		sum += tmp;
		x = x / 10;
	}
	return sum;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, k, max=0, res;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &k);
		if(max < digit_sum(k)) {
			max = digit_sum(k);
			res = k;
		}	
		else if (max==digit_sum(k)) {
			if(k > res) res = k;
		}
	
	}
	printf("%d\n", res);
}



