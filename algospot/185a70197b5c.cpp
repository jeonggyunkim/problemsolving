#include <iostream>

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int arr[1000];
		int n, l;
		scanf("%d %d", &n, &l);

		for (int i = 0; i < n; ++i) scanf("%d", arr + i);

		double min = 10000000, t;
		int sum;
		for (int day = l; day <= n; ++day) {
			for (int i = 0; i <= n - day; ++i) {
				sum = 0;
				for (int j = i; j < i + day; ++j) {
					sum += arr[j];
				}
				t = (double)sum / day;
				if (t < min) min = t;
			}
		}

		printf("%.9f\n", min);
	}
}
