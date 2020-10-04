#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end());

	int a, b, c, d;
	while (q--) {
		cin >> a >> b >> c >> d;
		int cnt = 0;
		for (int i = lower_bound(arr.begin(), arr.end(), ii(a, -1)) - arr.begin(); i < n && arr[i].first <= b; ++i) {
			if (arr[i].second >= c && arr[i].second <= d) cnt++;
		}
		cout << cnt << '\n';
	}
}