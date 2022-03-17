#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
int ice[300][300];
int tmp[300][300];
bool visited[300][300];

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y }); // 해당 좌표를 넣음

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		/* 좌표 (x,y) 기준으로 동서남북 4방향 모두 탐색 */
		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];

			/* 범위 안에 있으면 탐색 */
			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				if(ice[nr][nc] != 0 && !visited[nr][nc]) {
					q.push({ nr,nc }); // 해당 좌표를 넣음
					visited[nr][nc] = true; // 방문함
				}
			}
		}
	}
}

void melt_ice() {
	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] == 0) continue;

			// 빙산이라면 동서남북 검사해서 0의 개수만큼 높이 감소
			int water_cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dir[k][0];
				int nc = j + dir[k][1];

				/* 범위 안에 있으면 탐색 */
				if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
					if(ice[nr][nc] == 0) { // 빙산이 아니라면
						water_cnt++;
					}
				}
			}
			int val = ice[i][j] - water_cnt;
			if (val > 0) tmp[i][j] = val;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ice[i][j] = tmp[i][j];
		}
	}
}

void input() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ice[i][j]);
		}
	}
}

int main() {
	input();

	int time_ = 0;
	// 빙산 여부 확인
	while (true) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 빙산이라면
				if (!visited[i][j] && ice[i][j] != 0) { 
					bfs(i, j);
					cnt++; // 빙산덩이 수 증가
				}
			}
		}
		
		// 빙산이 다 녹았으면
		if (cnt == 0) {
			printf("0\n");
			break;
		}
		// 빙산이 두 덩어리 이상이라면
		else if (cnt >= 2) {
			printf("%d\n", time_);
			break;
		}

		time_++;
		// 아직 한참 남았다면
		melt_ice(); // 빙산 녹이기
		memset(visited, false, sizeof(visited)); // 방문기록 다 없애기
	}
	return 0;
}
