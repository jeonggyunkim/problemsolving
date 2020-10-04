#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

vector<int> init;
int n, m;
ii stree[(1 << 20) + 10];

void build(int li, int ri, int i) {
	if (li == ri) {
		if (li <= n) stree[i] = ii(0, init[li]);
		else stree[i] = ii(0, 0);
		return;
	}
	build(li, (li + ri) / 2, 2 * i + 1);
	build((li + ri) / 2 + 1, ri, 2 * i + 2);
}

ii get(int n, int li, int ri, int i) {
	if (li == ri) return stree[i];
	int mid = (li + ri) / 2;
	ii t;
	if (n <= mid) t = get(n, li, mid, 2 * i + 1);
	else t = get(n, mid + 1, ri, 2 * i + 2);
	if (t.first > stree[i].first) return t;
	else return stree[i];
}

void set(int l, int r, ii v, int li, int ri, int i) {
	if (l == li && r == ri) {
		stree[i] = v;
		return;
	}
	int mid = (li + ri) / 2;
	if (r <= mid) {
		set(l, r, v, li, mid, 2 * i + 1);
		return;
	}
	if (l >= mid + 1) {
		set(l, r, v, mid + 1, ri, 2 * i + 2);
		return;
	}

	set(l, mid, v, li, mid, 2 * i + 1);
	set(mid + 1, r, v, mid + 1, ri, 2 * i + 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, q;
	cin >> n >> m >> k >> q;

	memset(stree, -1, sizeof(stree));
	init.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> init[i];

	queue<ii> que;
	build(0, m, 0);
	for (int i = m + 1; i <= n; ++i) {
		if (!que.empty() && que.back().first == init[i]) que.back().second += 1;
		else que.push(ii(init[i], 1));
	}

	long long o, a, b, t;
	for (int query = 1; query <= q; ++query) {
		cin >> o;
		if (o == 1) {
			cin >> a >> b;
			t = b - a + 1;
			int sp = a;
			while (t && !que.empty()) {
				if (que.front().second <= t) {
					set(sp, sp + que.front().second - 1, ii(query, que.front().first), 0, m, 0);
					sp += que.front().second;
					t -= que.front().second;
					que.pop();
				}
				else {
					set(sp, sp + t - 1, ii(query, que.front().first), 0, m, 0);
					que.front().second -= t;
					t = 0;
				}
			}
			if (t) set(sp, sp + t - 1, ii(query, 0), 0, m, 0);
		}
		else if (o == 2) {
			cin >> t;
			cout << get(t, 0, m, 0).second << ' ';
		}
		else if (o == 3) {
			cin >> a >> b;
			que.push(ii(a, b));
		}
		else {
			cin >> t;
			while (t && !que.empty()) {
				if (que.front().second <= t) {
					t -= que.front().second;
					que.pop();
				}
				else {
					que.front().second -= t;
					t = 0;
				}
			}
		}
	}
	cout << '\n';

	for (int i = 1; i <= m; ++i) {
		cout << get(i, 0, m, 0).second << ' ';
	}
	cout << '\n';
}