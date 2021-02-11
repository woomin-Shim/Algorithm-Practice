#include <iostream>
using namespace std;

//BOJ 2578

int map[5][5];
int num[5];
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	}
	int n, idx = 0, order = 0;
	for (int k = 0; k < 25; k++) { //몇 번째 숫자에 빙고인지 
		cin >> n;
		order++;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (map[i][j] == n)
					map[i][j] = -1;

				int cnt = 0;
				for (int q = 0; q < 5; q++) { //row
					int sum = 0;
					for (int w = 0; w < 5; w++) {
						sum += map[q][w];
					}
					if (sum == -5) cnt++;
				}


				for (int q = 0; q < 5; q++) {  //column 
					int sum = 0;
					for (int w = 0; w < 5; w++) {
						sum += map[w][q];
					}
					if (sum == -5) cnt++;
				}


				int sum = 0;
				for (int q = 0; q < 5; q++) {
					sum += map[q][q];
				}
				if (sum == -5) cnt++;

				sum = 0;
				for (int q = 0; q < 5; q++) {
					sum += map[q][5 - 1 - q];

				}
				if (sum == -5) cnt++;
				if (cnt >= 3) {  //왜 cnt==3 은 아닌지 질문하기 
					cout << order;
					return 0; //입력 안할 시 반복됨 
				}
			}
		}
	}
}
