#include <iostream>
#include <vector>
#define EPS 1e-7
using namespace std;

typedef long long ll;
typedef pair<pair<ll, ll>, int> line;

int ux[100010];

struct LiChaoTree {
	const ll INF = 1e18;
	inline pair<ll, pair<int, int>> f(line l, ll x) {
		return {l.first.first * x + l.first.second, {-ux[l.second], l.second}};
	}
	struct Node {
		int lnode, rnode;
		ll xl, xr;
		line l;
	};
	vector<Node> nodes;
	LiChaoTree(ll xmin, ll xmax) {
		nodes.push_back({-1, -1, xmin, xmax, {{0, -INF}, 0}});
	}
	void insert(int n, line newline) {
		ll xl = nodes[n].xl, xr = nodes[n].xr;
		ll xm = (xl + xr) / 2;

		line llow = nodes[n].l, lhigh = newline;
		if (f(llow, xl) > f(lhigh, xl)) swap(llow, lhigh);

		if (f(llow, xr) <= f(lhigh, xr)) {
			nodes[n].l = lhigh;
			return;
		}
		else if (f(llow, xm) < f(lhigh, xm)) {
			nodes[n].l = lhigh;
			if (nodes[n].rnode == -1) {
				nodes[n].rnode = nodes.size();
				nodes.push_back({-1, -1, xm + 1, xr, {{0, -INF}, 0}});
			}
			insert(nodes[n].rnode, llow);
		}
		else {
			nodes[n].l = llow;
			if (nodes[n].lnode == -1) {
				nodes[n].lnode = nodes.size();
				nodes.push_back({-1, -1, xl, xm, {{0, -INF}, 0}});
			}
			insert(nodes[n].lnode, lhigh);
		}
	}

	pair<ll, pair<int, int>> get(int n, ll xq) {
		if (n == -1) return {-INF, {0, 0}};
		ll xl = nodes[n].xl, xr = nodes[n].xr;
		ll xm = (xl + xr) / 2;
		if (xq <= xm) return max(f(nodes[n].l, xq), get(nodes[n].lnode, xq));
		else return max(f(nodes[n].l, xq), get(nodes[n].rnode, xq));
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll maxy, miny;
	cin >> maxy >> miny;

	LiChaoTree tree(0, (maxy - miny) * 1000);

	int n;
	cin >> n;

	ll lx, a;
	for (int i = 1; i <= n; ++i) {
		cin >> ux[i] >> lx;
		a = lx - ux[i];
		lx *= -1000 * (maxy - miny);
		tree.insert(0, {{a, lx}, i});
	}

	int q;
	cin >> q;

	double t;
	ll y;
	while (q--) {
		cin >> t;
		if (t < 0) y = t * 1000 - EPS;
		else y = t * 1000 + EPS;
		y -= miny * 1000;
		cout << tree.get(0, y).second.second << '\n';
	}
}