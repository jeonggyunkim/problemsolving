#include <iostream>
using namespace std;

typedef pair<int, int> ii;

int ccw(ii& p, ii& q, ii& r) {
	return (q.first - p.first) * (r.second - p.second) - (q.second - p.second) * (r.first - p.first);
}

int main() {
	ii p[3];
	for (int i = 0; i < 3; ++i) {
		cin >> p[i].first >> p[i].second;
	}

	int c = ccw(p[0], p[1], p[2]);
	if (c < 0) cout << -1;
	else if (c > 0) cout << 1;
	else cout << 0;
}