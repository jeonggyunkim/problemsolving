#include <iostream>
#include <memory.h>
using namespace std;

int n, m, k;
int par, len, solind;
int num[200];
int tcnt = 1, icnt = 0;
int trie[500000][4];
int cnt[500000];
char str[1010];
int anscnt[1010];
int ansind[1010];
char ans[1010];

void dfs(int i, int d) {
	if (cnt[i] >= m) {
		anscnt[d]++;
		par++;
	}
	for (int j = 0; j < 4; ++j) {
		if (trie[i][j] != -1) dfs(trie[i][j], d + 1);
	}
}

void dfs2(int i, int d) {
	if (cnt[i] >= m && d == len) {
		ansind[icnt++] = i;
		return;
	}
	for (int j = 0; j < 4; ++j) {
		if (trie[i][j] != -1) dfs2(trie[i][j], d + 1);
	}
}

void dfs3(int i, int d) {
	if (i == solind) {
		cout << par << '\n';
		ans[d] = 0;
		cout << ans;
		exit(0);
	}
	for (int j = 0; j < 4; ++j) {
		if (trie[i][j] != -1) {
			ans[d] = "ACGT"[j];
			dfs3(trie[i][j], d + 1);
		}
	}
}
int main() {
	memset(trie, -1, sizeof(trie));

	num['A'] = 0;
	num['C'] = 1;
	num['G'] = 2;
	num['T'] = 3;

	cin >> n >> m >> k;
	cin >> str;

	for (int i = 0; i < n; ++i) {
		int now = 0;
		for (int j = i; j < n; ++j) {
			int ind = num[str[j]];
			if (trie[now][ind] == -1) {
				trie[now][ind] = tcnt++;
			}
			now = trie[now][ind];
			cnt[now]++;
		}
	}

	dfs(0, 0);
	int sum = 0, in;
	for (int i = 1; i <= n; ++i) {
		if (sum + anscnt[i] >= k) {
			len = i;
			in = k - sum - 1;
			break;
		}
		sum += anscnt[i];
	}

	dfs2(0, 0);
	solind = ansind[in];

	dfs3(0, 0);
}