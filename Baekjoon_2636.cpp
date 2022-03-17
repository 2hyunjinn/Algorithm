#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int R, C;
int cheese[100][100];
bool visited[100][100];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int result, time_ = 0;

bool bfs() {
	visited[0][0] = true; // 방문했다고 표시
	queue<pair<int, int>> q;
	q.push({ 0,0 }); // 해당 좌표를 넣음

	int cnt = 0; // 치즈의 개수 0으로 초기화
	time_++; // 시간증가

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		/* 좌표 (r,c) 기준으로 동서남북 4방향 모두 탐색 */
		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];

			/* 범위 안에 있으면 탐색 */
			if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
				if (cheese[nr][nc] == 0) { //인접한 칸이 0이면 계속 탐색
					q.push({ nr,nc }); // 해당 좌표를 넣음
				}
				else { //인접한 칸이 치즈면 치즈를 0으로 바꿔주고 카운팅
					cheese[nr][nc] = 0; // 방문했기 때문에 0으로 바꿔줌
					cnt++; // 치즈 개수 증가
				}
				visited[nr][nc] = true; // 해당 좌표는 방문함
			}
		}
	}

	//치즈가 없다면 시간과, 이전 bfs에서 나온 치즈의 개수를 출력한 후 true반환
	if (cnt == 0) {
		printf("%d\n%d\n", --time_, result);
		return true;
	}
	//치즈가 있다면 결과(치즈의 개수) 갱신
	else {
		result = cnt;
		return false;
	}
}

void input() {
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &cheese[i][j]);
		}
	}
}

int main() {
	input();

	//치즈가 없을 때까지
	while (true) {
		if (bfs())
			break;
		memset(visited, false, sizeof(visited)); // visited 다시 초기화
	}

	return 0;
}
