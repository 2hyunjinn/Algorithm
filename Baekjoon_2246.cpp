#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n; // 콘도 개수
vector<pair<int, int>> condo; // 콘도 거리, 가격

/* 콘도 정보 입력 */
void input_info() {
	scanf("%d", &n); // 콘도 개수 입력
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		condo.push_back(pair<int, int>(a, b));
	}
}

/* 후보 개수 구하기 */
int get_candidate() {
	int cnt = 1;
	int min_d = condo[0].first, min_c = condo[0].second; // 기준점
	for (int i = 1; i < n; i++) {
		if (min_d == condo[i].first) continue;		
		if (condo[i].second < min_c) {
			min_d = condo[i].first;
			min_c = condo[i].second;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	input_info();
	sort(condo.begin(), condo.end()); // 순서대로 정렬
	printf("%d\n", get_candidate());
	return 0;
}
