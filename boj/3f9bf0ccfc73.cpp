#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string& a, string& b) {
	int n = max(a.size(), b.size());
	for (int i = 0; i < n; ++i) {
		if (a[i % a.size()] != b[i % b.size()]) return a[i % a.size()] < b[i % b.size()];
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr.begin(), arr.end(), comp);

	if (arr[n - 1] == "0") cout << 0;
	else {
		for (int i = n - 1; i >= 0; --i) cout << arr[i];
	}
}