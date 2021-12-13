#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;

// CCW
int ccw(ii a, ii b, ii c) {
	ii ab = {b.first - a.first, b.second - a.second};
	ii ac = {c.first - a.first, c.second - a.second};
	long long d = (ab.first * ac.second) - (ab.second * ac.first);
	if (d > 0) return 1;
	else if (d < 0) return -1;
	else return 0;
}


// cross
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


// convex hull
long long ccw(ii& p, ii& q, ii& r) {
	return (q.first - p.first) * (r.second - p.second) - (q.second - p.second) * (r.first - p.first);
}

long long dist(ii& a, ii& b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int n;
vector<ii> arr(n);

sort(arr.begin(), arr.end());
sort(arr.begin() + 1, arr.end(), [](ii& x, ii& y) {
	return ccw(arr[0], x, y) > 0 || (ccw(arr[0], x, y) == 0 && dist(arr[0], x) < dist(arr[0], y));
});

stack<int> s;
s.push(0); s.push(1);

int next = 2;
while (next < n) {
	while (s.size() >= 2) {
		int first, second;
		second = s.top();
		s.pop();
		first = s.top();

		if (ccw(arr[first], arr[second], arr[next]) > 0) {
			s.push(second);
			break;
		}
	}
	s.push(next++);
}