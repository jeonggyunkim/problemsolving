#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int t;
	multiset<int> ms;
	cin >> t;
	ms.insert(t);

	for (int i = 1; i < n; ++i) {
		cin >> t;
		if (*ms.begin() >= t) ms.insert(t);
		else {
			auto it = ms.lower_bound(t);
			it--;
			ms.erase(it);
			ms.insert(t);
		}
	}
	cout << ms.size() << '\n';
}