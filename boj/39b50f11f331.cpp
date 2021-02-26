#include <iostream>
#define INF 1987654321
using namespace std;

int x[12], y[12];
int output[12];
int n, ans;
int p[12];

void rec(int i) {
	if (i == n) {
		bool inf = 0;
		for (int j = 0; j < n; ++j) {
			int start = j, now = j;
			do {
				now = output[p[now]];
			} while (now != -1 && now != start);
			if (now == start) inf = 1;
		}
		if (inf) ans++;
		return;
	}
	if (p[i] != -1) {
		rec(i + 1);
		return;
	}
	for (int j = i + 1; j < n; ++j) {
		if (p[j] == -1) {
			p[j] = i;
			p[i] = j;
			rec(i + 1);
			p[i] = -1;
			p[j] = -1;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		output[i] = -1;
		p[i] = -1;
	}

	for (int i = 0; i < n; ++i) {
		int m = INF;
		for (int j = 0; j < n; ++j) {
			if (y[i] == y[j] && x[j] > x[i] && x[j] < m) {
				output[i] = j;
				m = x[j];
			}
		}
	}

	rec(0);
	cout << ans;
}