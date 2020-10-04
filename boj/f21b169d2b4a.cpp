#include <iostream>
using namespace std;

int n, k;
int start, finish;

bool colored(int sz, int i, int j) {
	if (i >= start * sz && i < finish * sz) {
		if (j >= start * sz && j < finish * sz) {
			return 1;
		}
	}
	if (sz == 1) return 0;

	i %= sz;
	j %= sz;
	return colored(sz / n, i, j);
}

int main() {
	int nn = 1;

	int s;
	cin >> s;

	if (s == 0) {
		cout << 0;
		return 0;
	}

	cin >> n >> k;
	start = (n - k) / 2;
	finish = n - start;

	for (int i = 1; i < s; ++i) nn *= n;

	int r1, r2, c1, c2;
	cin >> r1 >> r2 >> c1 >> c2;

	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			cout << colored(nn, i, j);
		}
		cout << '\n';
	}
}