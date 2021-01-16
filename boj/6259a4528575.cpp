#include <iostream>
using namespace std;

int bi, tri;

void binary_search(long long left, long long right, int cnt) {
	if (right < left) return;
    long long mid = (left + right) / 2;
	bi = max(bi, cnt + 1);
	if (mid - 1 - left > right - mid - 1) binary_search(left, mid - 1, cnt + 1);
    else binary_search(mid + 1, right, cnt + 1);
}

void ternary_search(long long left, long long right, int cnt) {
	if (right < left) return;
    long long left_third = left + (right - left) / 3;
    long long right_third = right - (right - left) / 3;
	if (left_third == right_third) {
		tri = max(tri, cnt + 1);
		return;
	}
	tri = max(tri, cnt + 2);
	long long len[3] = {left_third - 1 - left, right_third - left_third - 2, right - right_third - 1};
	long long m = -1, ind;
	for (int i = 0; i < 3; ++i) {
		if (len[i] > m) {
			m = len[i];
			ind = i;
		}
	}
	if (ind == 0) ternary_search(left, left_third - 1, cnt + 2);
	else if (ind == 1) ternary_search(left_third + 1, right_third - 1, cnt + 2);
	else ternary_search(right_third + 1, right, cnt + 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	while (q--) {
		long long n;
		cin >> n;
		bi = 0; tri = 0;
		binary_search(0, n - 1, 0);
		ternary_search(0, n - 1, 0);
		cout << bi - 1 << ' ' << tri - 1 << '\n';
	}
}