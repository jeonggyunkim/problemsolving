#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;

int p[100000];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[a] = b;
}

ii a[100000], b[100000], c[100000];
iii arr[300000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) p[i] = i;

	int x, y, z;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z;
		a[i] = {x, i};
		b[i] = {y, i};
		c[i] = {z, i};
	}
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);

	int j = 0;
	for (int i = 1; i < n; ++i) {
		arr[j++] = {a[i].first - a[i - 1].first, {a[i - 1].second, a[i].second}};
		arr[j++] = {b[i].first - b[i - 1].first, {b[i - 1].second, b[i].second}};
		arr[j++] = {c[i].first - c[i - 1].first, {c[i - 1].second, c[i].second}};
	}
	sort(arr, arr + j);

	long long ans = 0;
	for (int i = 0; i < j; ++i) {
		x = arr[i].second.first;
		y = arr[i].second.second;
		if (find(x) != find(y)) {
			ans += arr[i].first;
			merge(x, y);
		}
	}
	cout << ans;
}