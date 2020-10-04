#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<int, ii> s;

	int n;
	cin >> n;

	int k, sum;
	int arr[200000];
	for (int i = 0; i < n; ++i) {
		cin >> k;
		sum = 0;
		for (int j = 0; j < k; ++j) {
			cin >> arr[j];
			sum += arr[j];
		}
		for (int j = 0; j < k; ++j) {
			if (s.find(sum - arr[j]) != s.end()) {
				if (s[sum - arr[j]].first == i) continue;
				else {
					cout << "YES" << '\n';
					cout << s[sum - arr[j]].first + 1 << ' ';
					cout << s[sum - arr[j]].second + 1 << '\n';
					cout << i + 1 << ' ';
					cout << j + 1 << '\n';
					return 0;
				}
			}
			else s[sum - arr[j]] = ii(i, j);
		}
	}
	cout << "NO" << '\n';
}