#include <iostream>
#include <memory.h>
#include <string>
#include <set>
using namespace std;

int n, len;
char str[101];
char c[101];
char pos[101][101];

bool check(int p, int d) {
	if (p > len) return false;
	if (d == n) {
		if (c[p] == 0) return true;
		else return false;
	}
	if (pos[p][d] != -1) return pos[p][d];

	if (str[d] == '*') {
		for (int i = p; i <= len; ++i) {
			if (check(i, d + 1)) return pos[p][d] = true;
		}
		return pos[p][d] = false;
	}
	else if (str[d] == '?') {
		return pos[p][d] = check(p + 1, d + 1);
	}
	else {
		if (str[d] == c[p]) return pos[p][d] = check(p + 1, d + 1);
		else return pos[p][d] = false;
	}

}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		scanf("%s", str);
		n = -1; while (str[++n]);

		int word;
		scanf("%d", &word);
		set<string> s;

		while (word--) {
			memset(pos, -1, sizeof(pos));
			scanf("%s", c);
			len = -1; while (c[++len]);
			if (check(0, 0)) {
				s.insert(c);
			}
		}
		for (auto it = s.begin(); it != s.end(); ++it) printf("%s\n", (*it).c_str());
	}
}
