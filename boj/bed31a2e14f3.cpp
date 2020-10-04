#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct s {
	int c, s, t, i;
};

bool comp1(s& a, s& b) {
	if (a.c != b.c) return a.c < b.c;
	return a.s < b.s;
}

bool comp2(s& a, s& b) {
	if (a.s != b.s) return a.s < b.s;
	return a.c < b.c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<s> arr(n);
	vector<int> ans(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].c >> arr[i].s;
		arr[i].t = 0;
		arr[i].i = i;
	}

	sort(arr.begin(), arr.end(), comp1);

	int cnt = 0, t = 0;
	for (int i = 0; i < n; ++i) {
		if (i != 0 && arr[i].c == arr[i - 1].c) {
			if (arr[i].s == arr[i - 1].s) arr[i].t = arr[i - 1].t;
			else arr[i].t = cnt;
			cnt += arr[i].s;
		}
		else {
			arr[i].t = 0;
			cnt = arr[i].s;
		}
	}

	sort(arr.begin(), arr.end(), comp2);

	cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i != 0 && arr[i].s == arr[i - 1].s) {
			t += arr[i].s;
			ans[arr[i].i] = cnt - arr[i].t;
		}
		else {
			cnt += t;
			t = arr[i].s;
			ans[arr[i].i] = cnt - arr[i].t;
		}
	}

	for (int u: ans) cout << u << '\n';
}