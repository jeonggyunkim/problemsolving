#include <iostream>
using namespace std;

struct D { int x, y; };

int ccw(D& p, D& q, D& r) {
	return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

int main() {
	D d[4];
	cin >> d[0].x >> d[0].y;
	cin >> d[2].x >> d[2].y;
	cin >> d[1].x >> d[1].y;
	cin >> d[3].x >> d[3].y;

	int c = ccw(d[0], d[1], d[2]);
	for (int i = 1; i < 3; ++i) {
		int t = ccw(d[i % 4], d[(i + 1) % 4], d[(i + 2) % 4]);
		if ((long long)c * t <= 0) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}