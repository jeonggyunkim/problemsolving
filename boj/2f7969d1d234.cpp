#include <iostream>
using namespace std;

typedef pair<int, int> ii;

int treesz = 2000001;
int tree[2000001];

void insert(int i, int d) {
	while (i <= treesz) {
		tree[i] += d;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i &= (i - 1);
	}
	return ret;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	int a, b;
	while (q--) {
		cin >> a >> b;
		if (a == 1) {
			insert(b, 1);
		}
		else {
			int low = 0, high = treesz;
			while (high - low != 1) {
				int mid = (low + high) / 2;
				if (get(mid) >= b) high = mid;
				else low = mid;
			}
			insert(high, -1);
			cout << high << '\n';
		}
	}
}