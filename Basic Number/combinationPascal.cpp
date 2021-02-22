#include <iostream>
using namespace std;

//2차원 배열의 크기가 크면 Runtime Error!! , 틀린풀이 
//BOJ 2004

int arr[31][31];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= 31; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            }
            else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= i; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << "\n";
   }
    int rest=0, cnt=0;
    while (1) {
        rest = arr[n][m] % 10;
        if (rest != 0) break;
       
        cnt++;
        arr[n][m] /= 10;  
    }

    cout << cnt;
    return 0;
}


/*

nCr + nCr+1 = n+1Cr+1 이다.
예를 들어, 10개 중 2개를 고르는 경우의 수는 45개이다. -> 10 x 9 / 2 x 1;
9C1 + 9C2 = 45이다.

다른 예를 보면, 9개 중 3개를 고르는 경우의 수는 9C3 인데,
8C2 + 8C3 으로 표현된다.

<코드>

#include<stdio.h>

int n,m;
int combi[32][32];

int getCombi(int arr[][32], int l, int k)
{
  if(k==1){
    // nC1은 항상 n

    arr[l][k] = l;

    return l;
  }
  if(k==0){

    // nC0 은 항상 1

    arr[l][k] = 1;

    return 1;
  }
  if(l==k){
    // nCn 은 항상 1
    arr[l][k] = 1;
    return 1;
  }

  if(arr[l][k]!=0){
    return arr[l][k];
  }


  arr[l][k] = getCombi(arr,l-1,k)+getCombi(arr,l-1,k-1);
  return arr[l][k];
}

int main(){

  scanf("%d %d",&n,&m);

  printf("%d",getCombi(combi,n,m));

  return 0;

}*/