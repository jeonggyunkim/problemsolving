#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> pac(n);
	for (int i = 0; i < n; ++i) {
		cin >> pac[i].first;
		pac[i].second = i + 1;
	}

	if (n == 1 || (n == 2 && pac[0].first == pac[1].first)) {
		cout << -1;
		return 0;
	}
	sort(pac.begin(), pac.end());
	cout << 1 << '\n' << pac[0].second;
}