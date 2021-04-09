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

int count[MAX]; //parent node와 집합의 node 개수를 따로 구분하기 위한 Array 
int parent[MAX];  //vertex의 최대 개수는 100개까지 가능, input_graph의 경우 vertex=9
Edge edge_set[MAX];  //유효한 간선만 저장하기 위해 Edge구조체를 배열로 선언


void init_set(int n) {  //parent 배열과 count 배열 초기 상태로 setting
	int i;
	for (i = 0; i < n; i++) {
		parent[i] = i;  //parent node들은 -1이 아닌 각자 자기 인덱스를 가리키도록 설정
		count[i] = 1;   //초기 상태에서 node들은 모두 집합의 node 하나씩을 가지고 있음 
	}

}


int find(int vertex) {   //root node를 찾는 함수 
	if (parent[vertex] == vertex) {  //based condition
		return parent[vertex];     //자신의 인덱스를 가리키면 return 
	}
	else {
		parent[vertex] = find(parent[vertex]);   //based condition 에 만족할때까지 반복 
	}
}

//정점 v1, v2 집합을 합병하는 함수 
void set_union(int v1, int v2) {
	int p1 = find(v1);  //정점 v1이 속한 집합의 root node find
	int p2 = find(v2);  //정점 v2가 속한 집합의 root node find 
	if (count[p1] < count[p2]) {  //v1 집합의 node 개수가 v2 보다 적거나 같을때
		parent[p1] = p2;  // 바로 위의 parent node가 아닌 root node로 연결 (collapsing Rule) 
		parent[v1] = p2;  // 자식들도 root node와 연결 
		count[p2] += count[v1];  //count 배열의 root node index에 집합의 node 개수 추가 
	}
	else {   //v1 집합의 node 개수가 v2 보다 많을 경우 
		parent[p2] = p1;  //바로 위 parent node가 아닌 root node로 연결
		parent[v2] = p1;  //root node(p2)의 집합에 소속되어있는 node들도 root node로 연결 
		count[p1] += count[v2]; //count 배열의 root node index에 집합의 node 개수 추가 
	}


	//부모 노드의 상태를 union 할 때마다 알아볼 수 있게 출력 
	printf(" Root ------>");
	for (int i = 0; i < 9; i++) {   
		printf("%4d", parent[i]);
	}
	printf("\n");

	//count 노드의 상태를 union 할 때마다 알아볼 수 있게 출력 
	printf("Count ------>");
	for (int i = 0; i < 9; i++) {
		printf("%4d", count[i]);
	}
	printf("\n");
	printf("\n");
}

int set_Edge(int n) { //비용인접행렬에서 유효한 값들만 대상으로 edge_set(배열)를 만듬 
	int idx = 0;   //필요한 간선의 수 return 시켜주기 위한 값 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {  //비용인접행렬은 대칭행렬
			if (graph[i][j] > 0) {  //가중치가 유효한 값이라면
				edge_set[idx].weight = graph[i][j];  //가중치 
				edge_set[idx].v1 = i;   //정점 1
				edge_set[idx].v2 = j;   //정점 2
				idx++;
			}
		}
	}
	return idx;  //유효한 간선의 수
}

int compare(const void* a, const void* b) {  //quicksort에서 사용될 비교 함수
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;

	if (e1->weight < e2->weight) return -1;    // e1가중치가 e2가중치보다 작을 경우 -1
	if (e1->weight > e2->weight) return 1;     // e1가중치가 e2가중치보다 클 경우 1
	return 0;   // 가중치가 같을 경우 0 
}

void kruskal(int n, int edge_count) {  //minimum Spanning Tree 함수, 최소 비용을 구하기 위한 함수 
	int mst_e = 0; //최소 비용을 저장 
	int mst_e_count = 0;  //최소 비용 신장 트리에 추가될 간선 수 저장 
	qsort(edge_set, edge_count, sizeof(Edge), compare); //정렬할 배열, 요소개수, 요소크기, 비교함수
	init_set(n); //parent node 배열을 index값으로 초기화, count 배열 1로 setting 


	//맨 처음 상태의 parent node print
	printf("초기 root node ---->");
	for (int i = 0; i < 9; i++) {
		printf("%4d", parent[i]);
	}
	printf("\n");
	printf("\n");

	for (int i = 0; mst_e_count < n - 1; i++) {  //edge = vertex-1
		//오름차순으로 정렬된 edge_set 구조체를 이용 root node를 찾음 
		int x = find(edge_set[i].v1);
		int y = find(edge_set[i].v2);
		printf("vertex %d의 root node : %d\n", edge_set[i].v1, x);  //정점을 식별하고 대표값 식별 
		printf("vertex %d의 root node : %d\n", edge_set[i].v2, y);

		if (x != y) {   //두 개의 root node 값이 다를 경우 union 가능 
			printf("Edge(%d, %d) 추가\n", edge_set[i].v1, edge_set[i].v2);
			mst_e += edge_set[i].weight;   //각 간선의 가중치를 더해 최소 비용 구함
			mst_e_count++;  //mst를 이루는데 필요한 간선 
			set_union(edge_set[i].v1, edge_set[i].v2);  //두 개의 정점이 속한 집합 합병 
		}
	}
	printf("Total weight : %d\n", mst_e);   //MST 에 필요한 가중치 
}


int main(void) {
	int edge = set_Edge(9);  //비용 인접 행렬로부터 만들어진 유효한 간선의 수(싸이클 포함) return 
	kruskal(9, edge); //input_graph의 정점과 간선의 개수를 인자로 전달 
}