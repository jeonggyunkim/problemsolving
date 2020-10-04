#include <iostream>
using namespace std;

int n = 1000010, tree[1000010];

void set(int i, int d) {
	while (i <= n) {
		tree[i] += d;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i &= i - 1;
	}
	return ret;
}

int find_lower(int d) {
	int ind = 0;
	while (true) {
		int r = 1;
		while (ind + r <= n && tree[ind + r] < d) r <<= 1;
		if (r == 1) return ind + r;
		else {
			r >>= 1;
			d -= tree[ind + r];
			ind += r;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	int a, b, c;
	while (q--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			int ind = find_lower(b);
			cout << ind << '\n';
			set(ind, -1);
		}
		else {
			cin >> b >> c;
			set(b, c);
		}
	}
}