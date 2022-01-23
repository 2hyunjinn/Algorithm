#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

// n - 정점의 개수
// m - 간선의 개수
// v - 정점의 번호
int n, m, v;
int arr[1000][1000] = { 0 }; // 양방향 간선 (a,b), (b,a) 모두 저장할 수 있도록 2차원 배열
int idx_BFS[1000] = { 0 }; // BFS 탐색 여부 확인용
int visit_DFS[1000] = { 0 }; // DFS 탐색 여부 확인용

void start_DFS(int now) {
	printf("%d ", now); // 탐색한 정점 출력
	/* 정점 now 탐색했다고 표시 */
	visit_DFS[now - 1] = 1; // index는 0부터기 때문에 now-1

	/* 탐색한 애를 기준으로 제일 작은 수 탐색 시작 */
	for (int i = 0; i < n; i++) {
		/* 무언가 값이 있고 탐색한 적 없다면 */
		if ((arr[now - 1][i] == 1) && (visit_DFS[i]) == 0)
			start_DFS(i + 1); // 걔를 탐색하도록 재귀 함수로 보내줌
	}
	return;
}

void start_BFS() {
	static int cnt = 0;// 탐색한 정점의 개수
	static int idx = 0;// 탐색할 정점의 index
	
	int now = v; // 탐색할 정점 저장
	int *next = (int*)calloc(n, sizeof(int)); // 다음 탐색할 정점 저장

	printf("\n%d", now); // 시작 정점 출력
	/* 모든 정점 탐색하면 탈출 */
	while (cnt < n - 1) {
		for (int i = 0; i < n; i++) { // 같은 레벨 탐색
			/* 해당 정점과 직접 연결된 값이 있다면 */
			if (arr[now - 1][i] == 1 && idx_BFS[i] == 1) {
				printf(" %d", i + 1); // 같은 레벨들 출력
				idx_BFS[i] = 0; // 다시 탐색 못하게 0으로 바꿈
				next[cnt] = i + 1; // 같은 레벨들 저장
				cnt++; // 인덱스 ++
			}
		}

		/*
		처음 정점이랑 연결된 간선 없으면 바로 break
		간선 하나여도 break
		*/
		if ((now == v && cnt == 0) || (now == v && cnt == 1))
			break;
		else {
			// 이제 같은 레벨 다 탐색함
			idx_BFS[now - 1] = 0; // 이 레벨은 이제 탐색함
			now = next[idx]; // 다음 수를 탐색할 정점으로 저장
			idx++; // 위와 같은 레벨에서 그 다음으로 작은 정점
		}
	}
	free(next);
	return;
}

int main(void) {
	scanf("%d%d%d", &n, &m, &v);

	/* 간선의 숫자만큼 반복문 */
	int a, b; // 간선이 연결하는 두 정점의 번호
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);

		/* 양방향 간선이므로 둘 다 저장 */
		arr[a - 1][b - 1] = 1; // (a,b)를 연결하는 간선 있다고 바꾸기
		arr[b - 1][a - 1] = 1; // (b,a)를 연결하는 간선 있다고 바꾸기

		/* 일단 이 인덱스에는 최소 1개 이상의 값이 있음 */
		idx_BFS[a - 1] = 1, idx_BFS[b - 1] = 1;
	}

	if (m == 0) // 간선이 0개이면
		printf("%d\n%d", v, v);
	else {
		start_DFS(v); // 깊이 우선 탐색
		start_BFS();  // 너비 우선 탐색
	}
	return 0;
}
