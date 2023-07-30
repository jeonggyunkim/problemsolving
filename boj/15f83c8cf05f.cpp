#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

char board[11][11];
int cnt_h[10], cnt_v[10];
int ans[3][2];

bool inc_seq(int cnt[], int d, int v) {
	for (int i = 0; i < 10; ++i) {
		for (int j = i; j < 10; ++j) {
			int arr[10] = {};
			for (int k = i; k <= j; ++k) {
				arr[k] = (k - i) * d + 1;
			}
			int same = 1;
			for (int k = 0; k < 10; ++k) {
				if (cnt[k] != arr[k]) same = 0;
			}
			if (same) {
				ans[0][v] = i;
				ans[1][v] = ans[2][v] = j;
				return 1;
			}

			memset(arr, 0, sizeof(arr));
			for (int k = i; k <= j; ++k) {
				arr[k] = (j - k) * d + 1;
			}
			same = 1;
			for (int k = 0; k < 10; ++k) {
				if (cnt[k] != arr[k]) same = 0;
			}
			if (same) {
				ans[0][v] = ans[1][v] = i;
				ans[2][v] = j;
				return 1;
			}
		}
	}
	return 0;
}

bool sym_seq(int cnt[], int v) {
	for (int i = 0; i < 10; ++i) {
		for (int j = i; j < 10; ++j) {
			if (2 * j - i >= 10) continue;
			int arr[10] = {};
			for (int k = i; k <= j; ++k) {
				arr[k] = k - i + 1;
			}
			for (int k = j; k <= 2 * j - i; ++k) {
				arr[k] = 2 * j - i - k + 1;
			}
			int same = 1;
			for (int k = 0; k < 10; ++k) {
				if (cnt[k] != arr[k]) same = 0;
			}
			if (same) {
				ans[0][v] = i;
				ans[1][v] = j;
				ans[2][v] = 2 * j - i;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 0; i < 10; ++i) {
		cin >> board[i];
		for (int j = 0; j < 10; ++j) {
			if (board[i][j] == '1') {
				cnt_v[i]++;
				cnt_h[j]++;
			}
		}
	}

	if (inc_seq(cnt_v, 1, 0) && inc_seq(cnt_h, 1, 1)) {
		if (ans[1][0] == ans[2][0] && ans[1][1] == ans[2][1]) swap(ans[0][1], ans[1][1]);
		else if (ans[0][0] == ans[1][0] && ans[0][1] == ans[1][1]) swap(ans[1][1], ans[2][1]);
		for (int i = 0; i < 3; ++i) cout << ans[i][0] + 1 << ' ' << ans[i][1] + 1 << '\n';
	}
	else if (sym_seq(cnt_v, 0) && inc_seq(cnt_h, 2, 1)) {
		if (ans[1][1] == ans[2][1]) swap(ans[0][1], ans[1][1]);
		else swap(ans[1][1], ans[2][1]);
		for (int i = 0; i < 3; ++i) cout << ans[i][0] + 1 << ' ' << ans[i][1] + 1 << '\n';
	}
	else if (sym_seq(cnt_h, 1) && inc_seq(cnt_v, 2, 0)) {
		if (ans[1][0] == ans[2][0]) swap(ans[0][1], ans[1][1]);
		else swap(ans[1][1], ans[2][1]);
		for (int i = 0; i < 3; ++i) cout << ans[i][0] + 1 << ' ' << ans[i][1] + 1 << '\n';
	}
	else cout << "0\n";
}