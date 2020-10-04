#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int fib[43] = {1, 2};
	for (int i = 2; i < 43; ++i) fib[i] = fib[i - 1] + fib[i - 2];

	int tc;
	cin >> tc;
	while (tc--) {
		int n, t;
		cin >> n;

		vector<int> ans;
		while (n) {
			for (int i = 0; i < 43; ++i) {
				if (fib[i] <= n) t = fib[i];
			}
			n -= t;
			ans.push_back(t);
		}
		for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << ' ';
		cout << '\n';
	}
}