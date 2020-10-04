#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define N 200010
using namespace std;

bool vis[N];
string name[N];
vector<vector<int>> edge(N);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<string, int> num;
	int cnt = 1;
	num["Baba"] = 0;
	string a, b, s;
	while (n--) {
		cin >> a >> s >> b;
		if (num.count(a) == 0) {
			num[a] = cnt;
			name[cnt++] = a;
		}
		if (num.count(b) == 0) {
			num[b] = cnt;
			name[cnt++] = b;
		}
		edge[num[a]].push_back(num[b]);
	}

	vector<int> ans;
	queue<int> q;
	q.push(0);
	vis[0] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int u: edge[now]) {
			if (!vis[u]) {
				vis[u] = 1;
				ans.push_back(u);
				q.push(u);
			}
		}
	}

	vector<string> ans2;
	for (int u: ans) {
		ans2.push_back(name[u]);
	}
	sort(ans2.begin(), ans2.end());
	for (string u: ans2) {
		cout << u << '\n';
	}
}