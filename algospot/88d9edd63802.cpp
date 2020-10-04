#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int n;
string str[15];
int com[15][15];
ii dp[15][1 << 15];

int find_com(int a, int b) {
	int& ret = com[a][b];
	if (ret != -1) return ret;
	int la = str[a].length(), lb = str[b].length();
	for (int i = la; i > 0; --i) {
		int j = min(i, lb);
		if (str[a].substr(la - i, j).compare(str[b].substr(0, j)) == 0) return ret = j;
	}
	return ret = 0;
}

ii cal(int start, int mask) {
	if (dp[start][mask].first > 0) return dp[start][mask];
	mask |= (1 << start);
	if (mask == (1 << n) - 1) return ii(str[start].length(), -1);
	ii ret = ii(1 << 30, -1);
	for (int i = 0; i < n; ++i) {
		if ((mask & (1 << i)) == 0) {
			int t = str[start].length() + cal(i, mask).first - com[start][i];
			if (ret.first > t) {
				ret.first = t;
				ret.second = i;
			}
		}
	}
	return dp[start][mask] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(com, -1, sizeof(com));
		memset(dp, 0, sizeof(dp));

		cin >> n;
		for (int i = 0; i < n; ++i) cin >> str[i];

		int mask = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			if (i != j && !((1 << i) & mask) && !((1 << j) & mask)) {
				com[i][j] = find_com(i, j);
				if (com[i][j] == str[i].length()) mask |= (1 << i);
				else if (com[i][j] == str[j].length()) mask |= (1 << j);
			}
		}

		int ans = 1 << 30, mini;
		for (int i = 0; i < n; ++i) {
			ii t = cal(i, mask);
			if (t.first < ans) {
				ans = t.first;
				mini = i;
			}
		}

		while (mini != -1) {
			ii t = cal(mini, mask);
			if (t.second != -1) cout << str[mini].substr(0, str[mini].length() - com[mini][t.second]);
			else cout << str[mini] << '\n';
			mask |= (1 << mini);
			mini = t.second;
		}
	}
}
