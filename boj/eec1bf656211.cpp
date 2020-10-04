#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

vector<int> h, p;

int dir[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		if (h[a] > h[b]) p[b] = a;
		else p[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, d;
		cin >> a >> b >> d;

		int size = a * b;

		h = vector<int>(size);
		p = vector<int>(size);
		vector<bool> add(size, 0);
		vector<ii> to_sort(size);
		for (int i = 0; i < size; ++i) p[i] = i;
		for (int i = 0; i < size; ++i) {
			cin >> h[i];
			to_sort[i] = ii(h[i], i);
		}
		sort(to_sort.begin(), to_sort.end(), greater<ii>());

		int i = 0, j = 0, ans = 0;
		while (i < size) {
			while (j < size && to_sort[j].first + d > to_sort[i].first) {
				int loc = to_sort[j].second;
				add[loc] = 1;
				int x = loc / b, y = loc % b;
				for (int k = 0; k < 4; ++k) {
					int xx = x + dir[k][0], yy = y + dir[k][1];
					if (xx < 0 || xx >= a || yy < 0 || yy >= b) continue;
					if (add[xx * b + yy]) merge(loc, xx * b + yy);
				}
				++j;
			}
			if (h[to_sort[i].second] == h[find(to_sort[i].second)]) ans++;
			++i;
		}
		cout << ans << '\n';
	}
}