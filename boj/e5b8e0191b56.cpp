#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];

	vector<int> ab(n * n), cd(n * n);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		ab[i * n + j] = a[i] + b[j];
		cd[i * n + j] = c[i] + d[j];
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	long long ans = 0;
	n *= n;
	int i = 0, j = n - 1;
	long long abcnt = 1, cdcnt = 1;
	while (i < n && j >= 0) {
		while (i != n - 1 && ab[i] == ab[i + 1]) {
			abcnt++; i++;
		}
		while (j != 0 && cd[j] == cd[j - 1]) {
			cdcnt++; j--;
		}
		if (ab[i] + cd[j] == 0) {
			ans += abcnt * cdcnt;
			abcnt = 1, cdcnt = 1;
			i++; j--;
		}
		else if (ab[i] + cd[j] < 0) {
			i++;
			abcnt = 1;
		}
		else {
			j--;
			cdcnt = 1;
		}
	}
	cout << ans;
}