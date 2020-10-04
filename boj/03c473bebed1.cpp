#include <iostream>
#include <vector>
#include <map>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x0, a, b, q;
	cin >> n >> x0 >> a >> b >> q;
	long long x, ans = 0;

	vector<int> arr(q), lb(q, -1), ub(q, MOD);
	for (int i = 0; i < q; ++i) cin >> arr[i];

	while (true) {
		map<int, int> cnt;
		for (int i = 0; i < q; ++i) {
			if (ub[i] - lb[i] != 1) cnt[(lb[i] + ub[i]) / 2] = 0;
		}
		if (cnt.size() == 0) break;
		cnt[MOD] = 0;

		x = x0;
		for (int i = 0; i < n; ++i) {
			(cnt.upper_bound(x)->second)++;
			x = (x * a + b) % MOD;
		}

		auto it = cnt.begin(), jt = it;
		jt++;
		while (true) {
			if (jt == cnt.end()) break;
			jt->second += it->second;
			it++; jt++;
		}

		for (int i = 0; i < q; ++i) {
			if (ub[i] - lb[i] != 1) {
				int mid = (lb[i] + ub[i]) / 2;
				if (cnt[mid] > arr[i]) ub[i] = mid;
				else lb[i] = mid;
			}
		}
	}

	for (int i = 0; i < q; ++i) ans += lb[i];
	cout << ans;
}