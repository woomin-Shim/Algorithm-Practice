#include <stdio.h>
#include <stdlib.h>   // 퀵정렬을 사용하기 위한 헤더파일 
#define MAX 100

int parent[MAX];  //vertex의 최대 개수는 100개까지 가능, input_graph의 경우 vertex=9

void init_set(int n) {  //parent 배열을 -1(root node)로 초기화
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

int find(int vertex) {   //parent node를 찾는 함수 
	if (parent[vertex] < 0) {  //based condition
		return parent[vertex];
	}
	else {
		return parent[vertex] = find(parent[vertex]);
	}
}
                               
void do_union(int v1, int v2) {  // 0  3  
	if (v1 > v2) {
		int temp = v1;
		v1 = v2;
		v2 = temp;
	}

	if (parent[v1] <= parent[v2]) {  //정점 v1이 더 많은 원소를 가질 때(음수니까 반대로)
		//-4   -2
		//int temp = parent[v2];  //parent[v2] 값 임시 저장
		parent[v1] += parent[v2];  //parent[v1]에 원소값 추가 
		parent[v2] = v1;  //정점 v2 node는 정점v1을 부모로 가짐 
	}
	else {
		//-2   -4
		//int temp = parent[v1];
		parent[v2] += parent[v1];
		parent[v1] = v2;
	}
}