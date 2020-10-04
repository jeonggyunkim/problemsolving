#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> to_print;

int phi(int n) {
	vector<int> div;
	int nn = n;
	int ret = n;
	if (n % 2 == 0) {
		while (n % 2 == 0) n /= 2;
		ret /= 2;
		div.push_back(2);
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			ret -= ret / i;
			div.push_back(i);
		}
	}
	if (n != 1) {
		ret -= ret / n;
		div.push_back(n);
	}

	vector<bool> mask(nn + 1, 1);
	for (int u: div) {
		for (int j = u; j <= nn; j += u) mask[j] = 0;
	}
	for (int i = 2; i <= nn; ++i) {
		if (mask[i]) to_print.push_back(ii(nn, i));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (m < n - 1) {
		cout << "Impossible\n";
		return 0;
	}

	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		ans += phi(i);
		if (ans >= m) {
			cout << "Possible\n";
			break;
		}
	}
	if (ans < m) {
		cout << "Impossible\n";
		return 0;
	}

	for (int i = 2; i <= n; ++i) cout << 1 << ' ' << i << '\n';

	for (int i = 0; i < m - n + 1; ++i) {
		cout << to_print[i].first << ' ' << to_print[i].second << '\n';
	}
}