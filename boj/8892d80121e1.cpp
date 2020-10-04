#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;

	if (k == 0) {
		cout << 0;
		return 0;
	}
	vector<long long> d(130, 0);
	d[k] = 1;
	for (int i = 0; i < n; ++i) {
		vector<long long> t(130, 0);
		for (int j = 0; j < 130; ++j) {
			if (j > 1) t[j - 1] += d[j];
			t[j + 1] += d[j];
		}
		d = t;
	}
	long long ans = 0;
	for (int i = 0; i < 130; ++i) ans += d[i];

	cout << ans;
}