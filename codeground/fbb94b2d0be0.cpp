#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

long long cal(int p, int base) {
	long long ret = 1;
	while (p--) {
		ret *= base;
		ret += 1;
	}
	return ret;
}

int pos(int n, int p) {
	int low = 1, high = (int)pow(n, 1.0 / p) + 1, mid;
	if (n <= p) return -1;
	while (high - low > 1) {
		mid = (low + high) / 2;
		long long t = cal(p, mid);
		if (t == n) return mid;
		else if (t > n) high = mid;
		else low = mid;
	}
	return -1;
}

vector<int> divi(int n) {
	vector<ii> temp;
	vector<int> ret = { 1 };
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			temp.push_back(ii(i, 0));
			while (n % i == 0) {
				temp.back().second++;
				n /= i;
			}
		}
	}
	if (n != 1) temp.push_back(ii(n, 1));

	for (ii u : temp) {
		int t = ret.size();
		int k = u.first;
		for (int i = 0; i < u.second; ++i) {
			for (int j = 0; j < t; ++j) ret.push_back(ret[j] * k);
			k *= u.first;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;

		int ans = n + 1;
		vector<int> todo = divi(n);
		for (int a : todo) {
			int b = n / a;
			int m = 0;
			int bb = 1;
			while (bb <= b) {
				bb *= a + 1;
				bb += 1;
				m++;
			}
			for (int i = 1; i < m; ++i) {
				int t = pos(b, i);
				if (t != -1) ans = min(t, ans);
			}
		}
		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}