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
Edge edge_set[MAX];  //유효한 간선만 저장하기 위해 Edge구조체를 배열로 선언

void init_set(int n) {  //노드들을 초기 상태로 setting
	int i;
	for (i = 0; i < n; i++) {
		parent[i] = -1;  //parent 배열을 -1(root node)로 초기화
		
	}
}


int find(int vertex) {   //root node(대표값)를 찾는 함수 , 붕괴법칙 사용 x 
	if (parent[vertex] < 0) {  //based condition
		return parent[vertex];
	}
	//based condition을 만족할 때 까지 재귀 호출 
	else {
		return find(parent[vertex]);  
	}
}  
               
//정점 v1, v2 집합을 합병하는 함수 
void set_union(int v1, int v2) {   
	if ((parent[v1] < 0 && parent[v2] <  0)) {  //부모 노드가 root node(음수)일 경우 
		if (parent[v1] <= parent[v2]) {   //  ex) -4  <=  -1  
			parent[v1] += parent[v2];   // 음수이므로 값이 더 작을수록 집합의 개수가 더 많다.
			parent[v2] = v1;           //집합의 개수가 적은쪽이 큰쪽으로 합병   
		}
		else {  // v2 집합이 v1 집합보다 많을 경우 
			parent[v2] += parent[v1];  //집합의 개수가 적은 v1집합이 v2집합으로 합병(v2밑으로 v1이 들어감) 
			parent[v1] = v2;
		}
	}
	else if ((parent[v1] >= 0) && (parent[v2] < 0)) { // 정점 v1 = root node가 아니고
		                                              // 정점 v2 = root node일 경우 	
		int p1 = find(v1);    // 정점 v1이 속한 집합의 root node(대표값)를 찾음 

		if (p1 <= parent[v2]) {  // v1 집합의 원소 개수가 v2 집합보다 많거나 같을 경우 
			parent[parent[parent[v1]]] += parent[v2]; //집합의 개수가 적은 v2 집합이 v1집합으로 합병 
			parent[v2] = v1;
		}
		else {   //v2 집합이 v1 집합보다 많을 경우 
			parent[parent[parent[v2]]] += parent[v1]; //집합의 개수가 적은 v1 집합이 v2 집합으로 합병 
			parent[v1] = v2;
		}
	}

	else if ((parent[v1] < 0) && (parent[v2] >= 0)) { // 정점 v1 = root node이고 
		                                              // 정점 v2 = root node가 아닐 경우 
		int p2 = find(v2) ;   // 정점 v2가 속한 집합의 루트 노드(대표값)를 찾음 

		if (p2 <= parent[v1]) {  //v2 집합이 v1집합의 개수보다 같거나 많을 때
			parent[parent[v2]] += parent[v1];  //개수가 적은 v1집합이 v2집합으로 합병
			parent[v1] = v2;
		}
		else {  //v1 집합이 v2 집합보다 많을 경우 
			parent[parent[v1]] += parent[v2];   //개수가 적은 v2집합이 v1집합으로 합병(v2가 v1밑으로 들어감)
			parent[v2] = v1; 
		}
	}

	else if((parent[v1] >= 0) && (parent[v2] >= 0)) {  //정점 v1, v2 모두 root node 일 경우 
		int p1 = find(v1);  //정점 v1이 속한 집합의 root node를 찾음
		int p2 = find(v2);  //정점 v2가 속한 집합의 root node를 찾음 
		if (p2 <= p1) {   //음수끼리 비교하므로 작을수록 더 많은 원소 갖고 있음 
			parent[parent[parent[v2]]] += parent[parent[v1]];  //개수가 적은 v1집합이 v2집합으로 합병
			parent[parent[v1]] = v2;               
		}
		else {  // p2 > p1  --> v1이 속한 집합의 node개수가 v2집합보다 많음
			parent[parent[v1]] += parent[v2];  //.개수가 적은 v2집합이 v1집합으로 합병 
			parent[v2] = v1;
		}
	}

	//부모 노드의 상태를 union 할 때마다 알아볼 수 있게 출력 
	printf("Parent node --->");   
	for (int i = 0; i < 9; i++) { 	
		printf("%4d", parent[i]);
	}
	printf("\n");
	printf("\n");
}

int set_Edge(int n) { //비용인접행렬에서 유효한 값들만 대상으로 edge_set(배열)를 만듬 
	int idx = 0;   //필요한 간선의 수 return 시켜주기 위한 값 
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {  //비용인접행렬은 대칭행렬(상위 삼각값만 저장) 
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

	if (e1->weight < e2->weight) return -1;   // e1가중치가 e2가중치보다 작을 경우 -1
	if (e1->weight > e2->weight) return 1;    // e1가중치가 e2가중치보다 클 경우 1 
	return 0;  // 가중치가 같을 경우 0 
}

void kruskal(int n, int edge_count) {  //minimum Spanning Tree 함수, 최소 비용을 구하기 위한 함수 
	int mst_e = 0; //최소 비용을 저장 
	int mst_e_count = 0;  //최소 비용 신장 트리에 추가될 간선 수 저장 
	qsort(edge_set, edge_count, sizeof(Edge), compare); //정렬할 배열, 요소개수, 요소크기, 비교함수
	init_set(n); //parent node 배열을 -1로 초기화 

	for (int i = 0; mst_e_count < n - 1; i++) {  //edge = vertex-1
		//비용인접행렬을 이용하여 저장한 구조체 배열 edge_set 를 이용하여 정점 1,2의 root node find  
		int x = find(edge_set[i].v1);  
		int y = find(edge_set[i].v2);  
		printf("vertex %d의 root node : %d\n", edge_set[i].v1, x);  //정점을 식별하고 대표값 식별 
		printf("vertex %d의 root node : %d\n", edge_set[i].v2, y);
		
		if ((x == -1 && y == -1) || x != y) {  //초기상태의 노드(-1)는 합병 union 가능
			printf("Edge(%d, %d) 추가\n", edge_set[i].v1, edge_set[i].v2);
			mst_e += edge_set[i].weight;   //총 가중치 계산 
			mst_e_count++;   //mst에서 간선은 정점의 개수-1이므로 정점의 개수-1이 되면 break;
			set_union(edge_set[i].v1, edge_set[i].v2);   //조건에 맞으면 두개의 정점 union 

		}
	}
	printf("Total weight : %d\n", mst_e);  //MST를 구성하는데 필요한 간선의 가중치의 합 


}


int main(void) {
	int edge = set_Edge(9);  //비용 인접 행렬로부터 만들어진 유효한 간선의 수 return 
	kruskal(9, edge);  //인자로 input_graph의 정점 개수, 간선의 수를 전달 
}