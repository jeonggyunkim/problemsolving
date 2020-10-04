#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

int n;
vector<vector<iii>> edge;
bool used[10];
long long w[10];

void dfs(int i) {
	used[i] = 1;
	for (iii u: edge[i]) {
		if (!used[get<0>(u)]) {
			w[get<0>(u)] = w[i] * get<2>(u);
			for (int j = 0; j < n; ++j) {
				if (used[j]) {
					w[j] *= get<1>(u);
				}
			}
			dfs(get<0>(u));
		}
	}
}

int main() {
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	edge.resize(n);

	int a, b, p, q;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> p >> q;
		edge[a].push_back({b, p, q});
		edge[b].push_back({a, q, p});
	}

	w[0] = 1;
	dfs(0);
	long long g = w[0];
	for (int i = 1; i < n; ++i) g = __gcd(g, w[i]);
	for (int i = 0; i < n; ++i) {
		cout << w[i] / g << ' ';
	}
}