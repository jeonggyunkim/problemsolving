#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, x, sum = 0;
		cin >> n >> x;
		for (int i = 1; i <= n; ++i) sum += i;
		vector<int> arr;

		int mx = n % 2, mi = n % 2;
		for (int i = 0; i < n / 2; ++i) {
			mx += n - i;
			arr.push_back(n - i);
		}
		for (int i = 0; i < n / 2; ++i) mi += 2 + i;
		mx = 2 * mx - sum;
		mi = 2 * mi - sum;
		if (x >= mi && x <= mx && (mx - x) % 2 == 0) {
			cout << "YES\n";
			if (n == 1) {
				cout << 1 << '\n';
				continue;
			}
			int dec = (mx - x) / 2;
			for (int i = 0; i < n / 2; ++i) {
				arr[i] -= dec / (n / 2);
			}
			dec %= (n / 2);
			for (int i = 0; i < dec; ++i) {
				arr[n / 2 - 1 - i]--;
			}

			set<int> my, opp;
			for (int u: arr) my.insert(u);
			for (int i = 2; i <= n; ++i) {
				if (!my.count(i)) opp.insert(i);
			}
			bool turn = 1;
			while (!my.empty() || !opp.empty()) {
				if (turn) {
					cout << *my.begin() << ' ';
					my.erase(*my.begin());
				}
				else {
					cout << *opp.begin() << ' ';
					opp.erase(*opp.begin());
				}
				turn = !turn;
			}
			cout << "1\n";
		}
		else cout << "NO\n";
	}
}