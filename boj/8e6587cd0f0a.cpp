#include <iostream>
#define MOD 1000000007
using namespace std;

int n = 200001, cnt[200002];
long long sum[200002];

void set(int i, int d) {
	while (i <= n) {
		cnt[i]++;
		sum[i] += d;
		i += (i & -i);
	}
}

int getcnt(int i) {
	int ret = 0;
	while (i) {
		ret += cnt[i];
		i &= i - 1;
	}
	return ret;
}

long long getsum(int i) {
	long long ret = 0;
	while (i) {
		ret += sum[i];
		i &= i - 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q, t;
	cin >> q;

	cin >> t; t++;
	set(t, t);

	long long ans = 1, a, b, c;
	for (int i = 1; i < q; ++i) {
		cin >> t; t++;
		a = getcnt(t);
		b = getsum(t);
		c = ((a * t - b) + (getsum(200000) - b - t * (i - a))) % MOD;

		ans = (ans * c) % MOD;
		set(t, t);
	}
	cout << ans;
}