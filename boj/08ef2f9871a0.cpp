#include <iostream>
using namespace std;

int p[500000];

int find(int i) {
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) p[i] = i;

	int a, b;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		a = find(a);
		b = find(b);

		if (a == b) {
			cout << i;
			return 0;
		}
		p[a] = b;
	}
	cout << 0;
}