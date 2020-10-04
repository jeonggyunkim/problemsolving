#include <iostream>
using namespace std;

char board[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> board[i];

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) board[i][j] -= '0';

	long long ans = -1;
	for (int i = 1; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			long long sum[3] = {};
			for (int x = 0; x < n; ++x) for (int y = 0; y < i; ++y) sum[0] += board[x][y];
			for (int x = 0; x < n; ++x) for (int y = i; y < j; ++y) sum[1] += board[x][y];
			for (int x = 0; x < n; ++x) for (int y = j; y < m; ++y) sum[2] += board[x][y];
			ans = max(ans, sum[0] * sum[1] * sum[2]);
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			long long sum[3] = {};
			for (int x = 0; x < i; ++x) for (int y = 0; y < m; ++y) sum[0] += board[x][y];
			for (int x = i; x < j; ++x) for (int y = 0; y < m; ++y) sum[1] += board[x][y];
			for (int x = j; x < n; ++x) for (int y = 0; y < m; ++y) sum[2] += board[x][y];
			ans = max(ans, sum[0] * sum[1] * sum[2]);
		}
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			long long sum[3] = {};
			for (int x = 0; x < j; ++x) for (int y = 0; y < i; ++y) sum[0] += board[x][y];
			for (int x = 0; x < j; ++x) for (int y = i; y < m; ++y) sum[1] += board[x][y];
			for (int x = j; x < n; ++x) for (int y = 0; y < m; ++y) sum[2] += board[x][y];
			ans = max(ans, sum[0] * sum[1] * sum[2]);
		}
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			long long sum[3] = {};
			for (int x = 0; x < j; ++x) for (int y = 0; y < m; ++y) sum[0] += board[x][y];
			for (int x = j; x < n; ++x) for (int y = 0; y < i; ++y) sum[1] += board[x][y];
			for (int x = j; x < n; ++x) for (int y = i; y < m; ++y) sum[2] += board[x][y];
			ans = max(ans, sum[0] * sum[1] * sum[2]);
		}
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			long long sum[3] = {};
			for (int x = 0; x < n; ++x) for (int y = 0; y < i; ++y) sum[0] += board[x][y];
			for (int x = 0; x < j; ++x) for (int y = i; y < m; ++y) sum[1] += board[x][y];
			for (int x = j; x < n; ++x) for (int y = i; y < m; ++y) sum[2] += board[x][y];
			ans = max(ans, sum[0] * sum[1] * sum[2]);
		}
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			long long sum[3] = {};
			for (int x = 0; x < j; ++x) for (int y = 0; y < i; ++y) sum[0] += board[x][y];
			for (int x = j; x < n; ++x) for (int y = 0; y < i; ++y) sum[1] += board[x][y];
			for (int x = 0; x < n; ++x) for (int y = i; y < m; ++y) sum[2] += board[x][y];
			ans = max(ans, sum[0] * sum[1] * sum[2]);
		}
	}

	cout << ans;
}