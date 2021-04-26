#include <iostream>
#include <time.h>
using namespace std;
#define MAX_SIZE 51000

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
		int pivot_pos = partition(list, start, end);
		quickSort_basic(list, start, pivot_pos - 1);
		quickSort_basic(list, pivot_pos + 1, end);
	}
}

//execute quickSort 
void quick_sort(int list[], int low, int high, int Threshold) {
	int cnt = high - low + 1;    //A count of elements

	if (low < high) {  //based condition

		//원소의 개수가 Threshold 이하이면 insertion_sort 후 종료(더 이상 정렬할 값 x) 
		if (cnt <= Threshold) {
			insertion_sort(list, cnt);
			return;  //insertion_sort가 호출 되고 나서는 loop 돌아가 필요 X
		}
		else {  //임계값보다 크면 recursive 
			int pivot = partition(list, low, high);
			quick_sort(list, low, pivot - 1, Threshold);
			quick_sort(list, pivot + 1, high, Threshold);
		}
	}
}

int main() {
	int arr[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE], arr4[MAX_SIZE], arr5[MAX_SIZE];
	clock_t start, end;
	double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0, t5 = 0.0;

	srand(time(NULL));
	for (int k = 0; k < 10; k++) {  //everage를 구하기 위해 10번 반복 

		//각 배열에 같은 랜덤 넘버 생성시킴 
		for (int i = 0; i < MAX_SIZE; i++) {
			arr[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = rand() % 9999 + 1;
		}

		//임계값을 각자 다르게 주고 변수에 실행 시간 저장 
		start = clock();
		quick_sort(arr, 0, MAX_SIZE - 1, 10);
		end = clock();
		t1 += (double)(end - start) / CLOCKS_PER_SEC;

		//THRESHOLD = 100
		start = clock();
		quick_sort(arr2, 0, MAX_SIZE - 1, 100);
		end = clock();
		t2 += (double)(end - start) / CLOCKS_PER_SEC;

		//THRESHOLD = 1000
		start = clock();
		quick_sort(arr3, 0, MAX_SIZE - 1, 1000);
		end = clock();
		t3 += (double)(end - start) / CLOCKS_PER_SEC;

		//THRESHOLD = 10000
		start = clock();
		quick_sort(arr4, 0, MAX_SIZE - 1, 10000);
		end = clock();
		t4 += (double)(end - start) / CLOCKS_PER_SEC;

		start = clock();
		quickSort_basic(arr5, 0, MAX_SIZE - 1);
		end = clock();
		t5 += (double)(end - start) / CLOCKS_PER_SEC;
	}

	cout << "임계값에 따른 실행 시간" << '\n';
	cout << "THRESHOLD 10 : " << t1/10 << '\n';
	cout << "THRESHOLD 100 : " << t2/10 << '\n';
	cout << "THRESHOLD 1000 : " << t3/10 << '\n';
	cout << "THRESHOLD 10000 : " << t4/10 << '\n';
	cout << "원래의 퀵 정렬 실행 시간 : " << t5/10 << '\n';

	return 0;
}