#include <bits/stdc++.h>
#define N 1000000
using namespace std;

typedef pair<int, int> ii;

int unluck(int i) {
	int a = i / 1000, b = i % 1000;
	int ret = 0;
	while (a) {
		ret += a % 10;
		a /= 10;
	}
	while (b) {
		ret -= b % 10;
		b /= 10;
	}
	return abs(ret);
}

int tree[N + 10];

void insert(int i, int d) {
	while (i <= N) {
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

ii u[N];
int num[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; ++i) u[i] = {unluck(i), -i};
	sort(u, u + N);

	for (int i = 0; i < N; ++i) {
		num[-u[i].second] = get(-u[i].second + 1);
		insert(-u[i].second + 1, 1);
	}

	int n, t;
	cin >> n;

	while (n--) {
		cin >> t;
		cout << num[t] << '\n';
	}
}