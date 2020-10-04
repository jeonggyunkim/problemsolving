#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int d, g;
	cin >> d >> g;

	vector<iii> box;
	int a, b, c;
	for (int i = 0; i < g; ++i) {
		cin >> a >> b >> c;
		box.push_back(iii(a, b, c));
	}

	sort(box.begin(), box.end());
	vector<int> h(d, -1);
	h[0] = 10;

	int time = 0;
	for (int i = 0; i < g; ++i) {
		int m = -1, dur = get<0>(box[i]) - time;

		for (int i = 0; i < d; ++i) {
			m = max(m, h[i]);
			if (h[i] >= dur) h[i] -= dur;
			else h[i] = -1;
		}

		bool alive = 0;
		for (int j = d - 1; j >= 0; --j) {
			if (h[j] != -1) {
				alive = 1;

				if (j + get<2>(box[i]) >= d) {
					cout << time + dur;
					return 0;
				}
				else {
					h[j + get<2>(box[i])] = max(h[j + get<2>(box[i])], h[j]);
				}
				h[j] += get<1>(box[i]);
			}
		}
		if (!alive) {
			cout << time + m;
			return 0;
		}
		time += dur;
	}

	int m = -1;
	for (int i = 0; i < d; ++i) m = max(m, h[i]);
	cout << time + m;
}