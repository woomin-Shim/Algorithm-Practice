#include <iostream>
using namespace std;

void swap(int arr[], int a, int b);
int partition(int list[], int low, int high) {
	int i, j = low;
	for (int i = low + 1; i <= high; i++) {
		if (list[i] <= list[low]) { 
			j++;  
			swap(list, i, j);  
		}
	}
	swap(list, low, j);  //pivot의 위치 설정 

	return j;  //pivot 위치 return;
}

void quicksort_DC(int list[], int low, int high) {
	if (low < high) { //data가 두 개이상이면 
		int pivot = partition(list, low, high);

		//분할된 왼쪽, 오른쪽 대상으로 quicksort
		quicksort_DC(list, low, pivot - 1);
		quicksort_DC(list, pivot + 1, high);
	}
}

void swap(int arr[], int a, int b) {
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int main() {
	int arr[10] = { 9, 1, 8, 2, 7, 3, 6, 4, 5, 20 };
	quicksort_DC(arr, 0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}