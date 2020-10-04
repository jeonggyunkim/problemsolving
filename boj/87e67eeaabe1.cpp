#include <iostream>
#include <map>
#include <vector>
using namespace std;

char win[110][110];
char ans[110][110];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; ++i) cin >> win[i];

	map<string, vector<string>> mp;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (win[i][j] == '+') {
				int k, l;
				string name;
				bool start = 0;
				for (k = i + 1; win[k][j] != '+'; ++k);
				for (l = j + 1; win[i][l] != '+'; ++l) {
					if (start) {
						if (win[i][l] != '|') name += win[i][l];
					}
					if (win[i][l] == '|') {
						start = !start;
					}
				}

				vector<string> str;
				for (int x = i; x <= k; ++x) {
					string s;
					for (int y = j; y <= l; ++y) s += win[x][y];
					str.push_back(s);
				}

				win[k][j] = '.';
				win[i][l] = '.';
				win[k][l] = '.';

				mp[name] = str;
			}
			ans[i][j] = '.';
		}
	}

	int x = 0, y = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		for (int i = 0; i < it->second.size(); ++i) {
			for (int j = 0; j < it->second[i].size(); ++j) {
				ans[x + i][y + j] = it->second[i][j];
			}
		}
		x++; y++;
	}

	for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}