#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char a[1000], b[1000];

    fgets(a, 1000, stdin);  //공백까지 포함('\n')
    fgets(b, 1000, stdin);

    int len = strlen(a);
    int len2 = strlen(b);
   
    for (int i = 0; i < len-len2; i++) {
        int cnt = 0;

        for (int j = 0; j < len2; j++) {
            if (a[i+j] == b[j]) {
                cnt++;
            }
        }

        if (cnt == len2) {
            cout << "YES";
            return 0;
        }
     }
    
    cout << "NO";
}