#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

vector<vector<int>> edge;
vector<ii> dfs_index;
int counter = 0;

void dfs(int i) {
	dfs_index[i].first = counter++;
	for (int u : edge[i]) dfs(u);
	dfs_index[i].second = counter;
}

long long stree[(1 << 18) + 10];

long long get(int n, int li, int ri, int i) {
	if (li == ri) return stree[i];
	int mid = (li + ri) / 2;
	long long ret = stree[i];
	if (n <= mid) ret += get(n, li, mid, 2 * i + 1);
	else ret += get(n, mid + 1, ri, 2 * i + 2);
	return ret;
}

void set(int l, int r, int d, int li, int ri, int i) {
	if (l == li && r == ri) {
		stree[i] += d;
		return;
	}
	int mid = (li + ri) / 2;
	if (r <= mid) {
		set(l, r, d, li, mid, 2 * i + 1);
		return;
	}
	if (l >= mid + 1) {
		set(l, r, d, mid + 1, ri, 2 * i + 2);
		return;
	}

	set(l, mid, d, li, mid, 2 * i + 1);
	set(mid + 1, r, d, mid + 1, ri, 2 * i + 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	long long j;
	cin >> n >> k >> j;

	edge.resize(n);
	int t;
	for (int i = 1; i < n; ++i) {
		cin >> t;
		edge[t - 1].push_back(i);
	}

	dfs_index.resize(n);
	dfs(0);

	vector<int> node_color(n);
	for (int i = 0; i < n; ++i) {
		cin >> node_color[i];
		node_color[i]--;
	}

	vector<iii> query(k);
	int ta, tb, tc;
	for (int i = 0; i < k; ++i) {
		cin >> ta >> tb >> tc;
		query[i] = make_tuple(ta, tb - 1, tc);
	}
	sort(query.begin(), query.end());

	vector<vector<int>> color(n);
	vector<int> low(n, -1), high(n, -1);
	for (int i = 0; i < n; ++i) {
		color[node_color[i]].push_back(dfs_index[i].first);
		low[node_color[i]] = 0;
		high[node_color[i]] = get<0>(query.back()) + 1;
	}

	for (int i = 0; i < k; ++i) {
		int a = dfs_index[get<1>(query[i])].first;
		int b = dfs_index[get<1>(query[i])].second;
		set(a, b - 1, get<2>(query[i]) / (b - a), 0, n - 1, 0);
	}
	for (int i = 0; i < n; ++i) {
		if (low[i] != -1) {
			long long sum = 0;
			for (int v : color[i]) sum += get(v, 0, n - 1, 0);
			if (sum <= j * color[i].size()) {
				low[i] = high[i] = -1;
			}
		}
	}


	while (true) {
		memset(stree, 0, sizeof(stree));
		map<int, vector<int>> m;
		for (int i = 0; i < n; ++i) {
			if (low[i] != -1 && high[i] - low[i] > 1) {
				int mid = (low[i] + high[i]) / 2;
				m[mid].push_back(i);
			}
		}
		if (m.size() == 0) break;
		auto it = m.begin();
		for (int i = 0; ; ++i) {
			while (it != m.end() && it->first < get<0>(query[i])) {
				for (int u : it->second) {
					long long sum = 0;
					for (int v : color[u]) sum += get(v, 0, n - 1, 0);
					if (sum <= j * color[u].size()) low[u] = it->first;
					else high[u] = it->first;
				}
				++it;
			}

			if (i == k) {
				while (it != m.end()) {
					for (int u : it->second) {
						long long sum = 0;
						for (int v : color[u]) sum += get(v, 0, n - 1, 0);
						if (sum <= j * color[u].size()) low[u] = it->first;
						else high[u] = it->first;
					}
					++it;
				}
				break;
			}

			int a = dfs_index[get<1>(query[i])].first;
			int b = dfs_index[get<1>(query[i])].second;
			set(a, b - 1, get<2>(query[i]) / (b - a), 0, n - 1, 0);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << high[node_color[i]] << '\n';
	}
}