#include <iostream>
using namespace std;

int height[100001];

long long findmax(int left, int right) {
	if (left == right) return height[left];
	int mid = (left + right) / 2;

	long long h = min(height[mid], height[mid + 1]), w = 2;
	long long area = w * h;
	int i1 = mid - 1, i2 = mid + 2;
	while (i1 >= left || i2 <= right) {
		if (i2 > right || ((i1 >= left) && (height[i1] > height[i2]))) {
			if (height[i1] < h) h = height[i1];
			i1--;
		}
		else {
			if (height[i2] < h) h = height[i2];
			i2++;
		}
		w++;
		if (area < w * h) area = w * h;
	}

	return max(findmax(left, mid), max(findmax(mid + 1, right), area));
}

int main() {
	int n;
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; ++i) scanf("%d", height + i);
		printf("%lld\n", findmax(0, n - 1));
	}
}