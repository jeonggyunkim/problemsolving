#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<long long> a(n + 1), b(n + 1), power;
	b[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		if (a[i] > 0) {
			if (b[i - 1] + a[i] != b[i]) {
				cout << -1;
				return 0;
			}
		}
		else if (b[i - 1] >= -a[i]) {
			if (b[i - 1] + a[i] != b[i]) {
				cout << -1;
				return 0;
			}
		}
		else {
			power.push_back(b[i] - a[i] - b[i - 1]);
		}
	}

	if (power.empty()) {
		cout << 1;
		return 0;
	}

	long long ans = power[0];
	for (int i = 1; i < power.size(); ++i) {
		ans = __gcd(ans, power[i]);
	}

	for (int i = 1; i <= n; ++i) {
		if (-a[i] > b[i - 1]) {
			long long cnt = (b[i] - a[i] - b[i - 1]) / ans;
			if (b[i - 1] + (cnt - 1) * ans >= -a[i]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
}