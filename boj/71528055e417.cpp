#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

int nxt[200010][26];
pair<string, int> str[1000];
string ans[1000];
char best[210];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; ++i) best[i] = 0;

	for (int i = 0; i < n; ++i) {
		cin >> str[i].first;
		if (str[i].first.size() < k) {
			cout << "NO";
			return 0;
		}
		str[i].second = i;
	}
	sort(str, str + n);

	for (int i = 0; i < n; ++i) {
		for (char c = 'A'; c <= 'Z'; ++c) {
			int loc = str[i].first.size();
			for (int j = str[i].first.size() - 1; j >= 0; --j) {
				nxt[j][c - 'A'] = loc;
				if (str[i].first[j] == c) loc = j;
			}
		}

		int minstart, startindex = 0;
		if (str[i].first[0] == best[0]) {
			int now = 0, imp = k - 1;
			int impind[200] = {};
			for (int j = 1; j < k; ++j) {
				for (char c = best[j] + 1; c <= 'Z'; ++c) {
					if ((int)str[i].first.size() - nxt[now][c - 'A'] >= k - j) {
						impind[j] = nxt[now][c - 'A'];
						break;
					}
				}
				if ((int)str[i].first.size() - nxt[now][best[j] - 'A'] >= k - j) {
					now = nxt[now][best[j] - 'A'];
				}
				else {
					imp = j;
					break;
				}
			}
			int find = 0;
			for (int j = imp; j >= 1; --j) {
				if (impind[j]) {
					minstart = j;
					startindex = impind[j];
					find = 1;
					break;
				}
			}
			if (!find) {
				cout << "NO";
				return 0;
			}
		}
		else {
			minstart = 1;
			best[0] = str[i].first[0];
			for (char c = 'A'; c <= 'Z'; ++c) {
				if ((int)str[i].first.size() - nxt[startindex][c - 'A'] >= k - 1) {
					startindex = nxt[startindex][c - 'A'];
					break;
				}
			}
		}

		for (int j = minstart; j < k; ++j) {
			best[j] = str[i].first[startindex];
			for (char c = 'A'; c <= 'Z'; ++c) {
				if ((int)str[i].first.size() - nxt[startindex][c - 'A'] >= k - j - 1) {
					startindex = nxt[startindex][c - 'A'];
					break;
				}
			}
		}
		best[k] = 0;

		ans[str[i].second] = best;
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
}