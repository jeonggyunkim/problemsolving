#include "NB.h"
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int n;
set<string> s;
set<string> pool[5][5][5][5];

ii result(string ans, string now) {
	ii ret = {0, 0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ans[i] == now[j]) ret.second++;
		}
		if (ans[i] == now[i]) {
			ret.second--;
			ret.first++;
		}
	}
	return ret;
}

void init(int T, int N) {
	n = N;
	if (n == 3) {
		for (char a = '0'; a <= '9'; ++a) {
			for (char b = '0'; b <= '9'; ++b) {
				if (b == a) continue;
				for (char c = '0'; c <= '9'; ++c) {
					if (c == a || c == b) continue;
					string now;
					now += a; now += b; now += c;
					ii ret = result("123", now);
					ii ret2 = result("456", now);
					pool[ret.first][ret.second][ret2.first][ret2.second].insert(now);
				}
			}
		}
	}
	else {
		for (char a = '0'; a <= '9'; ++a) {
			for (char b = '0'; b <= '9'; ++b) {
				if (b == a) continue;
				for (char c = '0'; c <= '9'; ++c) {
					if (c == a || c == b) continue;
					for (char d = '0'; d <= '9'; ++d) {
						if (d == a || d == b || d == c) continue;
						string now;
						now += a; now += b; now += c; now += d;
						ii ret = result("1234", now);
						ii ret2 = result("5678", now);
						pool[ret.first][ret.second][ret2.first][ret2.second].insert(now);
					}
				}
			}
		}
	}
}

void game() {
	string q;
	ii ret, ret2;
	if (n == 3) {
		ret = guess("123");
		if (ret == ii(n, 0)) return;
		ret2 = guess("456");
		if (ret2 == ii(n, 0)) return;
		s = pool[ret.first][ret.second][ret2.first][ret2.second];
	}
	else {
		ret = guess("1234");
		if (ret == ii(n, 0)) return;
		ret2 = guess("5678");
		if (ret2 == ii(n, 0)) return;
		s = pool[ret.first][ret.second][ret2.first][ret2.second];
	}
	
	q = *s.begin();
	ret = guess(q);
	while (ret != ii(n, 0)) {
		set<string> temp;
		for (auto it = s.begin(); it != s.end(); ++it) {
			if (result(*it, q) == ret) temp.insert(*it);
		}
		s = temp;
		q = *s.begin();
		ret = guess(q);
	}
}
