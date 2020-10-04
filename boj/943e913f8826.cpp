#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i) cin >> arr[i];

	map<int, int> m;
	for (int i = n - 1; i >= 0; --i) {
		if (m.count(arr[i] + 1)) m[arr[i]] = m[arr[i] + 1] + 1;
		else m[arr[i]] = 1;
	}

	int ans = -1;
	for (auto it = m.begin(); it != m.end(); ++it) {
		ans = max(ans, it->second);
	}
	cout << ans;
}