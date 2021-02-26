#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	int mxa = -1, mxb = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mxa = max(mxa, a[i]);
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		mxb = max(mxb, b[i]);
	}

	if (mxa != mxb) {
		cout << -1;
		return 0;
	}

	long long mi = 0, mx = 0;
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());

	int i = 0, j = 0;
	while (i < n || j < m) {
		if (i >= n) {
			while (j < m) mi += b[j++];
		}
		else if (j >= m) {
			while (i < n) mi += a[i++];
		}
		else {
			if (a[i] == b[j]) {
				mi += a[i];
				i++; j++;
			}
			else {
				if (a[i] > b[j]) mi += a[i++];
				else mi += b[j++];
			}
		}
	}

	j = m - 1;
	long long sum = 0, cnt = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (j >= 0 && b[j] < a[i]) {
			sum += b[j];
			cnt++;
			j--;
		}
		mx += sum + (m - cnt) * a[i];
	}
	cout << mi << ' ' << mx;
}