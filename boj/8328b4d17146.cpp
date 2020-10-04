#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> cnt(n, 0);
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		cnt[a]++;
		cnt[b]++;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] == 1) ans++;
	}

	cout << (ans + 1) / 2;
}