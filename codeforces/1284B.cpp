#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	ll as = 0;
	vector<int> big;
	vector<int> small(1000001, 0);
	for (int i = 0; i < n; ++i) {
		int l;
		cin >> l;
		vector<int> arr(l);
		cin >> arr[0];
		int mini = arr[0], maxi = arr[0];
		bool isas = 0;
		for (int j = 1; j < l; ++j) {
			cin >> arr[j];
			if (arr[j] > mini) isas = 1;
			else mini = arr[j];
			maxi = max(maxi, arr[j]);
		}
		if (isas) as++;
		else {
			big.push_back(maxi);
			small[mini]++;
		}
	}

	ll ans = 0;
	ans += as * as;
	ans += 2LL * as * (n - as);

	for (int i = 1; i <= 1000000; ++i) {
		small[i] += small[i - 1];
	}
	for (int u: big) {
		if (u != 0) ans += small[u - 1];
	}
	cout << ans;
}