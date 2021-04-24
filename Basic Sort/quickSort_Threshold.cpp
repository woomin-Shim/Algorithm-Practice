#include <iostream>
#include <time.h>
using namespace std;
#define MAX_SIZE 15000

//execute insertion_sort
void insertion_sort(int list[], int length) {
	for (int i = 1; i < length; i++) {
		for (int j = i; j > 0; j--) {
			//원소들을 비교하면서 작은 값이 나오면 swap 
			if (list[j] < list[j - 1]) {
				int tmp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = tmp;
			}
			else break;  //크다면 앞에는 이미 정렬된 상태이기 때문에 반복 필요 x
		}
	}
}


int partition(int list[], int low, int high) {
	int pivot = low;  //맨 처음 값을 pivot으로 setting
	int left = low, right = high;

	while (left < right) {  //두 값이 겹치면 while loop 종료
		while (list[left] <= list[pivot] && left <= high)  //피봇값보다 크면 stop 
			left++;
		while (list[right] > list[pivot])  //피봇값보다 작거나 같으면 stop 
			right--;
		if (left < right) {
			//list[left] 와 list[right] swap
			int tmp = list[left];
			list[left] = list[right];
			list[right] = tmp;
		}
	}
	//list[pivot] 과 list[right] swap
	int tmp = list[pivot];
	list[pivot] = list[right];
	list[right] = tmp;

	return right;  //return pivot index 
}

//execute basic quicksort
void quickSort_basic(int list[], int start, int end) {
	if (start <= end) {
		int pivot_pos = partition(list, start, end);  //오른쪽 partition의 first index
		quickSort_basic(list, start, pivot_pos - 1);
		quickSort_basic(list, pivot_pos + 1, end);
	}
}

//execute quickSort 
void quick_sort(int list[], int low, int high, int Threshold) {
	int cnt = high - low + 1;    //A count of elements  --->  THRESHOLD

	if (low < high) {
		if (cnt <= Threshold) {  //임계값보다 낮거나 같으면 insertion_sort 수행 
			insertion_sort(list, cnt);
		}

		else {
			int pivot = partition(list, low, high);
			//if (low < pivot - 1)  //left partition elements가 두 개 이상일 경우
				quick_sort(list, low, pivot - 1, Threshold);
			//if (pivot + 1 < high)  //right partition elements가 두 개 이상일 경우
				quick_sort(list, pivot + 1, high, Threshold);
		}
	}
	
}

int main() {
	int arr[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE], arr4[MAX_SIZE], arr5[MAX_SIZE];
	clock_t start, end;
	double t1, t2, t3, t4, t5;

	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = arr2[i] =arr3[i] = arr4[i] = arr5[i] = rand() % 9999 + 1;
	}
	
	
	start = clock();
	quick_sort(arr, 0, MAX_SIZE - 1, 10);
	end = clock();
	t1 = (double)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < 50; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	start = clock();
	quick_sort(arr2, 0, MAX_SIZE - 1, 100);
	end = clock();
	t2 = (double)(end - start) / CLOCKS_PER_SEC;

   
	start = clock();
	quick_sort(arr3, 0, MAX_SIZE - 1, 1000);
	end = clock();
	t3 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	quick_sort(arr4, 0, MAX_SIZE - 1, 10000);
	end = clock();
	t4 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	quickSort_basic(arr4, 0, MAX_SIZE - 1);
	end = clock();
	t5 = (double)(end - start) / CLOCKS_PER_SEC;

	cout << "THRESHOLD를 10으로 설정하였을 떄의 실행 시간 : " << t1 <<'\n';
	cout << "THRESHOLD를 100으로 설정하였을 떄의 실행 시간 : " << t2 << '\n';   
	cout << "THRESHOLD를 1000으로 설정하였을 떄의 실행 시간 : " << t3 << '\n';
	cout << "THRESHOLD를 10000으로 설정하였을 떄의 실행 시간 : " << t4 << '\n';
	cout << "원래의 퀵 정렬 실행 시간 : " << t5 << '\n';
	return 0;
}