#include <iostream>
#include <vector>
#include <memory.h>
#define N 1000100
using namespace std;

int stree[4 * N];

int set(int ind, int newv, int li, int ri, int i) {
	if (li == ri) return stree[i] = newv;
	int mid = (li + ri) / 2;
	if (ind <= mid)
		return stree[i] = min(set(ind, newv, li, mid, 2 * i + 1), stree[2 * i + 2]);
	else
		return stree[i] = min(stree[2 * i + 1], set(ind, newv, mid + 1, ri, 2 * i + 2));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(stree, -1, sizeof(stree));

	int q, mod, ind = 0;
	int op, t;
	long long num;
	cin >> q >> mod;

	if (mod >= q) {
		while (q--) {
			cin >> op;
			if (op == 1) cin >> num;
			else if (op == 3) cout << -1 << '\n';
		}
		return 0;
	}

	vector<int> arr;
	vector<vector<int>> link(mod);
	for (int i = 0; i < mod; ++i) link[i].push_back(-1);

	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> num;
			t = num % mod;
			set(t, ind, 0, mod - 1, 0);
			link[t].push_back(ind++);
			arr.push_back(t);
		}
		else if (op == 2) {
			if (arr.size() == 0) {
				continue;
			}
			t = arr.back();
			arr.pop_back();
			ind--;
			link[t].pop_back();
			set(t, link[t].back(), 0, mod - 1, 0);
		}
		else {
			if (stree[0] == -1) cout << -1 << '\n';
			else cout << arr.size() - stree[0] << '\n';
		}
	}
}