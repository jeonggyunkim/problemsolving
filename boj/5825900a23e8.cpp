#include <iostream>
using namespace std;

typedef pair<long long, long long> ii;

long long ccw(ii a, ii b, ii c) {
	ii ab = {b.first - a.first, b.second - a.second};
	ii ac = {c.first - a.first, c.second - a.second};
	return (ab.first * ac.second) - (ab.second * ac.first);
}

int main() {
	ii a, b, c, d;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	cin >> d.first >> d.second;

	long long d1 = ccw(a, b, c), d2 = ccw(a, b, d);
	if ((d1 > 0) == (d2 > 0)) cout << 0;
	else {
		d1 = ccw(c, d, a);
		d2 = ccw(c, d, b);
		if ((d1 > 0) == (d2 > 0)) cout << 0;
		else cout << 1;
	}
}