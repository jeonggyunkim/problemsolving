#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t, k = 0, sum = 0;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		k = max(k, arr[i]);
		sum += arr[i];
	}

	while (1) {
		if (k * n - sum > sum) break;
		k++;
	}

	cout << k;
}