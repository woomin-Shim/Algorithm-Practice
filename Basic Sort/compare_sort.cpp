#include <iostream>
#include <stdlib.h>
#include <time.h> //clock 함수를 사용하기 위한 헤더파일 
using namespace std;
#define MAX_SIZE 100000 //정렬될 배열 원소의 개수 
int sorted[MAX_SIZE];  //오름차순으로 정렬할 때 사용되는 임시 배열 


//execute merge 
void merge(int list[], int low, int mid, int high) {
	int n1 = low;  //left partition
	int n2 = mid + 1;  //right partition
	int idx = low;

	while (n1 <= mid && n2 <= high) {  //왼쪽이나 오른쪽 중에 데이터가 소진되면 빠져나감 
		if (list[n1] <= list[n2]) {  //왼쪽 data가 오른쪽 data보다 작거나 클 경우 
			sorted[idx++] = list[n1++];  //임시 배열에 left data 저장
		}
		else { //오른쪽 data가 왼쪽 data보다 작을경우
			sorted[idx++] = list[n2++];  //임시 배열에 right data 저장
		}
	}

	if (n1 > mid) {  //왼쪽 data 모두 소진
		while (n2 <= high) sorted[idx++] = list[n2++];   //남은 오른쪽 data들 저장
	}
	else {  //오른쪽 data 모두 소진
		while (n1 <= mid) sorted[idx++] = list[n1++];   //남은 왼쪽 data 저장
	}

	for (int i = low; i <= high; i++)
		list[i] = sorted[i];    //임시 배열에 정렬된 배열을 원래의 배열로 

}

void merge_sort(int list[], int low, int high) {  
	int middle;
	if (low < high) {
		middle = (low + high) / 2;  //mid index
		merge_sort(list, low, middle);  //왼쪽 merge sort
		merge_sort(list, middle + 1, high);  //오른쪽 merge sort
		merge(list, low, middle, high);  //execute merge 
	}
}

//call by reference 
void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int list[], int low, int high) {
	int pivot = low;  //맨 처음 값을 pivot으로 setting
	int left = low, right = high;

	while (left < right) {  //두 값이 겹치면 while loop 종료
		while (list[left] <= list[pivot] && left<=high)  //피봇값보다 크면 stop 
			left++;
		while (list[right] > list[pivot])  //피봇값보다 작거나 같으면 stop 
			right--;
		if (left < right) {
			//swap(&list[left], &list[right]);
			int tmp = list[left];
			list[left] = list[right];
			list[right] = tmp;
		}
	}
	//swap(&list[pivot], &list[right]);
	int tmp = list[pivot];
	list[pivot] = list[right];
	list[right] = tmp;
	return right;
}

void quick_sort(int list[], int low, int high) {
	if (low < high) {
		int pivot = partition(list, low, high);
		quick_sort(list, low, pivot - 1);
		quick_sort(list, pivot + 1, high);
	}
}

int main() {
	int arr[MAX_SIZE], arr2[MAX_SIZE];   //merge_sort, quick_sort를 위한 배열 
	

	srand(time(NULL));  //랜덤 생성을 위한 SEED
	clock_t start, end;
	double t1 = 0.0, t2 = 0.0;  //merge_sort, quick_sort 측정 시간 변수

	//평균시간 구하기 위해 10번을 반복 
	for (int k = 0; k < 10; k++) {  
		//랜덤 넘버 생성 
		for (int i = 0; i < MAX_SIZE; i++) {
			arr[i] = arr2[i] = rand() % 99999 + 1; // 1~99999 random 
		}
		for (int i = 0; i < 30; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < 30; i++) {
			cout << arr2[i] << " ";
		}
		cout << "\n";


		//merge_sort 측정
		start = clock();
		merge_sort(arr, 0, MAX_SIZE - 1);
		end = clock();
		for (int i = 0; i < 30; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		t1 += (double)(end - start) / CLOCKS_PER_SEC;

		//quick_sort 측정
		start = clock();
		quick_sort(arr2, 0, MAX_SIZE - 1);
		end = clock();
		for (int i = 0; i < 30; i++) {
			cout << arr2[i] << " ";
		}
		cout << "\n";
		t2 += (double)(end - start) / CLOCKS_PER_SEC;

	}
	cout << "MergeSort의 측정 시간 : " << t1/10 << '\n';
	cout << "QuickSort의 측정 시간 : " << t2/10 << '\n';

	return 0; 
}