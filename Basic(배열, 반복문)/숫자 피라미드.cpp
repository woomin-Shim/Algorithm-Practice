#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s, num=1;
	cin >> n >> s;
	int PreviousFirst, previousLast = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i-1; j++)
			cout << ' ';

		if (i % 2 == 0) {  //odd
			int currentFirst;

			if (i == 0) currentFirst = s;
			else {
				currentFirst = previousLast;

				for (int j = 0; j < num; j++) {
					currentFirst += 1;
					if (currentFirst == 10) currentFirst = 1;
				}
			}
				PreviousFirst = currentFirst;
			
			for (int j = 0; j < num; j++) {
				cout << currentFirst;
				currentFirst -= 1;
				if (currentFirst == 0) currentFirst = 9;
			}
			num += 2;
		}
		else { //even
			int currentFirst = PreviousFirst + 1;
			if (currentFirst == 10) currentFirst = 1;

			for (int j = 0; j < num; j++) {
				cout << currentFirst;
				previousLast = currentFirst;
				currentFirst += 1;
				if (currentFirst == 10) currentFirst = 1;					
			}
			num += 2;
		}
		cout << "\n";
	}
}