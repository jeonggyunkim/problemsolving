#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> pnt;
	for (int i = 0; i < n; ++i) {
		int p, l;
		cin >> p >> l;

		vector<int> arr(p);
		for (int j = 0; j < p; ++j) cin >> arr[j];

		if (p < l) pnt.push_back(1);
		else {
			sort(arr.begin(), arr.end());
			pnt.push_back(arr[p - l]);
		}
	}

	sort(pnt.begin(), pnt.end());
	int ans = 0;
	for (int u: pnt) {
		if (m >= u) {
			m -= u;
			ans++;
		}
	}
	cout << ans;
}