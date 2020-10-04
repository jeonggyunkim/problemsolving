#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	set<int> s;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		s.insert(t);
	}

	auto it = s.end();
	int max = *(--it);
	bool two = false;
	int a, b;
	for (auto it = s.begin(); it != s.end(); ++it) {
		bool mask[32] = {};
		int i = 0, sum = 1;
		while (*it + sum <= max) {
			if (s.find(*it + sum) != s.end()) mask[i] = 1;
			sum <<= 1; ++i;
		}
		for (int i = 0; i < 31; ++i) {
			if (!two && mask[i]) {
				two = true;
				a = *it, b = i;
			}
			if (mask[i] && mask[i + 1]) {
				cout << 3 << '\n';
				cout << *it << ' ';
				int sum = 1;
				for (int j = 0; j < i; ++j) sum <<= 1;
				cout << *it + sum << ' ';
				cout << *it + (sum << 1) << ' ';
				return 0;
			}
		}
	}
	if (two) {
		cout << 2 << '\n';
		cout << a << ' ';
		int sum = 1;
		for (int j = 0; j < b; ++j) sum <<= 1;
		cout << a + sum << ' ';
	}
	else {
		cout << 1 << '\n';
		cout << *(s.begin());
	}
}