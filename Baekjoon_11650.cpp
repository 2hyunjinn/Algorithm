#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair <int, int>> p;

/* 좌표 입력 */
void input_info() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		p.push_back(pair<int, int>(a, b));
	}
}

/* 좌표 출력 */
void print_info() {
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", p[i].first, p[i].second);
	}
}
int main() {
	input_info();
	sort(p.begin(), p.end());
	print_info();
	return 0;
}
