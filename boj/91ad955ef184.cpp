#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int house[200000];

bool can(int d) {
	int cnt = 1, placed, i;
	placed = house[0];
	i = 1;
	while (i < n) {
		if (house[i] - placed >= d) {
			cnt++;
			placed = house[i];
		}
		i++;
	}
	return cnt >= c;
}

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; ++i) scanf("%d", house + i);
	sort(house, house + n);

	int low = 1, high = (1 << 30), mid;
	while (1 < high - low) {
		mid = (low + high) / 2;
		if (can(mid)) low = mid;
		else high = mid;
	}
	printf("%d\n", low);
}