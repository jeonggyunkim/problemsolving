#include <bits/stdc++.h>
#define INF 1987654321
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	vector<iii> dif(n);
	for (int i = 0; i < n; ++i) {
		dif[i] = iii(y[i] - x[i], x[i], y[i]);
	}
	sort(dif.begin(), dif.end());

	vector<long long> x_sum(n), y_sum(n);
	x_sum[0] = get<1>(dif[0]);
	y_sum[0] = get<2>(dif[0]);
	for (int i = 1; i < n; ++i) {
		x_sum[i] = x_sum[i - 1] + get<1>(dif[i]);
		y_sum[i] = y_sum[i - 1] + get<2>(dif[i]);
	}

	vector<long long> ans(n, 0);
	for (int i = 0; i < n; ++i) {
		auto it = upper_bound(dif.begin(), dif.end(), iii(y[i] - x[i], INF, INF));
		int index = it - dif.begin();
		ans[i] += y_sum[index - 1];
		ans[i] += (long long)index * x[i];
		if (index != n) {
			ans[i] += x_sum[n - 1] - x_sum[index - 1];
			ans[i] += ((long long)n - index) * y[i];
		}
		ans[i] -= x[i] + y[i];
	}

	int a, b;
	while (m--) {
		cin >> a >> b;
		a--; b--;
		int d = min(x[a] + y[b], y[a] + x[b]);
		ans[a] -= d;
		ans[b] -= d;
	}

	for (long long u: ans) cout << u << ' ';
}