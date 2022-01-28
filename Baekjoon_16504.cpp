#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n, input, sum = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n*n; i++) {
		scanf("%lld", &input);
		sum += input;
	}
	printf("%lld\n", sum);
  return 0; 
}
