#include <iostream>
using namespace std;

int n, m;
int st[10];
bool mark[10];

void rec(int k) {
	if (k == m) {
		for (int i = 0; i < m; ++i) cout << st[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!mark[i]) {
			st[k] = i + 1;
			mark[i] = 1;
			rec(k + 1);
			mark[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	rec(0);
}