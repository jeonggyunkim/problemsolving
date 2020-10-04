#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

bool comp(ii a, ii b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	ii time[100001];
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d %d", &time[i].first, &time[i].second);
	sort(time, time + n, comp);

	int cnt = 0, i = n - 1;
	while (i >= 0) {
		int st = time[i].first;
		i--;
		while (i >= 0 && st < time[i].second) {
			if (time[i].first > st) st = time[i].first;
			i--;
		}
		cnt++;
	}
	printf("%d\n", cnt);
}