#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
	10
	1 5 6 8 3 4 5 9 2 10
	-------
	1 2 3 4 5 6 7 8 9 10
	*/

	int n;
	int data[100];
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> data[i];

	for (int i = 0; i < n; i++) {
		//이제 i번째에 최솟값을 넣어라
		//i번째부터 맨 끝까지의 수 중 최솟값 
		int idx = i;

		for (int j = i; j < n; j++) {
			if (data[idx] > data[j])
				idx = j;
		}

		int temp = data[i];
		data[i] = data[idx];
		data[idx] = temp;

		/*
		for (int j = 0; j < n; j++)
			cout << data[j] << ' ';
		cout << "\n";
		*/
	}

	for (int i = 0; i < n; i++)
		cout << data[i] << ' ';
	


}