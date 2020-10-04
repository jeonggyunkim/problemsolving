#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

char mem[20000];
char fin[20000];

char isfinished(vector<string>& board) {
	for (int i = 0; i < 3; ++i) {
		if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
		if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
	}
	if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
	if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
	for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) if (board[i][j] == '.') return 0;
	return 2;
}

int bijection(vector<string>& board) {
	int ret = 0;
	for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
		ret *= 3;
		if (board[i][j] == 'o') ret++;
		else if (board[i][j] == 'x') ret += 2;
	}
	return ret;
}

char canwin(vector<string>& board, char turn) {
	int now = bijection(board);
	if (mem[now] != -2) return mem[now];
	if (fin[now] == -1) fin[now] = isfinished(board);
	if (fin[now] == 1) return mem[now] = -1;
	else if (fin[now] == 2) return mem[now] = 0;

	bool win = false, draw = false;
	for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
		if (board[i][j] == '.') {
			board[i][j] = turn;
			int status = canwin(board, 'o'+'x'-turn);
			board[i][j] = '.';
			if (status == -1) win = 1;
			if (status == 0) draw = 1;
		}
	}

	if (win) return mem[now] = 1;
	if (draw) return mem[now] = 0;
	else return mem[now] = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 20000; ++i) {
		mem[i] = -2;
		fin[i] = -1;
	}

	int tc;
	cin >> tc;
	while (tc--) {
		vector<string> board(3);
		for (int i = 0; i < 3; ++i) cin >> board[i];

		int cnt = 0;
		for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) if (board[i][j] != '.') cnt++;

		int t = canwin(board, (cnt & 1 ? 'o' : 'x'));
		if (t == 0) cout << "TIE" << endl;
		else {
			if (t == 1) cout << (cnt & 1 ? 'o' : 'x') << endl;
			else cout << (cnt & 1 ? 'x' : 'o') << endl;
		}
	}
}
