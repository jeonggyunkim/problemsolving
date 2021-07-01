#include <iostream>
#include <cmath>
#include <algorithm>
#define SQ(a) ((a) * (a))
using namespace std;

typedef pair<double, pair<int, int>> dii;

dii arr[10000];
double x[100], y[100];
int p[100];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) p[i] = i;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			arr[cnt++] = {sqrt(SQ(x[i] - x[j]) + SQ(y[i] - y[j])), {i, j}};
		}
	}
	sort(arr, arr + cnt);

	double ans = 0;
	for (int i = 0; i < cnt; ++i) {
		int a = arr[i].second.first;
		int b = arr[i].second.second;
		if (find(a) != find(b)) {
			ans += arr[i].first;
			merge(a, b);
		}
	}
	cout.precision(20);
	cout << ans;
}