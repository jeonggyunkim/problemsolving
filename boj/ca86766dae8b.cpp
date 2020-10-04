#include <iostream>
#include <algorithm>
using namespace std;

struct s { int a, b; };

bool comp(s a, s b) { return a.a < b.a; }

int main() {
	int n;
	s a[55];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &(a[i].a));
		a[i].b = i;
	}
	stable_sort(a, a + n, comp);

	int r[55];
	for (int i = 0; i < n; ++i) r[a[i].b] = i;
	for (int i = 0; i < n; ++i) printf("%d ", r[i]);
	printf("\n");
}