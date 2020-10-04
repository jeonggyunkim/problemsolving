#include <iostream>
#include <cmath>
#define min(a, b) (a < b ? a : b)

int arr[500];
int temp[500];
int rem;

void change(int dec, int s, int f, int ss, int ff) {
	for (int i = s; i < f; ++i) {
		if (i < s + dec) temp[ff--] = arr[i];
		else temp[ss++] = arr[i];
	}
	int ind = 0;
	for (int i = s; i < f; ++i) arr[i] = temp[ind++];

	rem -= dec;
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	if (k < ceil((double)n / m) || k > (n - m + 1)) {
		printf("-1\n");
		return 0;
	}

	int ind = 0;
	for (int i = 1; i <= n / m; ++i) {
		for (int j = 1; j <= m; ++j) {
			arr[ind++] = n - m * i + j;
		}
	}
	int s = ind, f = n;
	for (int i = 1; i <= n % m; ++i) arr[ind++] = i;

	rem = k - ceil((double)n / m);

	if (rem > 0) {
		if (n % m > 0) change(min(rem, n % m - 1), s, f, 0, n % m - 1);

		s = m * (n / m - 1), f = s + m;
		while (rem > 0) {
			change(min(m - 1, rem), s, f, 0, m - 1);
			s -= m;
			f -= m;
		}
	}
	for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
}