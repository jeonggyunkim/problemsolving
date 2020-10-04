#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, string> is;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> name(4);
	map<string, double> ans;

	vector<string> a(6), b(6);
	vector<double> w(6), d(6), l(6);

	for (int i = 0; i < 4; ++i) {
		cin >> name[i];
		ans[name[i]] = 0.0;
	}

	for (int i = 0; i < 6; ++i) {
		cin >> a[i] >> b[i] >> w[i] >> d[i] >> l[i];
	}

	int res[6] = {};
	for (res[0] = 0; res[0] < 3; ++res[0])
	for (res[1] = 0; res[1] < 3; ++res[1])
	for (res[2] = 0; res[2] < 3; ++res[2])
	for (res[3] = 0; res[3] < 3; ++res[3])
	for (res[4] = 0; res[4] < 3; ++res[4])
	for (res[5] = 0; res[5] < 3; ++res[5]) {
		double prob = 1.0;
		for (int i = 0; i < 6; ++i) {
			if (res[i] == 0) prob *= w[i];
			else if (res[i] == 1) prob *= d[i];
			else prob *= l[i];
		}
		if (prob == 0.0) continue;
		map<string, int> score;
		for (int i = 0; i < 4; ++i) score[name[i]] = 0;
		for (int i = 0; i < 6; ++i) {
			if (res[i] == 0) score[a[i]] += 3;
			else if (res[i] == 1) {
				score[a[i]] += 1;
				score[b[i]] += 1;
			}
			else score[b[i]] += 3;
		}

		vector<vector<string>> board(13);
		for (auto it = score.begin(); it != score.end(); ++it) {
			board[it->second].push_back(it->first);
		}

		int team = 2;
		for (int i = 12; i >= 0; --i) {
			if (team <= 0) break;
			int now = board[i].size();
			for (int j = 0; j < now; ++j) {
				ans[board[i][j]] += prob * min(team, now) / now;
			}
			team -= now;
		}
	}

	cout.precision(10);
	for (int i = 0; i < 4; ++i) {
		cout << ans[name[i]] << '\n';
	}
}