#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int a[10];

	a[0] = 10;

	cout << *a << ' ' << a << ' ' << &a[0] << '\n';
	cout << a + 1 << ' ' << &a[1];
}