#include <iostream>
using namespace std;

typedef pair<long long, long long> ii;

int ccw(ii a, ii b, ii c) {
	ii ab = {b.first - a.first, b.second - a.second};
	ii ac = {c.first - a.first, c.second - a.second};
	long long d = (ab.first * ac.second) - (ab.second * ac.first);
	if (d > 0) return 1;
	else if (d < 0) return -1;
	else return 0;
}

bool cross(ii a, ii b, ii c, ii d) {
	int d1 = ccw(a, b, c) * ccw(a, b, d);
	int d2 = ccw(c, d, a) * ccw(c, d, b);
	if (!d1 && !d2) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && d >= a;
	}
	else return d1 <= 0 && d2 <= 0;
}

int main() {
	ii dot[4];
	for (int i = 0; i < 4; ++i) cin >> dot[i].first >> dot[i].second;

	cout << cross(dot[0], dot[1], dot[2], dot[3]);
}