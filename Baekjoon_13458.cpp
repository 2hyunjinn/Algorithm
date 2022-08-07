#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, b, c;
	vector<int> v;

	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> b >> c;

	ll sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// 총감독관은 1명만 가능
		v[i] -= b; sum++; 

		if (v[i] > 0) {
			// 부감독관
			sum += (v[i] / c);
			if (v[i] % c) sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
