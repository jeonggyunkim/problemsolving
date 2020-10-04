#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int trie[1600000][36];
int value[1600000];
int cnt = 1;
int point[10] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

string word[300000];
bool found[300000];
char board[4][5];
bool vis[4][4];

int ans, maxs, ind, acnt;

void dfs(int i, int j, int d, int node) {
	if (!trie[node][board[i][j] - 'A']) return;
	node = trie[node][board[i][j] - 'A'];

	if (value[node] != -1 && !found[value[node]]) {
		found[value[node]] = 1;
		ans += point[d];
		if (d > maxs) {
			maxs = d;
			ind = value[node];
		}
		else if (d == maxs && word[ind] > word[value[node]]) {
			ind = value[node];
		}
		acnt++;
	}
	vis[i][j] = 1;
	for (int x = -1; x <= 1; ++x) {
		for (int y = -1; y <= 1; ++y) {
			if (!x && !y) continue;
			int xx = i + x;
			int yy = j + y;
			if (xx < 0 || xx >= 4 || yy < 0 || yy >= 4 || vis[xx][yy]) continue;
			dfs(xx, yy, d + 1, node);
		}
	}
	vis[i][j] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(value, -1, sizeof(value));

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> word[i];
		int now = 0;
		for (int j = 0; j < word[i].size(); ++j) {
			if (!trie[now][word[i][j] - 'A']) {
				trie[now][word[i][j] - 'A'] = cnt++;
			}
			now = trie[now][word[i][j] - 'A'];
		}
		value[now] = i;
	}

	cin >> n;

	while (n--) {
		memset(found, 0, sizeof(found));
		ans = maxs = ind = acnt = 0;
		for (int i = 0; i < 4; ++i) cin >> board[i];
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				dfs(i, j, 1, 0);
			}
		}
		cout << ans << ' ' << word[ind] << ' ' << acnt << '\n';
	}
}