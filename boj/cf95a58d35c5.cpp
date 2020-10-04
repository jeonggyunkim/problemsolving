#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w;
	cin >> n >> w;
	vector<int> three, five;

	int t, s;
	while (n--) {
		cin >> t >> s;
		if (t == 3) three.push_back(s);
		else five.push_back(s);
	}

	sort(three.rbegin(), three.rend());
	sort(five.rbegin(), five.rend());
	vector<long long> st(three.size() + 1, 0), sf(five.size() + 1, 0);

	for (int i = 0; i < three.size(); ++i) {
		st[i + 1] = st[i] + three[i];
	}
	for (int i = 0; i < five.size(); ++i) {
		sf[i + 1] = sf[i] + five[i];
	}

	long long ans = 0;
	for (int i = 0; i <= five.size(); ++i) {
		if (w - 5 * i < 0) break;
		int j = min((w - 5 * i) / 3, (int)three.size());
		ans = max(ans, sf[i] + st[j]);
	}
	cout << ans;
}