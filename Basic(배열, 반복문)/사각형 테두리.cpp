#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;

	cin >> a >> b;

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			if (i == 0 || i == b - 1)
				cout << "* ";
			else
				if (j == 0 || j == a-1 )
					cout << "* ";
				else
					cout << "  ";
		}
		cout << "\n";
	}
}