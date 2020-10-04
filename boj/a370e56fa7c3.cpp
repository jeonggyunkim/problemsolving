#include <iostream>

int height[500001];
int vl[250001] = {};
int vr[250001] = {};

long long find(int left, int right) {
	if (left == right) return 0;
	if (right - left == 1) return 1;

	int mid = (left + right) / 2;
	long long t1 = find(left, mid);
	long long t2 = find(mid + 1, right);
	long long t3 = 0;
	int i = mid, ma = -1, mb = -1;

	int l = 1, r = 1;
	while (i >= left) {
		if (height[i] >= ma) {
			ma = height[i];
			vl[l++] = ma;
		}
		i--;
	}
	i = mid + 1;
	while (i <= right) {
		if (height[i] >= mb) {
			mb = height[i];
			vr[r++] = mb;
		}
		i++;
	}

	int i1 = 0, i2 = 1;
	for (int i = 1; i < l; ++i) {
		while (i1 < r && vr[i1] < vl[i - 1]) i1++;
		while (i2 < r && vr[i2 - 1] <= vl[i]) i2++;
		t3 += i2 - i1;
		if (i1 == 0) t3--;
	}

	return t1 + t2 + t3;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", height + i);

	printf("%lld\n", find(0, n - 1));
}