#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	vector<int> pos, neg;
	int zero = 0;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t < 0) neg.push_back(t);
		else if (t > 0) pos.push_back(t);
		else zero++;
	}

	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end(), greater<int>());

	for (int i = neg.size() - 2; i >= (int)(neg.size() & 1); i -= 2) cout << neg[i] << ' ';
	for (int i = 1 - (neg.size() & 1); i < neg.size(); i += 2) cout << neg[i] << ' ';

	while (zero--) cout << 0 << ' ';

	for (int i = pos.size() - 1; i >= (int)(1 - (pos.size() & 1)); i -= 2) cout << pos[i] << ' ';
	for (int i = (pos.size() & 1); i < pos.size(); i += 2) cout << pos[i] << ' ';
}