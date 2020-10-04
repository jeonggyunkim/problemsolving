#include <bits/stdc++.h>
using namespace std;

vector<int> pi;

void getpi(string& N) {
	int m = N.size();
	pi.resize(m, 0);

	int begin = 1, match = 0;
	while (begin + match < m) {
		if (N[begin + match] == N[match]) {
			++match;
			pi[begin + match - 1] = match;
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	string H, N;
	cin >> H >> N;

	getpi(N);

	vector<int> ans(n, 0);

	int begin = 0, match = 0;
	while (begin <= n - m) {
		if (match < m && H[begin + match] == N[match]) {
			++match;
			if (match == m) ans[begin] = 1;
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}

	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + ans[i - 1];

	int a, b;
	while (q--) {
		cin >> a >> b;
		b -= m - 1;
		if (a <= b) {
			cout << sum[b] - sum[a - 1] << '\n';
		}
		else cout << "0\n";
	}
}