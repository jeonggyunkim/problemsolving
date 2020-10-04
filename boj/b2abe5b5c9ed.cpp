#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, t;
		cin >> n;

		vector<vector<int>> seg;
		vector<int> tmp;
		bool z = 0;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			if (t) tmp.push_back(t);
			else {
				z = 1;
				if (!tmp.empty()) {
					seg.push_back(tmp);
					tmp.clear();
				}
			}
		}
		if (!tmp.empty()) seg.push_back(tmp);

		int real_ans = -987;
		if (z) real_ans = 0;

		int ans = 0, yang = 0;
		for (int i = 0; i < seg.size(); ++i) {
			int two_cnt = 0, neg_cnt = 0;
			for (int j = 0; j < seg[i].size(); ++j) {
				if (abs(seg[i][j]) == 2) two_cnt++;
				if (seg[i][j] < 0) neg_cnt++;
			}

			if (neg_cnt % 2 == 0) {
				yang = 1;
				ans = max(ans, two_cnt);
			}
			else {
				if (seg[i].size() == 1) {
					real_ans = max(real_ans, seg[i][0]);
					continue;
				}
				int a = 0, b = 0;
				for (int j = 0; j < seg[i].size(); ++j) {
					if (abs(seg[i][j]) == 2) a++;
					if (seg[i][j] < 0) break;
				}
				for (int j = seg[i].size() - 1; j >= 0; --j) {
					if (abs(seg[i][j]) == 2) b++;
					if (seg[i][j] < 0) break;
				}
				yang = 1;
				ans = max(ans, two_cnt - min(a, b));
			}
		}
		if (yang) {
			int p = 1;
			for (int i = 0; i < ans; ++i) {
				p = (p * 2) % 1000000007;
			}
			cout << p << '\n';
		}
		else {
			cout << real_ans << '\n';
		}
	}
}