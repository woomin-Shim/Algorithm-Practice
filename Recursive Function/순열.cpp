#include <iostream>
using namespace std;
int n, r;
char alpha[100];
bool TF[100];

void getResult(int x) {
    if (x >= r) {
        cout << alpha << '\n';
    }
    else {
        for (int i = 0; i < n; i++) {
            char c = i + 'a';
            if (TF[i] == false) {
                alpha[x] = c;
                TF[i] = true;

                getResult(x + 1);
                TF[i] = false;
                alpha[x] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> r;
    getResult(0);
}