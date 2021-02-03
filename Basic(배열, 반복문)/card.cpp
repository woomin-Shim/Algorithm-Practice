#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A[10], B[10], a=0, b=0;
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	for (int i = 0; i < 10; i++)
		cin >> B[i];
	
	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i]) a += 1;
		else if (A[i] < B[i]) b += 1;
		else a += 0, b += 0;
	}
	if (a > b) cout << "A";
	else if (a < b) cout << "B";
	else cout << "D";
}