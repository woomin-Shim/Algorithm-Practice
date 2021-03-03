#include <iostream>
using namespace std;

void initialize(int arr[]) {  //int *arr
    for (int i = 0; i < 10; i++) {
        arr[i] = 0;
    }
}
int main() {
    int arr[10] = { 0, };

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    initialize(arr);

    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';

    return 0;
}