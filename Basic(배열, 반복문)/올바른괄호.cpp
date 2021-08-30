#include <stdio.h>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	
	/*
	()()  1 0 1 0
	((())) 1 2 3 2 1 0
	( ---- +1
	) ---- -1
	*/
	
	char a[40];
	int cnt = 0;
	scanf("%s", &a);
	
	for(int i=0; a[i]!='\0'; i++) {
			if(a[i] == '(') cnt ++;
			else if(a[i] == ')') cnt--;
			if(cnt < 0) break;	
	}
		
	if(cnt==0) printf("YES\n");
	else printf("NO\n");
}



