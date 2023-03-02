#include <iostream>
#include <algorithm>
using namespace std;

pair<string, string> arr[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	cout << arr[k - 1].first << ' ' << arr[k - 1].second;
}