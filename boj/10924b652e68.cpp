#include <iostream>
#include <vector>
using namespace std;

long long fac[20] = {1, 1};

int main() {
	for (int i = 2; i <= 19; ++i) fac[i] = fac[i - 1] * i;

	int n, type, arr[20];
	scanf("%d", &n);
	scanf("%d", &type);

	if (type == 1) {
		long long num;
		scanf("%lld", &num);
		num--;
		vector<int> v;
		for (int i = 0; i < n; ++i) v.push_back(i + 1);
		for (int i = 0; i < n; ++i) {
			long long t = num / fac[n - 1 - i];
			printf("%d ", v[t]);
			v.erase(v.begin() + t);
			num -= t * fac[n - 1 - i];
		}
	}
	else {
		for (int i = 0; i < n; ++i) scanf("%d", arr + i);
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			int small = 0;
			for (int j = i + 1; j < n; ++j) if (arr[i] > arr[j]) small++;
			ans += small * fac[n - i - 1];
		}
		printf("%lld", ans + 1);
	}
}