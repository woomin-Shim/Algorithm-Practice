#include <iostream>
using namespace std;

/*행렬에 쓰여진 81개의 자연수가 주어질 때 
  이들 중 최대값을 찾고 몇행 몇열인지 출력 
  최대값이 여러값일 경우 행이 가장 작은 곳으로 출력
  행 번호도 같을시 열이 가장 작은 곳으로 출력*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, big=0, ry, rx;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> num;

			if (num > big) {
				big = num;
				ry = i;  //행
 				rx = j;  //열
			}

			//else if 구문 없어도 전혀 문제 X
			else if (big == num) {
				if (i < ry || (ry == i && j < rx)) {
					ry = i;
					rx = j;
				}
			}
		}
	}
	cout << big << "\n";
	cout << ry << ' ' << rx;

}