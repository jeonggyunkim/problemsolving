#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	int cnt[10001] = {};
	for (int i = 0; i < n; ++i) {
		cin >> t;
		cnt[t]++;
	}

	for (int i = 1; i <= 10000; ++i) {
		for (int j = 0; j < cnt[i]; ++j) cout << i << '\n';
	}
}