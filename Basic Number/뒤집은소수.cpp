#include <iostream>
#include <math.h>
using namespace std;

int reverse(int x) {
	//910 -> 019
	int tmp, res=0;
	while(x>0) {
		tmp = x % 10;
		res = res * 10 + tmp;
		x/=10;
	}
	return res;
}

bool isPrime(int x) {
	if(x<=1) return false;
	for(int i=2; i<=sqrt(x); i++) {
		if(x%i==0) {
			return false;	
			break;
		}
	}		
	return true;
}
int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, num, res;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> num;
		res = reverse(num); 
		if(isPrime(res)) cout << res << ' ';
	}
}




