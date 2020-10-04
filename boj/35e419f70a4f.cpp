#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	vector<int> sum(n + 1);

	for (int i = 0; i < n; ++i) cin >> arr[i];

	sum[0] = sum[1] = 0;
	for (int i = 2; i <= n; ++i) {
		sum[i] = sum[i - 1] + abs(arr[i - 1] - arr[i - 2]);
	}

	int a, b;
	while (q--) {
		cin >> a >> b;
		cout << sum[b] - sum[a] << '\n';
	}
}