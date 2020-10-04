#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> name(1);
vector<vector<int>> child(1);
int cnt = 1;

bool comp(int i, int j) {
	return name[i] < name[j];
}

void dfs(int i, int d) {
	if (d != 0) {
		for (int j = 1; j < d; ++j) cout << "--";
		cout << name[i] << '\n';
	}
	for (int u: child[i]) {
		dfs(u, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	string s;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		int now = 0;
		for (int j = 0; j < t; ++j) {
			cin >> s;
			bool find = 0;
			for (int u: child[now]) {
				if (name[u] == s) {
					find = 1;
					now = u;
					break;
				}
			}
			if (!find) {
				child[now].push_back(cnt);
				name.push_back(s);
				child.push_back(vector<int>());
				now = cnt;
				cnt++;
			}
		}
	}

	for (int i = 0; i < cnt; ++i) sort(child[i].begin(), child[i].end(), comp);

	dfs(0, 0);
}