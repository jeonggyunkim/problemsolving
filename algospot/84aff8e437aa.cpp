#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int rev(int n, int l, int s, int f) {
	vector<int> digit(l);
	for (int i = 0; i < l; ++i) {
		digit[l - 1 - i] = n % 10;
		n /= 10;
	}
	reverse(digit.begin() + s, digit.begin() + f);

	int ret = 0;
	for (int i = 0; i < l; ++i) {
		ret *= 10;
		ret += digit[i];
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<int, int> m;
	for (int len = 1; len <= 8; ++len) {
		int a = 0;
		for (int i = 1; i <= len; ++i) {
			a *= 10;
			a += i;
		}

		m[a] = 0;

		queue<int> q;
		q.push(a);

		while (!q.empty()) {
			int here = q.front(); q.pop();
			int d = m[here];
			for (int i = 0; i < len; ++i) {
				for (int j = i + 2; j <= len; ++j) {
					int r = rev(here, len, i, j);
					if (m.count(r) == 0) {
						m[r] = d + 1;
						q.push(r);
					}
				}
			}
		}
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		vector<ii> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first;
			a[i].second = i + 1;
		}

		sort(a.begin(), a.end());

		int re = 0;
		for (int i = 0; i < n; ++i) {
			re *= 10;
			re += a[i].second;
		}

		cout << m[re] << '\n';
	}
}
