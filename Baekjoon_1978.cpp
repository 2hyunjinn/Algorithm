#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int n;

bool primeN(int input) {
	if (input == 1) return false; // 1은 소수가 아님
	else if (input == 2) return true; // 2는 소수임
	else {
		for (int i = 2; i <= sqrt(input); i++) { // input의 제곱근까지
			for (int j = i + i; j <= input; j += i) { // 어떤 수의 배수는 소수 아님
				if (j == input) return false; // 어떤 수의 배수가 input이라면 소수 아님
			}
		}
		return true; // 어떤 수의 배수도 아니라면 소수임
	}
}

int main(){
	scanf("%d", &n);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		if (primeN(input)) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
