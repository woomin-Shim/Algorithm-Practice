#include <iostream>
using namespace std;

void insertion_sort(int list[], int n) {
	for (int i = 1; i < n; i++) {
		int key = list[i];    //1
		int hole = i;     //2
		while (hole > 0 && list[hole - 1] > key) {
			list[hole] = list[hole - 1];
			hole--;

			/*	int tmp = list[idx];
			list[idx] = list[idx - 1];
			list[idx - 1] = tmp;  */
		}
		list[hole] = key;
	}
}

int main() {
	int arr[] = { 2, 3, 1, 6, 1, 2, 7, 8, 9 };
	insertion_sort(arr, 9);
	for (int i = 0; i < 9; i++) cout << arr[i] << ' ';

}