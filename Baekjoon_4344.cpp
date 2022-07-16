#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(3);
	cout << fixed;

	int c;
	cin >> c;
	while (c--) {
		double n, score, cnt = 0;
		vector<double> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> score;
			v.push_back(score);
		}

		int avg = (accumulate(v.begin(), v.end(), 0) / n);
		for (int i = 0; i < n; i++) {
			if (v[i] > avg) {
				cnt++;
			}
		}
		
		cout << 100.0/(n/ cnt) << "%\n";
	}
	return 0;
}
