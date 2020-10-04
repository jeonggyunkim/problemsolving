#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int maxv;

vector<int> find_divi(int n) {
	vector<int> ret;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			if (i / 2 <= maxv && (n / i) / 2 <= maxv && (i +  n / i - 2) >= maxv) ret.push_back(i);
		}
	}
	return ret;
}

int insq(int x, int m, int n) {
	int ret = min(min(m, n), min(x - 1, m + n - x + 1));
	if (ret < 0) return 0;
	else return ret;
}

bool is_ans(map<int, int>& input, int n, int m, int x, int y) {
	int a = x, b = n - x - 1, c = y, d = m - y - 1;
	for (int i = maxv; i >= 1; --i) {
		int cnt = 0;
		if (i <= a) cnt++;
		if (i <= b) cnt++;
		if (i <= c) cnt++;
		if (i <= d) cnt++;
		cnt += insq(i, a, c);
		cnt += insq(i, a, d);
		cnt += insq(i, b, c);
		cnt += insq(i, b, d);
		if (cnt != input[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<int, int> m;
	int n, t;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		m[t]++;
	}

	auto it = m.end(); it--;
	maxv = it->first;
	if (maxv + 1 != m.size()) {
		cout << -1;
		return 0;
	}

	vector<int> divi = find_divi(n);
	if (divi.empty()) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < divi.size(); ++i) {
		vector<ii> pos;
		int x = divi[i], y = n / divi[i];
		for (int j = x / 2; j < x; ++j) {
			int k = maxv - j;
			if (k >= y / 2 && k < y) pos.push_back(ii(j, k));
		}
		for (ii u: pos) {
			if (is_ans(m, x, y, u.first, u.second)) {
				cout << x << ' ' << y << '\n';
				cout << u.first + 1 << ' ' << u.second + 1 << '\n';
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}