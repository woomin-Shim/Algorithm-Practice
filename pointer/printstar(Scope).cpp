#include <iostream>
using namespace std;

void printspace(int n) {
    for (int i = 0; i < n; i++) cout << " ";
}
void printstar(int n) {
    for (int i = 0; i < n; i++) cout << "*";
}
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        printspace(n - i - 1);
        printstar(i + 1);
        cout << "\n";
    }
}