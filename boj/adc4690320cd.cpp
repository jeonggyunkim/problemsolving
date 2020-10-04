#include <iostream>

int n, m;
int time[10001];

long long check(long long t) {
	if (t == -1) return 0;
	long long child = 0;
	for (int i = 0; i < m; ++i) child += t / time[i] + 1;
	return child;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) scanf("%d", time + i);

	long long low = -1, high = 60000003000, mid;
	while (high - low > 1) {
		mid = (low + high) / 2;
		long long t = check(mid);
		if (t < n) low = mid;
		else high = mid;
	}
	int r = n - check(low);
	int t = 1;
	for (int i = 0; i < m; ++i) {
		if (high % time[i] == 0) {
			if (t == r) printf("%d\n", i + 1);
			t++;
		}
	}
}