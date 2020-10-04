#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l;
	cin >> l;

	vector<int> arr(l);
	for (int& u: arr) cin >> u;

	long long ans = 0, ans2 = 0;
	for (int d = 1; d <= l; ++d) {
		long long sum = 0;
		for (int i = d - 1; i < l; i += d) sum += arr[i];
		if (sum > ans) {
			ans = sum;
			ans2 = d;
		}
	}
	cout << ans2 << ' ' << ans;
}