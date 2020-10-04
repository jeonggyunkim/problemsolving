#include <iostream>
#include <queue>
using namespace std;

const int N = 65540;
int tree[N];

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i &= i - 1;
	}
	return ret;
}

void set(int i, int d) {
	while (i <= N) {
		tree[i] += d;
		i += i & -i;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, t;
	cin >> n >> k;

	queue<int> q;
	for (int i = 0; i < k - 1; ++i) {
		cin >> t;
		t++;
		set(t, 1);
		q.push(t);
	}

	long long ans = 0;
	for (int i = 0; i <= n - k; ++i) {
		cin >> t;
		t++;
		set(t, 1);
		q.push(t);
		int low = 0, high = N, mid;
		while (high - low != 1) {
			mid = (low + high) / 2;
			if (get(mid) < (k + 1) / 2) low = mid;
			else high = mid;
		}
		ans += (high - 1);
		set(q.front(), -1);
		q.pop();
	}

	cout << ans;
}
