#include <iostream>
#include <set>
#include <queue>
using namespace std;

typedef pair<long long, int> ii;

int main() {
	long long a, b;
	cin >> a >> b;

	set<long long> s;
	queue<ii> q;

	s.insert(a);
	q.push({a, 1});

	while (!q.empty()) {
		ii now = q.front(); q.pop();
		long long x = now.first * 2;
		long long y = now.first * 10 + 1;
		if (x == b || y == b) {
			cout << now.second + 1;
			return 0;
		}
		if (x <= b && !s.count(x)) {
			q.push({x, now.second + 1});
			s.insert(x);
		}
		if (y <= b && !s.count(y)) {
			q.push({y, now.second + 1});
			s.insert(y);
		}
	}
	cout << -1;
}