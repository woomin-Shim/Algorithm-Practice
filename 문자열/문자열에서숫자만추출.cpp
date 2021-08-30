#include <stdio.h>
#include <string>
using namespace std;

//문자열에서 숫자 추출  
int main() {
	//freopen("input.txt", "rt", stdin);
	char a[100];
	int result=0, cnt=0;
	scanf("%s", &a);
	
	for(int i=0; a[i]!='\0'; i++) {
		if(a[i]>=48 && a[i] <= 57) {
			result = result * 10 + (a[i]-48);
		}
	}
	
	for(int i=1; i<=result; i++) {
		if(result%i==0) cnt++;
	}
	
	printf("%d\n%d", result, cnt);
	// 'A'~'Z' -> 65~90
	// 'a'~'z' -> 97~122
	// '0'~'9' -> 48~57
}


