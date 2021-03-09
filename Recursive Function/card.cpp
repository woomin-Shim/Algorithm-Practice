#include <iostream>
using namespace std;
//Line up cards (ex.   n=3 123, 132, 213, 231, 312, 321) 

int n;
int card[1000];
bool TF[1000];

void printCard(int current, int n, int card[]) {
	if (current >= n) {
		for (int i = 0; i < n; i++) cout << card[i];
		cout << '\n';
	}
	else {

		for (int i = 1; i <= n; i++) {
			if (TF[i] == false) {
				card[current] = i;
				TF[i] = true;

				printCard(current + 1, n, card);
				TF[i] = false;
				card[current] = 0;
			}
			
			
		}
	}
}
int main() {
	cin >> n;
	printCard(0, n, card);
}