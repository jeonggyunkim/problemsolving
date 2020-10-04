#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	vector<int> pos, neg;
	bool z = 0;
	while (n--) {
		cin >> t;
		if (t > 0) pos.push_back(t);
		else if (t < 0) neg.push_back(-t);
		else z = 1;
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	int ans = -987654321;
	if (pos.size() >= 2) {
		int p = pos.size();
		if (pos.size() > 2) {
			ans = pos[p - 1] * pos[p - 2] * pos[p - 3];
		}
		else {
			ans = pos[p - 1] * pos[p - 2];
		}
	}

	if (neg.size() >= 2) {
		int p = neg.size();
		int loc = neg[p - 1] * neg[p - 2];
		if (pos.size()) loc *= pos[pos.size() - 1];
		ans = max(ans, loc);
	}

	if (z) ans = max(ans, 0);
	if (ans < 0) {
		ans = -pos[0] * neg[0];
	}
	cout << ans;
}