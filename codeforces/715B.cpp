#include <bits/stdc++.h>
#define INF (1LL << 60)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;

vector<vector<ii>> edge;
vector<ii> toPrint;
int n, s, t;

void print() {
	cout << "YES\n";
	for (int i = 0; i < toPrint.size(); ++i) {
		cout << toPrint[i].first << ' ';
		cout << edge[toPrint[i].first][toPrint[i].second].first << ' ';
		cout << edge[toPrint[i].first][toPrint[i].second].second << ' ';
		cout << '\n';
	}
}


ll dij() {
	vector<ll> dist(n, INF);
	dist[s] = 0;
	priority_queue<li, vector<li>, greater<li>> pq;
	pq.push(li(0, s));
	while (!pq.empty()) {
		li now = pq.top(); pq.pop();
		ll d = now.first, u = now.second;
		if (d > dist[u]) continue;
		for (ii e: edge[u]) {
			if (dist[u] + e.second < dist[e.first]) {
				dist[e.first] = dist[u] + e.second;
				pq.push(ii(dist[e.first], e.first));
			}
		}
	}
	return dist[t];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, l;
	cin >> n >> m >> l >> s >> t;
	edge.resize(n);

	bool er = 0;
	vector<ii> erased;
	int a, b, w;
	while (m--) {
		cin >> a >> b >> w;
		if (w == 0) {
			edge[a].push_back(ii(b, 1));
			edge[b].push_back(ii(a, 1));
		}
		else {
			edge[a].push_back(ii(b, w));
			edge[b].push_back(ii(a, w));
		}
		if (w == 0) {
			erased.push_back(ii(a, edge[a].size() - 1));
			erased.push_back(ii(b, edge[b].size() - 1));
			er = 1;
		}
		toPrint.push_back(ii(a, edge[a].size() - 1));
	}

	if (!er) {
		if (dij() != l)	cout << "NO";
		else print();
		return 0;
	}

	ll ft = dij();
	if (ft > l) {
		cout << "NO";
		return 0;
	}

	int low = 1, high = 1e9 + 1;
	for (int i = 0; i < erased.size(); ++i) {
		edge[erased[i].first][erased[i].second].second = high;
	}
	ft = dij();
	if (ft < l) {
		cout << "NO";
		return 0;
	}

	while (high - low > 1) {
		int mid = (low + high) / 2;
		for (int i = 0; i < erased.size(); ++i) {
			edge[erased[i].first][erased[i].second].second = mid;
		}
		ll now = dij();
		if (now == l) {
			print();
			return 0;
		}
		else if (now < l) low = mid;
		else high = mid;
	}

	int low2 = 0, high2 = erased.size() / 2;
	for (int i = low2 * 2; i < high2 * 2; ++i) {
		edge[erased[i].first][erased[i].second].second = low;
	}
	while (high2 - low2 > 1) {
		int mid = (low2 + high2) / 2;
		for (int i = 2 * low2; i < 2 * mid; ++i) {
			edge[erased[i].first][erased[i].second].second = high;
		}
		ll now = dij();
		if (now == l) {
			print();
			return 0;
		}
		else if (now < l) {
			low2 = mid;
		}
		else {
			high2 = mid;
			for (int i = 2 * low2; i < 2 * mid; ++i) {
				edge[erased[i].first][erased[i].second].second = low;
			}
		}
	}
	print();
}
