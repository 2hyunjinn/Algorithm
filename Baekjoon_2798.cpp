#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int card[100];
	for (int i = 0; i < n; i++) cin >> card[i];

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				if (card[i] + card[j] + card[k] <= m) {
					sum = max(sum, (card[i] + card[j] + card[k]));
				}
				if (sum == m) break;
			}
		}
	}
	cout << sum;
	return 0;
}
