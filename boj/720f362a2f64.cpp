#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;

int y_sum[1000001];

iii dot[300000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> dot[i].first.first >> dot[i].first.second >> dot[i].second;
	}

	for (int i = 0; i < n; ++i) y_sum[dot[i].first.second] += dot[i].second;

	priority_queue<ii> pq;
	for (int i = 0; i <= 1000000; ++i) {
		if (y_sum[i]) {
			pq.push({y_sum[i], i});
		}
	}

	sort(dot, dot + n);
	int ans = 0, sum = 0;
	for (int rep = 0; rep < 2; ++rep) {
		vector<ii> get;
		for (int i = 0; i < 3; ++i) {
			if (!pq.empty()) {
				sum += pq.top().first;
				get.push_back(pq.top());
				pq.pop();
			}
		}
		for (ii u: get) pq.push(u);
		ans = max(ans, sum);
		sum = 0;

		for (int i = 0; i < n; ++i) {
			y_sum[dot[i].first.second] -= dot[i].second;
			pq.push({y_sum[dot[i].first.second], dot[i].first.second});
			sum += dot[i].second;
			if (i == n - 1 || dot[i].first.first != dot[i + 1].first.first) {
				// last
				// search queue
				int cnt = 0, prev = -1;
				ii a = {-1, -1}, b = {-1, -1};
				while (!pq.empty()) {
					ii now = pq.top(); pq.pop();
					if (y_sum[now.second] != now.first) continue;
					if (now.second == prev) continue;

					sum += now.first;
					cnt++;
					prev = now.second;
					b = a;
					a = now;
					if (cnt == 2) {
						break;
					}
				}
				ans = max(ans, sum);
				if (a.first != -1) pq.push(a);
				if (b.first != -1) pq.push(b);

				for (int j = i; j >= 0; --j) {
					if (dot[j].first.first == dot[i].first.first) {
						y_sum[dot[j].first.second] += dot[j].second;
						pq.push({y_sum[dot[j].first.second], dot[j].first.second});
					}
					else break;
				}
				sum = 0;
			}
		}
		if (rep == 0) {
			for (int i = 0; i < n; ++i) swap(dot[i].first.first, dot[i].first.second);

			memset(y_sum, 0, sizeof(y_sum));
			for (int i = 0; i < n; ++i) y_sum[dot[i].first.second] += dot[i].second;

			pq = priority_queue<ii>();
			for (int i = 0; i <= 1000000; ++i) {
				if (y_sum[i]) {
					pq.push({y_sum[i], i});
				}
			}
			sort(dot, dot + n);
		}
	}
	cout << ans;
}