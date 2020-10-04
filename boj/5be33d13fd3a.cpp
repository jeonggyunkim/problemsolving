#include <iostream>
#include <set>
using namespace std;

set<int> s;

bool two(int n) {
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0 && !s.count(i) && !s.count(n / i)) return 1;
	}
	return 0;
}

bool three(int n) {
	for (int i = 1; i * i * i <= n; ++i) {
		if (n % i == 0 && !s.count(i) && two(n / i)) return 1;
	}
	return 0;
}

int main() {
	int n, m;
	cin >> n >> m;

	int t;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		s.insert(t);
	}
	
	int ans = 0;
	while (1) {
		if (n + ans >= 1 && three(n + ans)) {
			cout << ans;
			return 0;
		}
		if (n - ans >= 1 && three(n - ans)) {
			cout << ans;
			return 0;
		}
		ans++;
	}
}