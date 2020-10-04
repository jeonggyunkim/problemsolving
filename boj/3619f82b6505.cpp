#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t, d;
	cin >> n;

	map<int, int> arr;
	cin >> t;
	arr[t] = 0;
	cout << 0 << '\n';

	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		cin >> t;
		auto up = arr.upper_bound(t);
		auto low = up; low--;
		if (up == arr.begin()) d = up->second;
		else if (up == arr.end()) d = low->second;
		else d = max(low->second, up->second);
		arr[t] = d + 1;
		ans += d + 1;
		cout << ans << '\n';
	}
}