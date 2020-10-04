#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	vector<string> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (string& u: arr) cout << u;
}