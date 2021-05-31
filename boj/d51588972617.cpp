#include <iostream>
#include <map>
using namespace std;

typedef pair<int, int> ii;

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

pair<ii, ii> line[3000];
int p[3000];

int find(int i) {
	if (p[i] == i) return i;
	return p[i] = find(p[i]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		p[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) p[i] = i;

	int a, b, c, d;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c >> d;
		line[i].first = {a, b};
		line[i].second = {c, d};
		for (int j = 0; j < i; ++j) {
			if (cross(line[i].first, line[i].second, line[j].first, line[j].second)) {
				merge(i, j);
			}
		}
	}

	map<int, int> cnt;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cnt[find(i)]++;
		ans = max(ans, cnt[find(i)]);
	}
	cout << cnt.size() << '\n' << ans;
}