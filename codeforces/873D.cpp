#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> ans;
int k, call = 1, cnt = 1;

void mergesort(int l, int r) {
	if (r - l == 1) {
		ans[l] = cnt++;
		return;
	}
	if (call < k) {
		int mid = (l + r) / 2;
		call += 2;
		mergesort(mid, r);
		mergesort(l, mid);
	}
	else {
		for (int i = l; i < r; ++i) ans[i] = cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> k;
	ans.resize(n);

	if (k % 2 == 0) {
		cout << -1;
		return 0;
	}
	mergesort(0, n);

	if (call < k) {
		cout << -1;
		return 0;
	}

	for (int u: ans) {
		cout << u << ' ';
	}
}