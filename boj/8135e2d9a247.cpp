#include <iostream>
#define N 65536
using namespace std;

int tree[N + 1];

void upd(int i, int d) {
	while (i <= N) {
		tree[i] += d;
		i += i & -i;
	}
}

int find(int k) {
	int move = N / 4;
	int i = N / 2;
	while (move) {
		if (tree[i] >= k) {
			i -= move;
		}
		else {
			k -= tree[i];
			i += move;
		}
		move /= 2;
	}
	if (tree[i] < k) ++i;
	return i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int arr[250001];
	for (int i = 1; i < k; ++i) {
		cin >> arr[i];
		upd(arr[i] + 1, 1);
	}

	long long ans = 0;
	for (int i = k; i <= n; ++i) {
		cin >> arr[i];
		upd(arr[i] + 1, 1);
		ans += find((k + 1) / 2) - 1;
		upd(arr[i - k + 1] + 1, -1);
	}

	cout << ans;
}