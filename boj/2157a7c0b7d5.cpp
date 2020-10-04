#include <iostream>
using namespace std;

int can[1001][31], n, w;
int tree[1001];

int drop(int s, int move) {
	if (can[s][move] > 0) return can[s][move];
	if (s >= n) return 0;
	if (move == w) {
		int cnt = 0;
		if (move & 1) {
			for (int i = s; i < n; ++i) if (tree[i] == 2) cnt++;
		}
		else {
			for (int i = s; i < n; ++i) if (tree[i] == 1) cnt++;
		}
		return can[s][move] = cnt;
	}
	int t1 = drop(s, move + 1);
	int t2 = drop(s + 1, move) + ((move & 1) == (tree[s] == 2));
	int t3 = drop(s + 1, move + 1) + ((move & 1) == (tree[s] == 2));

	return can[s][move] = max(t1, max(t2, t3));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w;
	for (int i = 0; i < n; ++i) cin >> tree[i];

	cout << drop(0, 0);
}