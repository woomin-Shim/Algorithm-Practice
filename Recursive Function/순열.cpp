#include <iostream>
using namespace std;
char alpha[100];
bool TF[100];

void getResult(int x, int n, int r, char alpha[]) {  //x번째 반복문 
    if (x >= r) {
        cout << alpha;
        cout << '\n';
    }
    else {
        for (int i = 0; i < n; i++) {
            if (TF[i] == false) {
                char c = i + 'a';
                alpha[x] = c;
                TF[i] = true;

                getResult(x + 1, n, r, alpha);
                TF[i] = false;
                alpha[x] = 0;
            }
        }
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    getResult(0, n, r, alpha);
}