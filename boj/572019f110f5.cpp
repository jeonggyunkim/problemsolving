#include <iostream>
#include <map>
using namespace std;

string what[16];

int dist(int i, int j) {
	int ret = 0;
	for (int k = 0; k < 4; ++k) {
		if (what[i][k] != what[j][k]) ret++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	string s;
	while (tc--) {
		int n;
		cin >> n;
		
		map<string, int> mp;
		int cnt[16] = {};
		while (n--) {
			cin >> s;
			if (!mp.count(s)) {
				what[mp.size()] = s;
				mp[s] = mp.size();
			}
			cnt[mp[s]]++;
		}

		int ans = 9999;
		for (int i = 0; i < 16; ++i) {
			for (int j = 0; j < 16; ++j) {
				for (int k = 0; k < 16; ++k) {
					int cnt_real[16] = {};
					cnt_real[i]++;
					cnt_real[j]++;
					cnt_real[k]++;
					bool pos = 1;
					for (int l = 0; l < 16; ++l) {
						if (cnt_real[l] > cnt[l]) pos = 0;
					}
					if (pos) {
						ans = min(ans, dist(i, j) + dist(j, k) + dist(k, i));
					}
				}
			}
		}
		cout << ans << '\n';
	}
}