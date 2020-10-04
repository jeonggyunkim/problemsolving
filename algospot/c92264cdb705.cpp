#include <iostream>
using namespace std;

int height[20000];

int findmax(int left, int right) {
	if (left == right) return height[left];
	int mid = (left + right) / 2;

	int h = min(height[mid], height[mid + 1]), w = 2;
	int area = w * h;
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
	int tc;
	scanf("%d", &tc);


	while (tc--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; ++i) scanf("%d", height + i);
		printf("%d\n", findmax(0, n - 1));
	}
}
