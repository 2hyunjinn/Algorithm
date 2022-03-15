#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int n, m;
int r, w;
int row[4] = { 0, 0, 1, -1 }; // 아래 위
int col[4] = { -1, 1, 0, 0 }; // 왼 오

struct node {
	int x;
	int y;
	int cnt;
};
node q[10000];

char arr[100][100] = { 0 };
bool miro[100][100] = { 0 };

void input() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	r = w = 0;
}

/* 큐 삽입 */
void enqueue(node n_) {
	q[w++] = n_;
}

/* 큐 삭제 */
node dequeue() {
	return q[r++];
}

/* 큐가 비어있는지 */
bool IsEmpty() {
	return r == w ? true : false; // 비면 true 반환
}

/* 가능한 경로인지 여부 */
bool chk(node n_) {
	if (arr[n_.x][n_.y] == '0') return false; // 갈 수 있는 길인지
	if (miro[n_.x][n_.y] == 1) return false; // 이미 탐색한 길인지
	if (n_.x >= n || n_.x < 0 || n_.y >= m || n_.y < 0)
		return false; // 범위 바깥인지

	return true; // 위 3개의 조건만 아니면 탐색 가능
}

int bfs() {
	node nd = { 0,0,1 }; // 시작점
	miro[0][0] = true; // 방문함
	enqueue(nd); // 큐 삽입

	while (!IsEmpty()) {
		nd = dequeue(); // 큐 삭제
		for (int i = 0; i < 4; i++) { // 4방향 접근
			node tmp = { nd.x + row[i], nd.y + col[i], nd.cnt + 1 };
			if (chk(tmp)) {
				if (tmp.x == n - 1 && tmp.y == m - 1)
					return tmp.cnt;
				enqueue(tmp);
				miro[tmp.x][tmp.y] = true;
			}
		}
	}
}

int main(){
	input();
	printf("%d\n", bfs());
	return 0;
}
