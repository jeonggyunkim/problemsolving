#include <iostream>
using namespace std;

int n;
int sz;

char cal(int i, int j) {
	i %= sz;
	j %= sz;
	int dist = abs(n - 1 - i) + abs(n - 1 - j);
	if (dist < n) {
		dist %= 26;
		return 'a' + dist;
	}
	else return '.';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	sz = 2 * n - 1;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			cout << cal(i, j);
		}
		cout << '\n';
	}
}