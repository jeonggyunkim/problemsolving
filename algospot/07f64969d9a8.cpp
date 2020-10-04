#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

bool cyc = false;
int visited[26];
vector<char> order;

void dfs(int n, vector<vector<int>>& alp) {
	visited[n] = 1;
	for (int i: alp[n]) {
		if (visited[i] == 1) {
			cyc = true;
			break;
		}
		else if (visited[i] == 0) dfs(i, alp);
	}
	visited[n] = 2;
	order.push_back(n + 'a');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		vector<vector<int>> alp(26);
		memset(visited, 0, sizeof(visited));
		order.clear();
		cyc = false;

		string d1, d2;
		cin >> d2;

		for (int i = 1; i < n; ++i) {
			d1 = d2;
			cin >> d2;
			int j = 0;
			while (d1[j] && d2[j]) {
				if (d1[j] == d2[j]) j++;
				else {
					alp[d2[j] - 'a'].push_back(d1[j] - 'a');
					break;
				}
			}
		}

		for (int i = 0; i < 26; ++i) {
			if (visited[i] == 0) dfs(i, alp);
		}

		if (cyc) cout << "INVALID HYPOTHESIS";
		else for (int i = 0; i < 26; ++i) cout << order[i];
		cout << '\n';
	}
}
