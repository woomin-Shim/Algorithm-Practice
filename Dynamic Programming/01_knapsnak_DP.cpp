#include <iostream>
using namespace std;
#define MAX 1234
#define max(a,b) a>b? a : b  // 큰 값 return 
int P[] = { 0, 4, 6, 8, 9, 6 };  //price 
int W[] = { 0, 2, 4, 5, 8, 3 };  //weight 
int K[MAX][MAX];
int K2[MAX][MAX];

int ks_01_DP(int n, int m) {  // n:배낭 개수, m:배낭 크기 
	int i, w;
	
	//0행(물건이 X)과 0열(무게가 0) 을0으로 초기화
	//for (w = 0; w <= m; w++) K[0][w] = 0;
	//for (i = 0; i <= n; i++) K[i][0] = 0;

	for (i = 1; i <= n; i++) {
		for (w = 1; w <= m; w++) {
			if (w < W[i]) //물건의 무게가 배낭의 무게를 초과하면 
				K[i][w] = K[i - 1][w];
			else  //초과하지 않으면 물건을 포함/포함하지 않았을 때 비교 
				K[i][w] = max(K[i - 1][w], K[i - 1][w - W[i]] + P[i]);
		}
	}

	return K[n][m];
}

int ks_01_DP2(int n, int m) {  //Dynamic programming 2
	int i, w;

	//0행, 0열의 나머지 부분 -1로 초기화 
	for (i = 1; i <= n; i++)
		for (w = 1; w <= m; w++)
			K2[i][w] = -1;

	//int P[] = { 0, 4, 6, 8, 9, 6 };  
	//int W[] = { 0, 2, 4, 5, 8, 3 };  

	/* K[5][13]을 구하기 위해서는 K[4][13]과 K[4][13-W[5]] (=[4][10]) + P[5] 필요 
	   K[4][13]  ->  [3][13], [3][13-W[4]] (=[3][5]) + P[4]  
	   k[4][10]  ->  [3][10], [3][2] + P[4]  
	*/

	
	return K[n][m];

}



int main() {
	int result = ks_01_DP(5, 13);  //최대 이익 
	int result2 = ks_01_DP2(5, 13);

	//DP 1 출력 
	for (int i = 0; i <= 5; i++) {
		for (int w = 0; w <= 13; w++) {
			//cout << "  ";
			cout.width(3);  //행렬 일정하게 출력 
			cout << K[i][w];
		}
		cout << endl;
	}
	cout << "\n";
	//DP 2 print
	for (int i = 0; i <= 5; i++) {
		for (int w = 0; w <= 13; w++) {
			//cout << "  ";
			cout.width(3);  //행렬 일정하게 출력 
			cout << K2[i][w];
		}
		cout << endl;
	}

	
}