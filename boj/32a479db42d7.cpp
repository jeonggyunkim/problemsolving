#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int dir[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
int r, c;
vector<vector<bool>> cap;
char board[51][51];
vector<iii> todo;

void bfs(int cnum, int i, int j) {
	int vis[51][51];
	memset(vis, -1, sizeof(vis));

	queue<ii> q;
	q.push(ii(i, j));
	vis[i][j] = 0;
	while (!q.empty()) {
		ii now = q.front(); q.pop();
		for (int k = 0; k < 4; ++k) {
			int x = now.first + dir[k][0];
			int y = now.second + dir[k][1];
			if (x < 0 || x >= r || y < 0 || y >= c || board[x][y] == 'X' || vis[x][y] != -1) continue;
			q.push(ii(x, y));
			vis[x][y] = vis[now.first][now.second] + 1;
		}
	}

	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		if (board[i][j] < 0 && vis[i][j] != -1) {
			cap[cnum][-board[i][j] - 1] = 1;
			todo.push_back(iii(vis[i][j], ii(cnum, -board[i][j] - 1)));
		}
	}
}

int bm[101];
bool vis[101];

bool dfs(int a) {
	if (vis[a]) return 0;
	vis[a] = 1;

	for (int b = 0; b < cap[a].size(); ++b) {
		if (cap[a][b] == 0) continue;
		if (bm[b] == -1 || dfs(bm[b])) {
			bm[b] = a;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i) cin >> board[i];

	vector<ii> car, park;
	int cnum = 0, pnum = 0;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		if (board[i][j] == 'P') {
			pnum++;
			board[i][j] = -pnum;
		}
		if (board[i][j] == 'C') cnum++;
	}
	if (cnum == 0) {
		cout << 0;
		return 0;
	}

	cap = vector<vector<bool>>(cnum, vector<bool>(pnum, 0));

	cnum = 0;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		if (board[i][j] == 'C') {
			bfs(cnum, i, j);
			cnum++;
		}
	}

	int size = 0;
	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < cnum; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) size++;
	}

	if (size != cnum) {
		cout << -1;
		return 0;
	}

	sort(todo.begin(), todo.end());
	for (int i = todo.size() - 1; i >= 0; --i) {
		cap[todo[i].second.first][todo[i].second.second] = 0;
		if (bm[todo[i].second.second] == todo[i].second.first) {
			bm[todo[i].second.second] = -1;
			memset(vis, 0, sizeof(vis));
			if (!dfs(todo[i].second.first)) {
				cout << todo[i].first;
				return 0;
			}
		}
	}
}