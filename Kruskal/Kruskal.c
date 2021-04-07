#include <stdio.h>
#include <stdlib.h>   // 퀵정렬을 사용하기 위한 헤더파일 
#define MAX 100

//비용 인접 행렬(가중치를 나타냄)
int graph[9][9] = { 0, 4, -1, -1, -1, -1, -1, 8, -1,
				   4, 0, 8, -1, -1, -1, -1, 11, -1,
				   -1, 8, 0, 7, -1, 4, -1, -1, 2,
				   -1, -1, 7, 0, 9, 14, -1, -1, -1,
				   -1, -1, -1, 9, 0, 10, -1, -1, -1,
				   -1, -1, 4, 14, 10, 0, 2, -1, -1,
				   -1, -1, -1, -1, -1, 2, 0, 1, 6,
				   8, 11, -1, -1, -1, -1, 1, 0, 7,
				   -1, -1, 2, -1, -1, -1, 6, 7, 0,
};

typedef struct edge {  //간선 집합을 위한 구조체 
	int weight; //간선 가중치 
	int v1;  //정점1
	int v2;  //정점2
}Edge;

int parent[MAX];  //vertex의 최대 개수는 100개까지 가능, input_graph의 경우 vertex=9
Edge edge_set[MAX];  //유효한 간선만 저장하기 위해 Edge구조체를 배열로 선언

void init_set(int n) {  //parent 배열을 -1(root node)로 초기화
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

int find(int vertex) {   //parent node를 찾는 함수 , 붕괴법칙 사용 x 
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

	if (parent[v1] <= parent[v2]) {  //정점 v1 배열이 더 많은 원소를 가질 때(음수니까 반대로)
		//-4   -2
		//int temp = parent[v2];  //parent[v2] 값 임시 저장
		parent[v1] += parent[v2];  //parent[v1]에 원소값 추가 
		parent[v2] = v1;  //정점 v2 node는 정점v1을 부모로 가짐 
	}
	else {  //정점 v2 배열이 더 많은 원소를 가질 때 
		//-2   -4
		//int temp = parent[v1];
		parent[v2] += parent[v1];  
		parent[v1] = v2;
	}
}

void set_Edge(int* Graph, int n) {
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (graph[i][j] != -1) {  //가중치가 유효한 값이라면
				edge_set[idx].weight = graph[i][j];  //가중치 
				edge_set[idx].v1 = i;   //정점 1
				edge_set[idx].v2 = j;   //정점 2
				idx++;
			}
			
		}
	}
}


int main(void) {
	set_Edge(graph, 9);

}