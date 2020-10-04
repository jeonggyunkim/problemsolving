#include <iostream>
using namespace std;

char arr[30][30];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; ++i) cin >> arr[i];

		bool blk[30] = {};
		for (int i = 0; i < r; ++i) {
			bool blank = 1;
			for (int j = 0; j < c; ++j) {
				if (arr[i][j] != '?') blank = 0;
			}
			if (!blank) {
				for (int j = 0; j < c; ++j) {
					if (arr[i][j] == '?') {
						int left = j - 1, right = j + 1;
						while (left >= 0) {
							if (arr[i][left] != '?') {
								arr[i][j] = arr[i][left];
								goto end;
							}
							left--;
						}
						while (right < c) {
							if (arr[i][right] != '?') {
								arr[i][j] = arr[i][right];
								goto end;
							}
							right++;
						}
						end:;
					}
				}
			}
			else blk[i] = 1;
		}

		for (int i = 0; i < r; ++i) {
			if (blk[i]) {
				int up = i - 1, down = i + 1;
				while (up >= 0) {
					if (!blk[up]) {
						for (int j = 0; j < c; ++j) arr[i][j] = arr[up][j];
						goto end2;
					}
					up--;
				}
				while (down < r) {
					if (!blk[down]) {
						for (int j = 0; j < c; ++j) arr[i][j] = arr[down][j];
						goto end2;
					}
					down++;
				}
				end2:;
				blk[i] = 0;
			}
		}

		cout << "Case #" << test << ":\n";
		for (int i = 0; i < r; ++i) cout << arr[i] << '\n';
	}
}