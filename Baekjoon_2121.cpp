#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
set<pair<int, int>> s;

int main() {
	int n;
	int x, y;
	vector<pair<int, int>> v;
    scanf("%d%d%d", &n,&x,&y);
	v.resize(n);
	for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i].first, &v[i].second);
		s.insert({ v[i].first,v[i].second });
	}
    
	int a, b;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		a = v[i].first;
		b = v[i].second;

		if (s.find({ a + x,b }) == s.end()) continue;
		if (s.find({ a,b + y }) == s.end()) continue;
		if (s.find({ a + x,b + y }) == s.end()) continue;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
