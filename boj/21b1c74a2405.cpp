#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int depth[250];
ii boot[250];
bool vis[250][251];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, b;
	cin >> n >> b;

	for (int i = 0; i < n; ++i) {
		cin >> depth[i];
	}
	for (int i = 0; i < b; ++i) {
		cin >> boot[i].first >> boot[i].second;
	}

	queue<ii> q;
	q.push({0, 0});
	vis[0][0] = 1;

	while (!q.empty()) {
		ii now = q.front(); q.pop();
		int loc = now.first;
		int top = now.second;

		if (top == b) continue;

		if (!vis[loc][top + 1]) {
			vis[loc][top + 1] = 1;
			q.push({loc, top + 1});
		}

		if (boot[top].first >= depth[loc]) {
			int last = loc;
			for (int i = loc + 1; i < n; ++i) {
				if (boot[top].first >= depth[i] && i - last <= boot[top].second) {
					if (!vis[i][top + 1]) {
						vis[i][top + 1] = 1;
						q.push({i, top + 1});
					}
					last = i;
				}
			}
		}
	}

	for (int i = 0; i <= b; ++i) {
		if (vis[n - 1][i]) {
			cout << i - 1;
			return 0;
		}
	}
}