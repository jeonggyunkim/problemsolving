#include <bits/stdc++.h>
using namespace std;

int len[301], ind[301];

bool comp(int a, int b, int k) {
	for (int i = 0; i < k; ++i) if (ind[a + i] != ind[b + i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;

	unordered_map<string, int> hm;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		len[i] = len[i - 1] + s.size();
		if (hm.find(s) == hm.end()) {
			hm[s] = i;
			ind[i] = i;
		}
		else ind[i] = hm[s];
	}

	int ans = 0;
	for (int a = 1; a <= n - 1; ++a) {
		for (int k = 1; a + 2 * k <= n + 1; ++k) {
			int b = a + k, cnt = 1;
			int r = len[a + k - 1] - len[a - 1] - 1;
			while (b <= n - k + 1) {
				if (comp(a, b, k)) {
					b += k;
					cnt++;
				}
				else b++;
			}
			if (cnt >= 2) ans = max(ans, r * cnt);
		}
	}
	cout << len[n] + n - 1 - ans;
}