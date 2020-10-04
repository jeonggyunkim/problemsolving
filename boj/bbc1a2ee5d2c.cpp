#include <iostream>
#include <vector>
#include <queue>
#define index(a) (a <= 'Z' ? a - 'A' : a - 'a' + 26)
#define INF 987654321
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int capacity[52][52] = {}, flow[52][52] = {};
	char a, b;
	int c;
	while (n--) {
		cin >> a >> b >> c;
		capacity[index(a)][index(b)] += c;
		capacity[index(b)][index(a)] += c;
	}

	int totalFlow = 0;
	while (true) {
		vector<int> p(52, -1);
		queue<int> q;
		p[0] = 0;
		q.push(0);

		while (!q.empty() && p[index('Z')] == -1) {
			int now = q.front(); q.pop();
			for (int i = 0; i < 52; ++i) {
				if (p[i] == -1 && capacity[now][i] - flow[now][i] > 0) {
					q.push(i);
					p[i] = now;
				}
			}
		}

		if (p[index('Z')] == -1) break;

		int amount = INF;
		for (int i = index('Z'); i != 0; i = p[i]) {
			amount = min(amount, capacity[p[i]][i] - flow[p[i]][i]);
		}

		for (int i = index('Z'); i != 0; i = p[i]) {
			flow[p[i]][i] += amount;
			flow[i][p[i]] -= amount;
		}
		totalFlow += amount;
	}

	cout << totalFlow << '\n';
}