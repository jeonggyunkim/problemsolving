#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> ii;

string edge[300];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) cin >> edge[i];

		int ans = 0;
		vector<ii> ans_edge;

		vector<bool> put(n, 0);
		vector<vector<int>> con;
		for (int i = 0; i < n; ++i) {
			if (put[i]) continue;

			put[i] = 1;
			con.push_back(vector<int>(1, i));

			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				if (edge[i][j] == '1' && edge[j][i] == '1') {
					con.back().push_back(j);
					put[j] = 1;
				}
			}
			if (con.back().size() > 1) ans += con.back().size();
		}

		int t = con.size();
		for (int i = 0; i < t; ++i) {
			for (int j = 0; j < t; ++j) {
				if (i == j) continue;
				if (edge[con[i][0]][con[j][0]] == '1') {
					bool exist = true;
					for (int k = 0; k < t; ++k) {
						if (k == i || k == j) continue;
						if (edge[con[i][0]][con[k][0]] == '1' && edge[con[k][0]][con[j][0]] == '1') {
							exist = 0;
							break;
						}
					}
					if (exist) {
						ans++;
						ans_edge.push_back(ii(con[i][0], con[j][0]));
					}
				}
			}
		}

		cout << ans << '\n';
		for (ii u: ans_edge) {
			cout << u.first + 1 << ' ' << u.second + 1 << '\n';
		}

		for (int i = 0; i < con.size(); ++i) {
			if (con[i].size() > 1) {
				for (int j = 0; j < con[i].size(); ++j) cout << con[i][j] + 1 << ' ' << con[i][(j + 1) % con[i].size()] + 1 << '\n';
			}
		}
		cout << '\n';
	}
}