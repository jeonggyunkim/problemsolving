#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n;

	vector<ii> arr(n);
	vector<ii> x(n);
	vector<ii> y(n);
	int a, b, c, dd;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		arr[i] = {a, b};
		x[i] = {arr[i].first, i};
		y[i] = {arr[i].second, i};
	}
	cin >> d;

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	vector<int> cnt(n, 0);
	a = 0; b = 0; c = 0; dd = 0;
	int ans = 0;
	int two = 0;
	for (int i = 0; i < n; ++i) {
		int now = x[i].first;
		while (a < n && x[a].first < now) {
			if (cnt[x[a].second] == 2) two--;
			cnt[x[a].second]--;
			a++;
		}
		while (b < n && x[b].first <= now + d) {
			cnt[x[b].second]++;
			if (cnt[x[b].second] == 2) two++;
			b++;
		}
		while (c < n && y[c].first < now) {
			if (cnt[y[c].second] == 2) two--;
			cnt[y[c].second]--;
			c++;
		}
		while (dd < n && y[dd].first <= now + d) {
			cnt[y[dd].second]++;
			if (cnt[y[dd].second] == 2) two++;
			dd++;
		}
		ans = max(ans, two);
	}
	cout << ans;
}