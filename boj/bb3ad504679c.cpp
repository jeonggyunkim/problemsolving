#include <iostream>
#define N 1000010
using namespace std;

int r, c, w;
char board[N];
int p[N], cnt[N];

int find(int i) {
	if (p[i] == i) return i;
	return p[i] = find(p[i]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		p[a] = b;
		cnt[b] += cnt[a];
	}
}

bool pos(int t) {
	int noww = w;
	for (int i = 0; i < r * c; ++i) {
		p[i] = i;
		if (board[i] == '1') cnt[i] = 1;
		else cnt[i] = 0;
	}

	for (int j = 0; j < c; ++j) {
		int mx = -1;
		for (int i = 0; i < r; ++i) {
			if (board[i * c + j] == '1') {
				if (i != 0) {
					if (board[(i - 1) * c + j] == '1') {
						merge((i - 1) * c + j, i * c + j);
					}
				}
				if (j != 0) {
					if (board[i * c + j - 1] == '1') {
						merge(i * c + j - 1, i * c + j);
					}
				}
				mx = max(mx, cnt[find(i * c + j)]);
			}
		}
		if (mx > t) {
			if (noww == 0) return 0;
			noww--;

			mx = -1;
			for (int i = 0; i < r; ++i) {
				if (board[i * c + j] == '1') {
					p[i * c + j] = i * c + j;
					cnt[i * c + j] = 1;

					if (i != 0) {
						if (board[(i - 1) * c + j] == '1') {
							merge((i - 1) * c + j, i * c + j);
						}
					}
					mx = max(mx, cnt[find(i * c + j)]);
				}
			}
			if (mx > t) return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> w;

	int low = 0, high = 0;
	for (int i = 0; i < r; ++i) {
		cin >> (&board[i * c]);
	}
	for (int i = 0; i < r * c; ++i) {
		if (board[i] == '1') high++;
	}
	if (high == 0) {
		cout << 0;
		return 0;
	}
	while (high - low != 1) {
		int mid = (low + high) / 2;
		if (pos(mid)) high = mid;
		else low = mid;
	}
	cout << high;
}