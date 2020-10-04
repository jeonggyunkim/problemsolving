#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector<vector<int>> edge;
vector<int> vis, sccId;
stack<int> s;
int vCounter, sCounter;

int dfs(int n) {
	int ret = vis[n] = vCounter++;
	s.push(n);

	for (int u: edge[n]) {
		if (vis[u] == -1) {
			int r = dfs(u);
			ret = min(ret, r);
		}
		else if (vis[u] < vis[n] && sccId[u] == -1) ret = min(ret, vis[u]);
	}

	if (ret == vis[n]) {
		while (1) {
			int t = s.top(); s.pop();
			sccId[t] = sCounter;
			if (t == n) break;
		}
		sCounter++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m, n || m) {
		n--;
		edge.clear();
		vis.clear();
		sccId.clear();
		vCounter = sCounter = 0;

		edge.resize(2 * n + 1);
		vis.resize(2 * n + 1, -1);
		sccId.resize(2 * n + 1, -1);

		string a, b;
		int aa, bb;
		while (m--) {
			cin >> a >> b;
			if (a > b) swap(a, b);

			aa = atoi(a.substr(0, a.size() - 1).c_str());
			bb = atoi(b.substr(0, b.size() - 1).c_str());

			if (aa == 0) {
				if (a.back() == 'h') {
					if (b.back() == 'h') {
						edge[bb + n].push_back(-bb + n);
					}
					else {
						edge[-bb + n].push_back(bb + n);
					}
				}
			}
			else {
				if (a.back() == 'h') aa = -aa;
				if (b.back() == 'h') bb = -bb;
				edge[-aa + n].push_back(bb + n);
				edge[-bb + n].push_back(aa + n);
			}
		}

		for (int i = 0; i <= 2 * n; ++i) {
			if (i != n && vis[i] == -1) {
				dfs(i);
			}
		}

		string ans;
		bool brk = 0;
		for (int i = 1; i <= n; ++i) {
			if (sccId[i + n] == sccId[-i + n]) {
				cout << "bad luck\n";
				brk = 1;
				break;
			}
			else {
				ans += to_string(i);
				if (sccId[i + n] > sccId[-i + n]) ans += "h ";
				else ans += "w ";
			}
		}
		if (!brk) cout << ans << '\n';
	}
}