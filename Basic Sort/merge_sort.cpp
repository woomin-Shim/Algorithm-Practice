#include <iostream>
using namespace std;
#define MAX_SIZE 10000  

int sorted[MAX_SIZE]; //오름차순으로 합병을 수행한 값들을 임시저장하기 위한 배열 


//합병을 수행하는 함수
void merge(int list[], int low, int mid, int high) {
	int n1 = low;  //left data set
	int n2 = mid + 1;  //right data set
	int s = low;  //sorted 배열에 사용될 index

	while (n1 <= mid && n2 <= high) { //왼쪽, 오른쪽 data set이 있을 때까지
		if (list[n1] <= list[n2]) { //왼쪽 data가 오른쪽보다 작거나 같으면 win
			sorted[s++] = list[n1++];
		}
		else {  //오른쪽 data가 작으면 win
			sorted[s++] = list[n2++];
		}
	}

	if (n1 > mid) {  //왼쪽 data가 모두 sorted에 저장된 경우
		while (n2 <= high)  //남음 오른쪽 data 모두 저장
			sorted[s++] = list[n2++];
	}
	else //오른쪽 data가 모두 sorted에 저장된 경우
		while (n1 <= mid)  //남은 왼쪽 data 모두 저장 
			sorted[s++] = list[n1++];

	for (int i = low; i <= high; i++)  //sorted에 임시로 정렬된 수들을 list로 
		list[i] = sorted[i];
}

//합병정렬
void merge_sort_DC(int list[], int low, int high) {
	int middle;//중간
	if (low < high) {  //분할이 가능(부문제가 2개)
		middle = (low + high) / 2;
		merge_sort_DC(list, low, middle);  //left집합을 대상으로 데이터 개수가 하나가 될때까지 분할
		merge_sort_DC(list, middle + 1, high); //right집합을 대상으로 데이터 개수가 하나가 될때까지 분할
		merge(list, low, middle, high);  //합병
	}
}

int main() {
	int arr[10] = { 3, 7, 1, 2, 2, 55, 6, 1, 3, 9};
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
	cout << '\n';
	merge_sort_DC(arr, 0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
	cout << '\n';
	
}