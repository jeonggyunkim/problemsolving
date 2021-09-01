#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

int node[1000000][26];
bool fin[1000000];
int cnt;
long long ans;

void dfs(int n, int sum) {
	if (fin[n]) ans += sum;

	int cnt = 0;
	for (int i = 0; i < 26; ++i) {
		if (node[n][i] != -1) cnt++;
	}

	if (n == 0 && cnt == 1) sum++;

	for (int i = 0; i < 26; ++i) {
		if (node[n][i] != -1) {
			if (!fin[n] && cnt == 1) dfs(node[n][i], sum);
			else dfs(node[n][i], sum + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	memset(node, -1, sizeof(node));
	while (cin >> n) {
		for (int i = 0; i < cnt; ++i) {
			for (int j = 0; j < 26; ++j) node[i][j] = -1;
			fin[i] = 0;
		}
		cnt = 1;
		ans = 0;

		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			int now = 0;
			for (char u: s) {
				if (node[now][u - 'a'] == -1) {
					node[now][u - 'a'] = cnt++;
				}
				now = node[now][u - 'a'];
			}
			fin[now] = 1;
		}

		dfs(0, 0);
		cout.precision(2);
		cout << fixed;
		cout << (double)ans / n << '\n';
	}
}