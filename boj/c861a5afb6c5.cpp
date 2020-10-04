#include <iostream>

int n, m;
int len[1000000];

long long can(int cut) {
	long long ret = 0;
	for (int i = 0; i < n; ++i) if (len[i] - cut > 0) ret += len[i] - cut;
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", len + i);

	unsigned int low = 0, high = (1 << 31), mid;
	while (1 < high - low) {
		mid = (low + high) / 2;
		long long cnt = can(mid);
		if (cnt >= m) low = mid;
		else high = mid;
	}
	printf("%d\n", low);
}