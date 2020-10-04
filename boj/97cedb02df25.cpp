#include <iostream>
#include <vector>
using namespace std;

int arr[101];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> arr[i];

	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		bool vis[101] = {};
		int t = i;
		while (!vis[t]) {
			vis[t] = 1;
			t = arr[t];
		}
		if (t == i) ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int u: ans) cout << u << '\n';
}