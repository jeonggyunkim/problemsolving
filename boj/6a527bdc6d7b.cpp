#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int cnt = 0, ans = 0;

	vector<int> a(n, 0);
	for (int i = 0; i < m; ++i) a[i] = 1;
	do {
		vector<int> b(n, 0);
		for (int i = 0; i < m; ++i) b[i] = 1;

		do {
			cnt++;
			int same = 0;
			for (int i = 0; i < n; ++i) if (a[i] && b[i]) same++;
			if (same >= k) {
				ans++;
			}
		} while (prev_permutation(b.begin(), b.end()));
	} while (prev_permutation(a.begin(), a.end()));

	cout.precision(15);
	cout << (double)ans / cnt;
}