#include <bits/stdc++.h>
using namespace std;

set<int> card;
int exist;
int ans = 10;

void query(int mask) {
	int input = mask;
	int now = exist ^ (mask & exist);
	int a = now & 31;
	int b = now & (31 << 5);
	if ((a & (a - 1)) == 0) mask ^= a;
	if ((b & (b - 1)) == 0) mask ^= b;

	set<int> s = card;
	for (int i = 0; i < 5; ++i) {
		if (!(mask & (1 << i))) continue;
		for (int j = 5; j < 10; ++j) {
			if (!(mask & (1 << j))) continue;
			s.erase((1 << i) | (1 << j));
		}
	}
	while (!s.empty()) {
		bool del = 0;
		int cnt[10] = {};
		for (int u: s) {
			for (int i = 0; i < 10; ++i) {
				if (u & (1 << i)) cnt[i]++;
			}
		}
		for (int i = 0; i < 10; ++i) {
			if (cnt[i] == 1) {
				if (mask & (1 << i)) {
					for (int u: s) {
						if (u & (1 << i)) {
							s.erase(u);
							del = 1;
							break;
						}
					}
				}
			}
		}
		if (!del) break;
	}
	if (s.empty() || s.size() == 1) {
		ans = min(ans, __builtin_popcount(input));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<char, int> color = {{'R', 0}, {'G', 1}, {'B', 2}, {'Y', 3}, {'W', 4}};
	string s;
	while (n--) {
		cin >> s;
		int now = (1 << color[s[0]]) | (1 << (s[1] - '1' + 5));
		card.insert(now);
		exist |= now;
	}

	for (int i = 0; i < (1 << 10); ++i) {
		query(i);
	}
	cout << ans;
}