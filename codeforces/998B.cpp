#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, B;
	cin >> n >> B;

	vector<int> arr(n);
	vector<int> res;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int odd = 0, even = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] % 2 == 0) even++;
		else odd++;

		if (i % 2 == 1 && odd == even) res.push_back(abs(arr[i] - arr[i + 1]));
	}
	sort(res.begin(), res.end());

	int sum = 0;
	int i = 0;
	while (i < res.size() && res[i] + sum <= B) {
		sum += res[i];
		i++;
	}
	cout << i;
}