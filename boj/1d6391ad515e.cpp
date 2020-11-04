#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int cnt[10008];
vector<bool> prime(10008, 1);

vector<ii> facdiv(int n) {
	vector<ii> ret;
	for (int i = 2; i <= n; ++i) {
		if (prime[i]) {
			ret.push_back({i, 0});
			for (int j = i; j <= n; j *= i) {
				ret.back().second += n / j;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= 10007; ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= 10007; j += i) prime[j] = 0;
		}
	}

	int n, m, t;
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		cin >> t;
		vector<ii> now = facdiv(t);
		for (ii u: now) cnt[u.first] += u.second;
	}
	for (int i = 0; i < m; ++i) {
		cin >> t;
		vector<ii> now = facdiv(t);
		for (ii u: now) cnt[u.first] -= u.second;
	}
	for (int i = 0; i <= 10007; ++i) {
		if (cnt[i] < 0) {
			cout << -1;
			return 0;
		}
	}

	vector<ii> ans;
	while (1) {
		if (cnt[2] <= 0) break;
		int low = 2, high = 10007;
		while (high - low != 1) {
			int mid = (low + high) / 2;
			vector<ii> now = facdiv(mid);

			int pos = 1;
			for (ii u: now) {
				if (cnt[u.first] < u.second) {
					pos = 0;
					break;
				}
			}
			if (pos) low = mid;
			else high = mid;
		}
		vector<ii> now = facdiv(low);
		int dec = INF;
		for (ii u: now) dec = min(dec, cnt[u.first] / u.second);
		for (ii u: now) cnt[u.first] -= dec * u.second;
		ans.push_back({low, dec});
	}
	cout << ans.size() << '\n';
	for (ii u: ans) cout << u.first << ' ' << u.second << '\n';
}