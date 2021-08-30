#include <stdio.h>
#include <string>
using namespace std;
 
int main() {
	//freopen("input.txt", "rt", stdin);
	char a[101], b[101];
	int idx=0;
	gets(a);
	
	for(int i=0; a[i]!='\0'; i++) {
		if(a[i]!=' ') {
			if(a[i]>=65 && a[i]<= 90) {
				a[i]+=32;
				b[idx++] = a[i];
			}
			else b[idx++] = a[i];
		}
	}
	b[idx]='\0';
	printf("%s", b);
}



