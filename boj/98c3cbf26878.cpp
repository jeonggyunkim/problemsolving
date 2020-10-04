#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

queue<int> fq;
int vis[1 << 25];
char board[6][6];

bool isCon(int b) {
	for (int i = 0; i < 25; ++i) {
		if (b & (1 << i)) {
			fq.push(i);
			b ^= (1 << i);
			while (!fq.empty()) {
				int now = fq.front(); fq.pop();
				if (now < 20 && (b & (1 << (now + 5)))) {
					fq.push(now + 5);
					b ^= (1 << (now + 5));
				}
				if (now >= 5 && (b & (1 << (now - 5)))) {
					fq.push(now - 5);
					b ^= (1 << (now - 5));
				}
				if (now % 5 != 0 && (b & (1 << (now - 1)))) {
					fq.push(now - 1);
					b ^= (1 << (now - 1));
				}
				if (now % 5 != 4 && (b & (1 << (now + 1)))) {
					fq.push(now + 1);
					b ^= (1 << (now + 1));
				}
			}
			if (b == 0) return 1;
			else return 0;
		}
	}
}

int main() {
	memset(vis, -1, sizeof(vis));

	int now = 0, cnt = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> board[i];
		for (int j = 0; j < 5; ++j) {
			if (board[i][j] == '*') now |= (1 << cnt);
			cnt++;
		}
	}

	if (isCon(now)) {
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(now);
	vis[now] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < 25; ++i) {
			if (now & (1 << i)) {
				int next1 = now ^ (1 << i);
				if (i < 20 && ((next1 & (1 << (i + 5))) == 0)) {
					int next2 = next1 | (1 << (i + 5));
					if (vis[next2] == -1) {
						if (isCon(next2)) {
							cout << vis[now] + 1;
							return 0;
						}
						q.push(next2);
						vis[next2] = vis[now] + 1;
					}
				}
				if (i >= 5 && ((next1 & (1 << (i - 5))) == 0)) {
					int next2 = next1 | (1 << (i - 5));
					if (vis[next2] == -1) {
						if (isCon(next2)) {
							cout << vis[now] + 1;
							return 0;
						}
						q.push(next2);
						vis[next2] = vis[now] + 1;
					}
				}
				if (i % 5 != 0 && ((next1 & (1 << (i - 1))) == 0)) {
					int next2 = next1 | (1 << (i - 1));
					if (vis[next2] == -1) {
						if (isCon(next2)) {
							cout << vis[now] + 1;
							return 0;
						}
						q.push(next2);
						vis[next2] = vis[now] + 1;
					}
				}
				if (i % 5 != 4 && ((next1 & (1 << (i + 1))) == 0)) {
					int next2 = next1 | (1 << (i + 1));
					if (vis[next2] == -1) {
						if (isCon(next2)) {
							cout << vis[now] + 1;
							return 0;
						}
						q.push(next2);
						vis[next2] = vis[now] + 1;
					}
				}
			}
		}
	}
}