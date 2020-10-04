#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	int a[3], b[3];
	while (tc--) {
		int arr[3] = {0, 1, 2};
		for (int i = 0; i < 3; ++i) cin >> a[i] >> b[i];

		int ans = INF;
		do {
			for (int mask = 0; mask < 7; ++mask) {
				for (int j = 0; j < 3; ++j) {
					if ((1 << j) & mask) swap(a[j], b[j]);
				}

				int s2[2][2] = {{a[arr[0]], 0}, {0, b[arr[0]]}};
				int s3[4][2] = {{a[arr[0]] + a[arr[1]], 0}, {a[arr[0]], b[arr[1]]}, {a[arr[1]], b[arr[0]]}, {0, b[arr[0]] + b[arr[1]]}};

				int pos[3][2];
				for (int j = 0; j < 2; ++j) {
					for (int k = 0; k < 4; ++k) {
						pos[0][0] = 0; pos[0][1] = 0;
						pos[1][0] = s2[j][0]; pos[1][1] = s2[j][1];
						pos[2][0] = s3[k][0]; pos[2][1] = s3[k][1];
						bool intersect = 0;
						for (int l = 0; l < 3; ++l) {
							if (pos[l][0] + a[arr[l]] > pos[(l + 1) % 3][0] && pos[(l + 1) % 3][0] + a[arr[(l + 1) % 3]] > pos[l][0]) {
								if (pos[l][1] + b[arr[l]] > pos[(l + 1) % 3][1] && pos[(l + 1) % 3][1] + b[arr[(l + 1) % 3]] > pos[l][1]) {
									intersect = 1;
								}
							}
						}
						if (!intersect) {
							int now = max(max(a[arr[0]], pos[1][0] + a[arr[1]]), pos[2][0] + a[arr[2]]) * max(max(b[arr[0]], pos[1][1] + b[arr[1]]), pos[2][1] + b[arr[2]]);
							if (now < ans) {
								ans = now;
							}
						}
					}
				}

				for (int j = 0; j < 3; ++j) {
					if ((1 << j) & mask) swap(a[j], b[j]);
				}
			}
		} while (next_permutation(arr, arr + 3));
		cout << ans << '\n';
	}
}