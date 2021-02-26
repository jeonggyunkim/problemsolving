#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>
#define INF 1e10
#define SQ(n) ((n) * (n))
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, int> di;
typedef tuple<int, int, int> i3;

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
	return d1 < 0 && d2 < 0;
}

ii line[100];
double dist[101][101];
double ans[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	scanf("%d %d\n", &n, &m);

	vector<i3> person;
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("(%d,%d) %d\n", &a, &b, &c);
		person.push_back({a, b, c});
	}
	for (int i = 0; i < m; ++i) {
		scanf("(%d,%d) - (%d,%d)\n", &line[2 * i].first, &line[2 * i].second, &line[2 * i + 1].first, &line[2 * i + 1].second);
	}
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) dist[i][j] = INF;
		ans[i] = INF;
	}

	for (int i = 0; i < 2 * m; ++i) {
		dist[i][i] = 0;
		for (int j = i + 1; j < 2 * m; ++j) {
			bool intersect = 0;
			for (int k = 0; k < m; ++k) {
				if (cross(line[i], line[j], line[2 * k], line[2 * k + 1])) {
					intersect = 1;
					break;
				}
			}
			if (!intersect) {
				double t = sqrt(SQ(line[i].first - line[j].first) + SQ(line[i].second - line[j].second));
				dist[i][j] = t;
				dist[j][i] = t;
			}
		}

		bool intersect = 0;
		for (int k = 0; k < m; ++k) {
			if (cross(line[i], {line[i].first, 0}, line[2 * k], line[2 * k + 1])) {
				intersect = 1;
				break;
			}
		}
		if (!intersect) {
			dist[i][100] = line[i].second;
			dist[100][i] = line[i].second;
		}
	}
	dist[100][100] = 0;

	priority_queue<di, vector<di>, greater<di>> pq;
	pq.push({0, 100});
	ans[100] = 0;
	while (!pq.empty()) {
		di now = pq.top(); pq.pop();
		if (now.first > ans[now.second]) continue;
		for (int i = 0; i <= 100; ++i) {
			if (now.first + dist[now.second][i] < ans[i]) {
				ans[i] = now.first + dist[now.second][i];
				pq.push({ans[i], i});
			}
		}
	}

	double maxt = 0;
	for (int i = 0; i < n; ++i) {
		double nowmin = INF;
		for (int j = 0; j < 2 * m; ++j) {
			bool intersect = 0;
			for (int k = 0; k < m; ++k) {
				if (cross({get<0>(person[i]), get<1>(person[i])}, line[j], line[2 * k], line[2 * k + 1])) {
					intersect = 1;
					break;
				}
			}
			if (!intersect) {
				nowmin = min(nowmin, ans[j] + sqrt(SQ(get<0>(person[i]) - line[j].first) + SQ(get<1>(person[i]) - line[j].second)));
			}
		}

		bool intersect = 0;
		for (int k = 0; k < m; ++k) {
			if (cross({get<0>(person[i]), get<1>(person[i])}, {get<0>(person[i]), 0}, line[2 * k], line[2 * k + 1])) {
				intersect = 1;
				break;
			}
		}
		if (!intersect) {
			nowmin = get<1>(person[i]);
		}
		maxt = max(maxt, nowmin / get<2>(person[i]));
	}
	cout.precision(1);
	cout << fixed;
	cout << maxt;
}