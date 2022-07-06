#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> v(9);

	for (int i = 0; i < 9; i++) {
		scanf("%d", &v[i]);
	}
	printf("%d\n", *max_element(v.begin(), v.end()));
	printf("%d\n", max_element(v.begin(), v.end()) - v.begin() + 1);
	return 0;
}
