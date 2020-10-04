#include <iostream>

int k, n;
int len[10000];

long long count(int n) {
	long long ret = 0;
	for (int i = 0; i < k; ++i) ret += len[i] / n;
	return ret;
}

int main() {
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; ++i) scanf("%d", len + i);

	unsigned int low = 1, high = (1 << 31), mid;
	while (1 < high - low) {
		mid = (low + high) / 2;
		long long cnt = count(mid);
		if (cnt >= n) low = mid;
		else high = mid;
	}
	printf("%d\n", low);
}