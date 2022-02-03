#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
int n;
vector<ll> v;

/* 숫자 뒤집기 */
ll reverse_num(ll input) {
	if (input < 10) return input; // 일의 자리 수라면
	
	ll sum = input % 10;
	while (1) {
		input /= 10;
		sum = (sum * 10) + (input % 10);
		if (input % 10 == input) return sum;
	}
}

/* 숫자 입력 */
void input_info() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll input;
		scanf("%lld", &input);
		v.push_back(reverse_num(input));
	}
}

void print_info() {
	for (int i = 0; i < n; i++)
		printf("%lld\n", v[i]);
}

int main() {
	input_info();
	sort(v.begin(), v.end());
	print_info();

	return 0;
}
