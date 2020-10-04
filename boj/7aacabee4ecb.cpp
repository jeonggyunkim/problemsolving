#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, t;
	scanf("%d", &n);

	int num[10010], size = 1;
	scanf("%d", &t); num[0] = t;
	for (int i = 1; i < n; ++i) {
		scanf("%d", &t);
		if (t < num[size - 1]) *lower_bound(num, num + size, t) = t;
		else if (t > num[size - 1]) num[size++] = t;
	}
	printf("%d\n", size);
}