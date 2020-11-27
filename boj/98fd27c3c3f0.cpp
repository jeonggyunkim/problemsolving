#include <iostream>
#include <set>
#define N 1010
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int board[N][N];
int sum[N][N];
int min_ver[N][N];
ii pos_ver[N][N];
int min_all[N][N];
ii pos_all[N][N];

int area(int a, int b, int c, int d) {
	return sum[c - 1][d - 1] - sum[c - 1][b - 1] - sum[a - 1][d - 1] + sum[a - 1][b - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, a, b, c, d;
	cin >> m >> n >> a >> b >> c >> d;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> board[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + board[i][j];
		}
	}

	for (int i = 2; i <= n - d; ++i) {
		set<iii> st;
		for (int j = 2; j < a - c + 1; ++j) st.insert({area(i, j, i + d, j + c), {i, j}});
		for (int j = 2; j + c <= m; ++j) {
			min_ver[i][j] = st.begin()->first;
			pos_ver[i][j] = st.begin()->second;
			st.erase({area(i, j, i + d, j + c), {i, j}});
			st.insert({area(i, j + a - c - 1, i + d, j + a - 1), {i, j + a - c - 1}});
		}
	}

	for (int j = 2; j <= m - c; ++j) {
		set<iii> st;
		for (int i = 2; i < b - d + 1; ++i) st.insert({min_ver[i][j], pos_ver[i][j]});
		for (int i = 2; i + d <= n; ++i) {
			min_all[i][j] = st.begin()->first;
			pos_all[i][j] = st.begin()->second;
			st.erase({min_ver[i][j], pos_ver[i][j]});
			st.insert({min_ver[i + b - d - 1][j], pos_ver[i + b - d - 1][j]});
		}
	}

	int ans = 0;
	ii pos[2];
	for (int i = 1; i + b <= n + 1; ++i) {
		for (int j = 1; j + a <= m + 1; ++j) {
			int now = area(i, j, i + b, j + a) - min_all[i + 1][j + 1];
			if (now > ans) {
				ans = now;
				pos[0] = {i, j};
				pos[1] = pos_all[i + 1][j + 1];
			}
		}
	}
	cout << pos[0].second << ' ' << pos[0].first << '\n';
	cout << pos[1].second << ' ' << pos[1].first << '\n';
}