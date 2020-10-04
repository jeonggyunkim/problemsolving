#include <iostream>
using namespace std;

int tree[100010];
int n;

void insert(int i, int d) {
	while (i <= n) {
		tree[i] += d;
		i += (i & -i);
	}
}

int get(int i) {
	long long ret = 0;
	while (i) {
		ret += tree[i];
		i &= (i - 1);
	}
	return ret;
}

int main() {
	int k;
	cin >> n >> k;

	for (int i = 1; i <= n + 1; ++i) {
		tree[i] = (1 << __builtin_ctz(i));
	}

	int now = 1;
	int size = n;
	n++;
	cout << '<';
	while (size) {
		now += k - 1;
		now %= size;
		if (now == 0) now += size;
		int low = 0, high = n;
		while (high - low != 1) {
			int mid = (low + high) / 2;
			if (get(mid) >= now) high = mid;
			else low = mid;
		}
		if (size == 1) cout << high << '>';
		else cout << high << ", ";
		insert(high, -1);
		size--;
	}
}