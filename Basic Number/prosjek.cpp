#include <iostream>
using namespace std;

int B[101], A[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> B[i];

	A[1] = B[1];
	cout << A[1] << ' ';
	for (int i = 2; i <= n; i++) {
		int n1 = B[i] * i;
		int result = n1 - A[i - 1];
		A[i] = n1;

		cout << result << ' ';
	}
}

/*
#include <stdio.h>

int n;
int b[101];
int a[101];

// 재귀 호출을 사용하여 반복문 사용을 줄일 수 있었다.
int mksum(int n){
  a[1] = b[1];
  if(n==1) return a[1];
  return mksum(n-1)+a[n];
}

int main() {
  scanf("%d",&n);
  for(int i=1; i<=n; i++){
	scanf("%d",&b[i]);
  }

  a[1] = b[1];

  for(int i=2; i<=n; i++){
	a[i] = b[i] * i - mksum(i-1);
  }

  for(int i=1; i<=n; i++){
	printf("%d ",a[i]);
  }
  return 0;

}*/