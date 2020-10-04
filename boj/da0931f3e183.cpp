#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> line;

struct LiChaoTree {
	const ll INF = 1e18;
	inline ll f(line l, ll x) {
		return l.first * x + l.second;
	}
	struct Node {
		int lnode, rnode;
		ll xl, xr;
		line l;
	};
	vector<Node> nodes;
	LiChaoTree(ll xmin, ll xmax) {
		nodes.push_back({-1, -1, xmin, xmax, {0, INF}});
	}
	void insert(int n, line newline) {
		ll xl = nodes[n].xl, xr = nodes[n].xr;
		ll xm = (xl + xr) / 2;

		line llow = nodes[n].l, lhigh = newline;
		if (f(llow, xl) > f(lhigh, xl)) swap(llow, lhigh);

		if (f(llow, xr) <= f(lhigh, xr)) {
			nodes[n].l = llow;
			return;
		}
		else if (f(llow, xm) <= f(lhigh, xm)) {
			nodes[n].l = llow;
			if (nodes[n].rnode == -1) {
				nodes[n].rnode = nodes.size();
				nodes.push_back({-1, -1, xm + 1, xr, {0, INF}});
			}
			insert(nodes[n].rnode, lhigh);
		}
		else {
			nodes[n].l = lhigh;
			if (nodes[n].lnode == -1) {
				nodes[n].lnode = nodes.size();
				nodes.push_back({-1, -1, xl, xm, {0, INF}});
			}
			insert(nodes[n].lnode, llow);
		}
	}

	ll get(int n, ll xq) {
		if (n == -1) return INF;
		ll xl = nodes[n].xl, xr = nodes[n].xr;
		ll xm = (xl + xr) / 2;
		if (xq <= xm) return min(f(nodes[n].l, xq), get(nodes[n].lnode, xq));
		else return min(f(nodes[n].l, xq), get(nodes[n].rnode, xq));
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> x(n);
	ll t;

	x[0] = 0;
	for (int i = 1; i < n; ++i) {
		cin >> t;
		x[i] = x[i - 1] + t;
	}

	LiChaoTree tree(0, x[n - 1]);

	ll time = 0;
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		if (i) time = tree.get(0, x[i]);
		cin >> a >> b;
		tree.insert(0, {b, time + a - x[i] * b});
	}

	cout << tree.get(0, x[n - 1]);
}