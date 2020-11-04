#include <iostream>
#include <queue>
using namespace std;

char what[] = "BLD";

typedef pair<int, int> ii;

bool vis[1501][1501];

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	queue<ii> q;
	vis[0][3 * n] = 1;
	q.push({0, 3 * n});
	int ans = 0;

	while (!q.empty()) {
		ii now = q.front(); q.pop();
		int eat = 3 * n - (now.second - now.first);

		ans = max(ans, eat);
		if (now.first == now.second) continue;
		if (s[now.first] == what[eat % 3]) {
			if (!vis[now.first + 1][now.second]) {
				vis[now.first + 1][now.second] = 1;
				q.push({now.first + 1, now.second});
			}
		}
		if (s[now.second - 1] == what[eat % 3]) {
			if (!vis[now.first][now.second - 1]) {
				vis[now.first][now.second - 1] = 1;
				q.push({now.first, now.second - 1});
			}
		}
	}
	cout << ans;
}