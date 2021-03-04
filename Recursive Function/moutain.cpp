#include <iostream>
using namespace std;

void printMountain(int n) {
    if (n == 1)
        cout << 1;
    else {
        printMountain(n - 1);
        cout << n;
        printMountain(n - 1);
    }
}
int main() {
    int n;
    cin >> n;

    printMountain(n);
}