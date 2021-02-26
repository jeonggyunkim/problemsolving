#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool pos;

void dfs(vector<vector<int>>& edge, vector<int>& team, int i, int color) {
	if (team[i] == -1) {
		team[i] = color;
	}
	for (int u: edge[i]) {
		if (team[u] == -1) {
			dfs(edge, team, u, 1 - color);
		}
		else if (team[u] == team[i]) {
			pos = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;

		int cnt = 0;
		unordered_map<string, int> mp;
		vector<vector<int>> edge;

		string a, b;
		while (n--) {
			cin >> a >> b;
			if (!mp.count(a)) {
				mp[a] = cnt++;
				edge.push_back(vector<int>());
			}
			if (!mp.count(b)) {
				mp[b] = cnt++;
				edge.push_back(vector<int>());
			}
			edge[mp[a]].push_back(mp[b]);
			edge[mp[b]].push_back(mp[a]);
		}

		pos = 1;
		vector<int> team(edge.size(), -1);
		for (int i = 0; i < edge.size(); ++i) {
			if (team[i] == -1) {
				dfs(edge, team, i, 0);
			}
		}
		cout << "Case #" << test << ": ";
		if (pos) cout << "Yes\n";
		else cout << "No\n";
	}
}