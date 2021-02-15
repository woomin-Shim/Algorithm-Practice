#include <iostream>
using namespace std;

/*자동차 10부제 위반하는 차량의 수 출력
  첫번째줄에는 날짜 일의 자리, 두번째 줄에는 자동차5대의 번호판 일의자리 입력
  */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int day, car, n = 5, cnt=0;
	cin >> day;
	while (n--) {
		cin >> car;
		if (day == car)
			cnt++;
	}
	cout << cnt;
}