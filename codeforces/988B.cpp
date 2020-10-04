#include <bits/stdc++.h>
using namespace std;

bool comp(string& a, string& b) {
	return a.size() < b.size();
}

bool issub(string& a, string& b) {
	for (int i = 0; i < b.size() - a.size() + 1; ++i) {
		if (a.compare(b.substr(i, a.size())) == 0) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string arr[101];
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr, arr + n, comp);

	bool brk = false;
	for (int i = 1; i < n; ++i) {
		if (!issub(arr[i - 1], arr[i])) {
			brk = true;
			break;
		}
	}
	if (brk) cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		for (int i = 0; i < n; ++i) {
			cout << arr[i] << '\n';
		}
	}
}