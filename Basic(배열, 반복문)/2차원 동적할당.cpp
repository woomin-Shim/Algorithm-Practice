#include <iostream>
using namespace std;

int main() {
	int row = 5;             //행 갯수입니다.
	int column = 10;       //열 갯수입니다.
	int cnt = 0;

	int** ary = new int* [row];          //이부분이 동적할당입니다.
	for (int i = 0; i < row; ++i)         //행부터 동적할당 해주고 행마다 또 동적할당 해주는겁니다
		ary[i] = new int[column];

	for (int i = 0; i < row; i++) {                       //확인위해 0부터 차례로 값넣어줍니다.
		for (int j = 0; j < column; j++) {
			ary[i][j] = cnt++;
		}
	}

	for (int i = 0; i < row; i++) {                       //확인위해 값 출력
		for (int j = 0; j < column; j++) {
			cout << ary[i][j] << ",";
		}
		cout << '\n';
	}

	for (int i = 0; i < row; i++)              //메모리 해제 , 행마다 해제해주고
		delete[] ary[i];
	delete[] ary;            //마지막으로 행도 해제
}
