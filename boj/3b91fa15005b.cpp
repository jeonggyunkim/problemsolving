#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, k, t;
	cin >> n >> k;

	multiset<int> cnt[10];
	for (int i = 0; i < n; ++i) {
		cin >> t;
		cnt[t % k].insert(t);
	}

	for (int i = 1; i <= n; ++i) {
		if (cnt[i % k].empty() || *cnt[i % k].begin() > i) {
			cout << 0;
			return 0;
		}
		cnt[i % k].erase(cnt[i % k].begin());
	}
	cout << 1;
}