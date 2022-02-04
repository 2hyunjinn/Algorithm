#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
typedef long long ll;

ll gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);
	ll big, small;
	(a > b) ? (big = a, small = b) : (big = b, small = a);
    
  ll gcd_V = gcd(big, small);
	printf("%lld", gcd_V*(big/gcd_V)*(small/gcd_V));
	return 0;
}
