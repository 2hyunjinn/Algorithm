#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int chicken, beef, pasta, C, B, P;
	cin >> chicken >> beef >> pasta >> C >> B >> P;
	
	int sum = 0;
	if (C > chicken) sum += (C - chicken);
	if (B > beef) sum += (B - beef);
	if (P > pasta) sum += (P - pasta);

	cout << sum;
	return 0;
}
