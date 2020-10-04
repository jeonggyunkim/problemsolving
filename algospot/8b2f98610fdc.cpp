#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> route;

void dfs(int n, vector<vector<int>>& edge, vector<string>& word, vector<bool>& used) {
	for (int i: edge[n]) {
		if (!used[i]) {
			used[i] = 1;
			dfs(word[i].back() - 'a', edge, word, used);
			route.push_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		vector<bool> used(n, 0);
		vector<string> word;
		vector<vector<int>> edge(26);
		route.clear();

		vector<int> cnt(26);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			word.push_back(s);
			edge[s.front() - 'a'].push_back(i);
			cnt[s.front() - 'a']--;
			cnt[s.back() - 'a']++;
		}

		int start = word[0].front() - 'a';

		bool imp = false, neg = false;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] != 0) {
				if (cnt[i] == -1) {
					if (neg == false) {
						start = i;
						neg = true;
					}
					else imp = true;
				}
				else if (cnt[i] != 1) imp = true;
			}
		}

		if (imp) cout << "IMPOSSIBLE\n";
		else {
			dfs(start, edge, word, used);
			for (int i = route.size() - 1; i >= 0; --i) cout << word[route[i]] << ' ';
			cout << '\n';
		}
	}
}
