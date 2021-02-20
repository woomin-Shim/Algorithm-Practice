#include <iostream>
using namespace std;

//2010 Arab Collegiate Programming Contest A¹ø  
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b==0 && c==0) break;
		else {
			if ((b - a) == (c - b)) {
				cout << "AP " << (b - a) + c << "\n";
			}
			else if ((b / a) == (c / b)) {
				cout << "GP " << c * (c / b) << "\n";
			}
		}
	}
}