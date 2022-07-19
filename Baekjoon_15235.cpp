#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;

	queue<pair<int, int>> people;
	for (int i = 0; i < n; i++) {
		int pizza;
		cin >> pizza;
		people.push({ i, pizza }); // index, slices of pizza
	}

	vector<int> time(n);
	int cnt = 0;
	while(!people.empty()) {
    cnt++; // increase in time
    
		int idx = people.front().first; // index
		int pizza = --people.front().second; // minus the number of pizzas
		people.pop();
    
    // if people don't need pizza anymore
		if (!pizza) {
			time[idx] = cnt; // time so far
			continue;
		}
		people.push({ idx, pizza });
	}

	for (int i = 0; i < n; i++) cout << time[i] << ' ';
	return 0;
}
