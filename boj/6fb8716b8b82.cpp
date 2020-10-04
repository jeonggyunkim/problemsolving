#include <iostream>
#include <algorithm>

int main() {
	int n;
	long long num[1000000];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld", num + i);

	std::sort(num, num + n);

	long long ans;
	int max = -1, i = 1, seq = 1;
	while (i < n) {
		if (num[i - 1] == num[i]) seq++;
		else {
			if (seq > max){
				max = seq;
				ans = num[i - 1];
			}
			seq = 1;
		}
		i++;
	}
	if (seq > max) ans = num[n - 1];

	printf("%lld\n", ans);
}