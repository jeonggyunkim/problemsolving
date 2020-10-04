#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int x[1000];
int y[1000];
int h[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> h[i];
	}

	int px = -INF, mx = -INF;
	int py = -INF, my = -INF;

	for (int i = 0; i < n; ++i) {
		px = max(px, h[i] - x[i]);
		mx = max(mx, h[i] + x[i]);
		py = max(py, h[i] - y[i]);
		my = max(my, h[i] + y[i]);
	}

	int ax = (mx - px) / 2;
	int ay = (my - py) / 2;

	cout << ax << ' ' << ay << ' ' << max({ax + px, -ax + mx, ay + py, -ay + my});
}