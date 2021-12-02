#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int top = -1, stack[100];

void push(int element) {
	stack[++top] = element;	
}
int pop() {
	return stack[top--];
}

int main() {
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n, k, cnt=0;
	char str[20] = "0123456789ABCDEF";
	cin >> n >> k;
	
	while(n>0) {
		push(n%k);
		n /= k;
		cnt++;
	}
	
	while(top != -1) {
		cout << str[pop()]; 
	}
}
	 

