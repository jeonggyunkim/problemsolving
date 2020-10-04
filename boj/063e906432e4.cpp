#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end());

	vector<int> inc(n, 1);
	int ans = 0;
	inc[0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i].second > arr[j].second) inc[i] = max(inc[i], inc[j] + 1);
		}
		ans = max(ans, inc[i]);
	}
	cout << n - ans;
}