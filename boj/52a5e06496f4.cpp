#include <iostream>
using namespace std;

int main() {
	int r;
	cin >> r;

	for (int i = 0; i < r; ++i) {
		int M, N, m, n;
		cin >> M >> N >> m >> n;

		while (m != n && m <= M * N) {
			m > n ? n += N : m += M;
		}

		if (m == n) {
			cout << m << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	return 0;
}