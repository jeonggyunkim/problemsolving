#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);

	int first = -1, second = -1;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	for (int i = 0; i < n; ++i) {
		if (arr[i] >= first) {
			second = first;
			first = arr[i];
		}
		else if (arr[i] >= second) {
			second = arr[i];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] == first) cout << second << '\n';
		else cout << first << '\n';
	}
}