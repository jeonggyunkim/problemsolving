#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

struct p {
	int x, y;
	p() {};
	p(int x, int y) : x(x), y(y) {};
	bool operator < (const p& v) const{
		if (y != v.y) return y < v.y;
		else return x < v.x;
	}
};

int dist(p a, p b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool comp(p& a, p& b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

p dot[100001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &dot[i].x, &dot[i].y);
	sort(dot, dot + n, comp);

	set<p> s;
	s.insert(dot[0]);
	s.insert(dot[1]);
	int ans = dist(dot[0], dot[1]);

	vector<p> del;
	for (int i = 2; i < n; ++i) {
		int d = ceil(sqrt(ans));
		p low = p(-100000, dot[i].y - d);
		p high = p(100000, dot[i].y + d);
		auto lb = s.lower_bound(low);
		auto ub = s.upper_bound(high);
		for (auto it = lb; it != ub; ++it) {
			if (dot[i].x - (*it).x >= d) {
				del.push_back(*it);
				continue;
			}
			int dd = dist(dot[i], *it);
			if (dd < ans) ans = dd;
		}
		while (!del.empty()) {
			s.erase(del.back());
			del.pop_back();
		}
		s.insert(dot[i]);
	}
	printf("%d\n", ans);
}