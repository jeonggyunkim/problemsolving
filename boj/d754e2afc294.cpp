#include "MM.h"
#include <iostream>
#include <set>
#define N 10000
using namespace std;

typedef pair<int, int> ii;

ii result(int ans, int now) {
	int a[4], b[4];
	int cnta[6] = {}, cntb[6] = {};
	for (int i = 0; i < 4; ++i) {
		a[i] = ans % 6; ans /= 6;
		b[i] = now % 6; now /= 6;
	}
	ii ret = {};
	for (int i = 0; i < 4; ++i) {
		if (a[i] == b[i]) ret.first++;
		else {
			cnta[a[i]]++;
			cntb[b[i]]++;
		}
	}
	for (int i = 0; i < 6; ++i) {
		ret.second += min(cnta[i], cntb[i]);
	}
	return ret;
}

pair<bool, int> todo[N];
int nxt[N][5][5];
int counter = 0;

void make(int ind, set<int>& s) {
	if (s.size() == 1) {
		todo[ind].first = 1;
		todo[ind].second = *s.begin();
		return;
	}

	int mincnt = 98765, minq;
	for (int i = 0; i < 6 * 6 * 6 * 6; ++i) {
		int cnt[5][5] = {};
		for (int j: s) {
			ii now = result(i, j);
			cnt[now.first][now.second]++;
		}
		int maxcnt = -1;
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				maxcnt = max(maxcnt, cnt[j][k]);
			}
		}
		if (maxcnt < mincnt) {
			mincnt = maxcnt;
			minq = i;
		}
	}

	todo[ind].second = minq;
	set<int> nexts[5][5];
	for (int i: s) {
		ii now = result(i, minq);
		nexts[now.first][now.second].insert(i);
	}

	for (int i = 0; i < 5; ++i) {
		if (i == 4) continue;
		for (int j = 0; j < 5; ++j) {
			if (nexts[i][j].size() > 0) {
				nxt[ind][i][j] = counter;
				make(counter++, nexts[i][j]);
			}
		}
	}
}

void init(int T, int K) {
	set<int> s;
	for (int i = 0; i < 6 * 6 * 6 * 6; ++i) {
		s.insert(i);
	}
	make(counter++, s);
}

void game() {
	int ind = 0;
	while (!todo[ind].first) {
		int j = todo[ind].second;
		vector<int> q;
		for (int i = 0; i < 4; ++i) {
			q.push_back(j % 6 + 1);
			j /= 6;
		}
		ii ret = guess(q);
		if (ret == ii(4, 0)) return;
		ind = nxt[ind][ret.first][ret.second];
	}
	int j = todo[ind].second;
	vector<int> q;
	for (int i = 0; i < 4; ++i) {
		q.push_back(j % 6 + 1);
		j /= 6;
	}
	guess(q);
}