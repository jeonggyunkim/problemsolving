#include <iostream>
#include <vector>
#include <memory.h>
#define INF 987654321
using namespace std;

int n;
vector<vector<int>> ver, hor;

bool black_and[20], white_and[20];

int counter;

bool valid(vector<int>& note, int s) {
	for (int i = 0; i < s; ++i) {
		if (black_and[i] && note[i] == 0) return 1;
		if (white_and[i] && note[i] == 1) return 1;
	}
	for (int i = s; i < note.size(); ++i) {
		if (black_and[i] || white_and[i]) return 1;
	}
	return 0;
}

void solve_line(int s, int d, vector<int>& line, vector<int>& note, vector<int>& list, int left) {
	if (d == list.size()) {
		counter++;
		for (int i = s; i < line.size(); ++i) {
			if (line[i] == 1) return;
		}
		for (int i = 0; i < note.size(); ++i) {
			if (note[i] == 0) {
				black_and[i] = 0;
			}
			else {
				white_and[i] = 0;
			}
		}
		return;
	}
	for (int i = s; i + left + list.size() - d < line.size() + 2; ++i) {
		int num = list[d];
		bool pos = 1;
		for (int j = 0; j < num; ++j) {
			if (line[i + j] == 2) {
				pos = 0;
				break;
			}
		}
		if (i + num < line.size() && line[i + num] == 1) pos = 0;
		if (pos) {
			for (int j = 0; j < num; ++j) note[i + j] = 1;
			if (valid(note, i + num + 1)) solve_line(i + num + 1, d + 1, line, note, list, left - num);
			for (int j = 0; j < num; ++j) note[i + j] = 0;
		}
		if (line[i] == 1) break;
	}
	return;
}

int vertical(int i, int board[20][20], vector<int>& checked) {
	counter = 0;

	vector<int> line(n - i);
	vector<int> note(n - i, 0);
	for (int j = 0; j < n - i; ++j) {
		black_and[j] = 1;
		white_and[j] = 1;
	}
	for (int j = 0; j < n - i; ++j) {
		line[j] = board[i][j];
	}
	int sum = 0;
	for (int u: ver[i]) sum += u;
	solve_line(0, 0, line, note, ver[i], sum);
	if (black_and[0] && white_and[0]) return -1;
	int changed = 0;
	for (int j = 0; j < n - i; ++j) {
		if (black_and[j] && line[j] == 0) {
			board[i][j] = 1;
			checked[j + n] = 0;
			changed = 1;
		}
		if (white_and[j] && line[j] == 0) {
			board[i][j] = 2;
			checked[j + n] = 0;
			changed = 1;
		}
	}
	return changed;
}

int horizontal(int i, int board[20][20], vector<int>& checked) {
	counter = 0;

	vector<int> line(n - i);
	vector<int> note(n - i, 0);
	for (int j = 0; j < n - i; ++j) {
		black_and[j] = 1;
		white_and[j] = 1;
	}
	for (int j = 0; j < n - i; ++j) {
		line[j] = board[j][i];
	}
	int sum = 0;
	for (int u: hor[i]) sum += u;
	solve_line(0, 0, line, note, hor[i], sum);
	if (black_and[0] && white_and[0]) return -1;
	int changed = 0;
	for (int j = 0; j < n - i; ++j) {
		if (black_and[j] && line[j] == 0) {
			board[j][i] = 1;
			checked[j] = 0;
			changed = 1;
		}
		if (white_and[j] && line[j] == 0) {
			board[j][i] = 2;
			checked[j] = 0;
			changed = 1;
		}
	}
	return changed;
}

bool solve(int board[20][20]) {
	int original_board[20][20];
	memcpy(original_board, board, sizeof(original_board));

	vector<int> checked(2 * n, 0);

	int now = 0, success = 0;
	while (true) {
		if (!checked[now]) {
			if (now < n) {
				int ret = vertical(now, board, checked);
				if (ret == 1) success = 0;
				else if (ret == 0) success++;
				else {
					memcpy(board, original_board, sizeof(original_board));
					return 0;
				}
			}
			else {
				int ret = horizontal(now - n, board, checked);
				if (ret == 1) success = 0;
				else if (ret == 0) success++;
				else {
					memcpy(board, original_board, sizeof(original_board));
					return 0;
				}
			}
			checked[now] = counter;
		}
		else success++;
		if (success == 2 * n) break;
		now = (now + 1) % (2 * n);
	}

	int mi = INF, x, y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			if (board[i][j] == 0) {
				if (checked[i] + checked[j] < mi) {
					mi = checked[i] + checked[j];
					x = i, y = j;
				}
			}
		}
	}
	if (mi == INF) return 1;
	else {
		board[x][y] = 1;
		if (!solve(board)) {
			board[x][y] = 2;
			if (!solve(board)) return 0;
		}
		return 1;
	}
}

int main() {
	cin >> n;

	ver.resize(n);
	hor.resize(n);
	for (int i = 0; i < 2 * n; ++i) {
		int sz, t;
		cin >> sz;
		while (sz--) {
			cin >> t;
			if (i < n) ver[i].push_back(t);
			else hor[i - n].push_back(t);
		}
	}

	int board[20][20] = {};
	if (!solve(board)) {
		cout << "No Answer";
	}
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - i; ++j) {
				if (board[i][j] == 1) cout << "1 ";
				else cout << "0 ";
			}
			cout << '\n';
		}
	}
}