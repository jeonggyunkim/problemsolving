#include <iostream>
#include <vector>
#include <tuple>
#define N 100010
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<ll, ll, ll, int> iiii;

long long sum, sqsum, cnt;
int child[N];
bool leaf[N];
vector<vector<ii>> edge;


int dfs(int i, int p, int d) {
	if (leaf[i]) {
		sum += d;
		sqsum += d * d;
		cnt++;
		return child[i] = 1;
	}
	child[i] = 0;
	for (ii u: edge[i]) {
		if (u.first != p) child[i] += dfs(u.first, i, d + u.second);
	}
	return child[i];
}

iiii tree(int start, int dist) {
	sum = 0;
	sqsum = 0;
	cnt = 0;
	dfs(start, -1, dist);

	iiii ret = {0, sum, sqsum, cnt};

	if (cnt <= 1) return ret;

	int num = child[start] / 2, p = -1;
	while (1) {
		if (child[start] <= num) {
			break;
		}
		int maxChild = -1, next;
		for (ii u: edge[start]) {
			if (u.first != p && child[u.first] >= maxChild) {
				maxChild = child[u.first];
				next = u.first;
			}
		}
		p = start;
		start = next;
	}

	int d;
	for (auto it = edge[p].begin(); it != edge[p].end(); ++it) {
		if (it->first == start) {
			d = it->second;
			edge[p].erase(it);
			break;
		}
	}
	for (auto it = edge[start].begin(); it != edge[start].end(); ++it) {
		if (it->first == p) {
			edge[start].erase(it);
			break;
		}
	}

	iiii a = tree(p, 0);
	iiii b = tree(start, d);

	get<0>(ret) += get<0>(a);
	get<0>(ret) += get<0>(b);
	get<0>(ret) += get<2>(a) * get<3>(b);
	get<0>(ret) += get<2>(b) * get<3>(a);
	get<0>(ret) += 2 * get<1>(a) * get<1>(b);

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	edge.resize(n);

	int a, b, w;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b >> w;
		a--; b--;
		edge[a].push_back({b, w});
		edge[b].push_back({a, w});
	}
	int start;
	for (int i = 0; i < n; ++i) {
		if (edge[i].size() == 1) leaf[i] = 1;
		else start = i;
	}

	iiii ans = tree(start, 0);
	cout << get<0>(ans);
}
