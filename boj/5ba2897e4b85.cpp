#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q, mod, op, t;
	long long num;
	cin >> q >> mod;

	vector<int> arr;
	vector<vector<int>> link(mod);
	for (int i = 0; i < mod; ++i) link[i].push_back(-1);

	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> num;
			t = num % mod;
			link[t].push_back(arr.size());
			arr.push_back(t);
		}
		else if (op == 2) {
			if (arr.size() == 0) {
				continue;
			}
			link[arr.back()].pop_back();
			arr.pop_back();
		}
		else {
			int ans = 1 << 30;
			for (int i = 0; i < mod; ++i) {
				ans = min(link[i].back(), ans);
			}
			if (ans == -1) cout << -1 << '\n';
			else cout << arr.size() - ans << '\n';
		}
	}
}