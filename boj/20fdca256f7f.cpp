#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int op = 0, loc;
	for (int i = 1; i < n; ++i) {
		if (arr[i - 1] > arr[i]) {
			op++;
			loc = i;
		}
	}

	if (op >= 2) cout << 0;
	else if (op == 1) {
		int ans = 0;
		if (loc == 1 || arr[loc] >= arr[loc - 2]) ans++;
		if (loc == n - 1 || arr[loc + 1] >= arr[loc - 1]) ans++;
		cout << ans;
	}
	else cout << n;
}