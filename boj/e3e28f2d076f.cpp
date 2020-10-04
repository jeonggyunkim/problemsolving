#include <iostream>
#include <queue>
using namespace std;

int len(int n) {
	int ret = 0;
	while (n) {
		ret++;
		n /= 10;
	}
	return ret;
}

int diag(int n, int dir) {
	int ret = 1;
	int d = dir * 2;
	for (int i = 0; i < n; ++i) {
		ret += d;
		d += 8;
	}
	return ret;
}

int get(int i, int j) {
	int d;
	if (j > -i) {
		if (j < i) {
			d = j + i;
			return diag(i, 3) + d;
		}
		else {
			d = i + j;
			if (i == j) return diag(i, 4);
			else return diag(j, 1) - d;
		}
	}
	else {
		if (j < i) {
			d = i - j;
			return diag(-j, 2) + d;
		}
		else {
			d = -i - j;
			return diag(-i, 1) + d;
		}
	}
}


int main() {
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int m = -1;
	queue<int> q;
	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			int t = get(i, j);
			q.push(t);
			m = max(m, t);
		}
	}

	int l = len(m);

	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			for (int k = 0; k < l - len(q.front()); ++k) cout << ' ';
			cout << q.front(); q.pop();
			if (j != c2) cout << ' ';
		}
		cout << '\n';
	}
}