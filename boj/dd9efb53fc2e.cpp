#include <iostream>
using namespace std;

int n;
int arr[1025][1025];
int tree[1025][1025];

void set(int i, int j, int d) {
	while (i <= n) {
		int t = j;
		while (t <= n) {
			tree[i][t] += d;
			t += (t & -t);
		}
		i += (i & -i);
	}
}

int get(int i, int j) {
	int ret = 0;
	while (i) {
		int t = j;
		while (t) {
			ret += tree[i][t];
			t &= (t - 1);
		}
		i &= (i - 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
			set(i, j, arr[i][j]);
		}
	}

	int w, a, b, c, d;
	for (int i = 1; i <= m; ++i) {
		cin >> w;
		if (w == 0) {
			cin >> a >> b >> c;
			set(a, b, c - arr[a][b]);
			arr[a][b] = c;
		}
		else {
			cin >> a >> b >> c >> d;
			cout << get(c, d) - get(a - 1, d) - get(c, b - 1) + get(a - 1, b - 1) << '\n';
		}
	}
}