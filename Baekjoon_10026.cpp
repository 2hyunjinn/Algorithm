#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;
/* 적록색약 아닌 사람 */
char map[101][101];
bool visit[101][101];

/* 적록색약 */
char map2[101][101];
bool visit2[101][101];

int n;
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; // 상하좌우 이동

void Yes_dfs(int x, int y) {
	visit[x][y] = true; // 방문했다고 표시
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx >= 0 && ny >= 0 && nx <= n && ny <= n) {
			if (!visit[nx][ny] && (map[nx][ny] == map[x][y])) {
				Yes_dfs(nx, ny);
			}
		}
	}
}

void No_dfs(int x, int y) {
	visit2[x][y] = true; // 방문했다고 표시
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx >= 0 && ny >= 0 && nx <= n && ny <= n) {
			if (!visit2[nx][ny] && (map2[nx][ny] == map2[x][y])) {
				No_dfs(nx, ny);
			}
		}
	}
}

void input() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'G') map2[i][j] = 'R';
			else map2[i][j] = map[i][j];
		}
		getchar();
	}
}

int main(void) {
	input();

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) { // 아직 방문 안했으면
				cnt++; // 영역의 개수 증가
				Yes_dfs(i, j); // 해당좌표보냄
			}
		}
	}
	printf("%d ", cnt); // 영역의 개수

	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit2[i][j] == false) { // 아직 방문 안했으면
				cnt++; // 영역의 개수 증가
				No_dfs(i, j); // 해당좌표보냄
			}
		}
	}
	printf("%d\n", cnt); // 영역의 개수
	return 0;
}
