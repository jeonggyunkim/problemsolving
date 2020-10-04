#include <iostream>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int n;
int arr[100010];
ii tree[100010];

void set(int i, int sign, int prev_sign) {
	while (i <= n) {
		if (sign == 1) tree[i].first++;
		else if (sign == -1) tree[i].second++;

		if (prev_sign == 1) tree[i].first--;
		else if (prev_sign == -1) tree[i].second--;
		i += (i & -i);
	}
}

ii get(int i) {
	ii ret(0, 0);
	while (i) {
		ret.first += tree[i].first;
		ret.second += tree[i].second;
		i &= i - 1;
	}
	return ret;
}

int main() {
	int k;
	while (scanf("%d %d", &n, &k) != EOF) {
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; ++i) {
			scanf("%d ", arr + i);
			if (arr[i] > 0) set(i, 1, 0);
			else if (arr[i] < 0) set(i, -1, 0);
		}
		char c; int a, b;
		for (int i = 0; i < k; ++i) {
			scanf("%c %d %d ", &c, &a, &b);
			if (c == 'C') {
				int pv = 0;
				if (arr[a] > 0) pv = 1;
				else if (arr[a] < 0) pv = -1;
				arr[a] = b;
				if (b > 0) set(a, 1, pv);
				else if (b < 0) set(a, -1, pv);
				else set(a, 0, pv);
			}
			else {
				int d = b - a + 1;
				ii r1 = get(b);
				ii r2 = get(a - 1);
				ii r(r1.first - r2.first, r1.second - r2.second);
				if (r.first + r.second != d) printf("0");
				else {
					if (r.second & 1) printf("-");
					else printf("+");
				}
			}
		}
		printf("\n");
	}
}