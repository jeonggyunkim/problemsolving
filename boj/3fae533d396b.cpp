#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	int arr[80000];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	long long ans = 0;
	vector<ii> v;
	v.push_back(ii(1 << 30, n));
	for (int i = n - 1; i >= 0; --i) {
		while (v.back().first < arr[i]) v.pop_back();
		ans += v.back().second - i - 1;
		if (v.back().first == arr[i]) v.pop_back();
		v.push_back(ii(arr[i], i));
	}

	cout << ans;
}