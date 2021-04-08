#include <stdio.h>
#include <stdlib.h>   // 퀵정렬을 사용하기 위한 헤더파일 
#define MAX 100

//비용 인접 행렬(가중치를 나타냄)
int graph[9][9] = { {0, 4, -1, -1, -1, -1, -1, 8, -1},
					{4, 0, 8, -1, -1, -1, -1, 11, -1},
					{-1, 8, 0, 7, -1, 4, -1, -1, 2},
					{-1, -1, 7, 0, 9, 14, -1, -1, -1},
                    {-1, -1, -1, 9, 0, 10, -1, -1, -1},
	                {-1, -1, 4, 14, 10, 0, 2, -1, -1},
                    {-1, -1, -1, -1, -1, 2, 0, 1, 6},
                    {8, 11, -1, -1, -1, -1, 1, 0, 7},
					{-1, -1, 2, -1, -1, -1, 6, 7, 0},
};

typedef struct edge {  //간선 집합을 위한 구조체 
	int weight; //간선 가중치 
	int v1;  //정점1
	int v2;  //정점2
}Edge;

int parent[MAX];  //vertex의 최대 개수는 100개까지 가능, input_graph의 경우 vertex=9
int count[MAX]; //각 노드 집합의 개수를 따로 저장하기 위한 배열 
Edge edge_set[MAX];  //유효한 간선만 저장하기 위해 Edge구조체를 배열로 선언

void init_set(int n) {  //노드들을 초기 상태로 setting
	int i;
	for (i = 0; i < n; i++) {
		parent[i] = -1;  //parent 배열을 -1(root node)로 초기화
		count[i] = 1;  //초기의 노드 집합은 모두 1개로 구성 
	}
}

/*
int find(int vertex) {   //parent node를 찾는 함수 , 붕괴법칙 사용 x 
	if (parent[vertex] < 0) {  //based condition
		return parent[vertex];
	}
	else {
		return parent[vertex] = find(parent[vertex]);
	}
}  
*/

int find(int vertex) {
	int p, s, i = 0;
	for (i = vertex; (p = parent[i]) > 0; i = p)
		;
	s = i;
	return s;
}  
                               
void set_union(int v1, int v2) {  // 0  3  
	/*if (v1 > v2) {
		int temp = v1;
		v1 = v2;
		v2 = temp;
	} */
	if ((parent[v1] < 0) && (parent[v2] <  0)) {  //부모 노드가 초기 노드(-1)이라면 
		if (count[v1] < count[v2]) {
			parent[v1] = v2;
			count[v2] += count[v1];
			
		}
		else {
			parent[v2] = v1;
			count[v1] += count[v2];
			
		}
	}
	else if ((parent[v1] > 0) && (parent[v2] < 0)) { // 정점 v1 집합이 루트 노드가 아닐때
		count[v1] += count[parent[v1]]; //집합에 속한 노드의 개수를 모두 더한다
		if (count[v1] < count[v2]) {
			parent[v1] = v2;
			count[v2] += count[v1];
		}
		else {
			parent[v2] = v1;
			count[v1] += count[v2];
		}
	}

	else if ((parent[v1] < 0) && (parent[v2] )) {
		count[v2] += count[6]; //집합에 속한 노드의 개수를 모두 더한다
		if (count[v1] < count[v2]) {
			parent[v1] = v2;
			count[v2] += count[v1];
		}
		else {
			parent[v2] = v1;
			count[v1] += count[v2];
		}
	}
	



	/*
	if (parent[v1] <= parent[v2]) {  //정점 v1 배열이 더 많은 원소를 가질 때(음수니까 반대로)
		//-4   -2
		//int temp = parent[v2];  //parent[v2] 값 임시 저장
		parent[v1] += parent[v2];  //parent[v1]에 원소값 추가 
		parent[v2] = v1;  //정점 v2 node는 정점v1을 부모로 가짐 
	}
	else {  //정점 v2 배열이 더 많은 원소를 가질 때 
		//1   -1
		//int temp = parent[v1];
		parent[v2] += parent[v1];  
		parent[v1] = v2;
	}
	*/

	for (int i = 0; i < 9; i++) {
		printf("%3d", parent[i]);
	}
	printf("\n");
	for (int i = 0; i < 9; i++) {
		printf("%3d", count[i]);

	}
	printf("\n");
}

int set_Edge(int n) { //비용인접행렬에서 유효한 값들만 대상으로 edge_set(배열)를 만듬 
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {  //비용인접행렬은 대칭행렬
			if (graph[i][j] > 0) {  //가중치가 유효한 값이라면
				edge_set[idx].weight = graph[i][j];  //가중치 
				edge_set[idx].v1 = i;   //정점 1
				edge_set[idx].v2 = j;   //정점 2
				idx++;
			}
			
			
		}
	}
	return idx;
}

int compare(const void* a, const void* b) {  //quicksort에서 사용될 비교 함수
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;

	if (e1->weight < e2->weight) return -1;
	if (e1->weight > e2->weight) return 1;
	return 0;
}

void kruskal(int n, int edge_count) {  //minimum Spanning Tree 함수, 최소 비용을 구하기 위한 함수 
	int mst_e = 0; //최소 비용을 저장 
	int mst_e_count = 0;  //최소 비용 신장 트리에 추가될 간선 수 저장 
	qsort(edge_set, edge_count, sizeof(Edge), compare); //정렬할 배열, 요소개수, 요소크기, 비교함수
	init_set(n); //parent node 배열을 -1로 초기화 

	for (int i = 0; mst_e_count < n - 1; i++) {  //edge = vertex-1
		int x = find(edge_set[i].v1);
		int y = find(edge_set[i].v2);
		printf("%d : %d, %d : %d\n", edge_set[i].v1, x, edge_set[i].v2, y);

		if ((x < 0 && y < 0) || x != y) {
			printf("간선 (%d, %d) 추가\n", edge_set[i].v1, edge_set[i].v2);
			mst_e += edge_set[i].weight;
			mst_e_count++;
			set_union(edge_set[i].v1, edge_set[i].v2);

		}
	}
	printf("최소 비용은 %d 입니다.\n", mst_e);


}


int main(void) {
	int edge = set_Edge(9);  //비용 인접 행렬로부터 만들어진 유효한 간선의 수(싸이클 포함) return 
	printf("%d\n", edge);
	kruskal(9, edge);
}