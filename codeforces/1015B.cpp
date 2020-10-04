#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s, t;
	cin >> n >> s >> t;

	int cnt[26] = {};
	for (int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
		cnt[t[i] - 'a']--;
	}

	for (int i = 0; i < 26; ++i) if (cnt[i] != 0) {
		cout << -1;
		return 0;
	}

	vector<int> move;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (t[i] == s[j]) {
				for (int k = j - 1; k >= i; --k) {
					move.push_back(k + 1);
					swap(s[k], s[k + 1]);
				}
				break;
			}
		}
	}
	cout << move.size() << '\n';
	for (int u: move) cout << u << ' ';
}