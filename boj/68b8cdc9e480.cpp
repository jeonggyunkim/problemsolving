#include "SORT.h"
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int n;
pair<pair<int, int>, string> todo[1 << 14];

void make(int ind, set<string>& s) {
	if (s.size() == 1) {
		todo[ind].first.first = -1;
		todo[ind].second = *s.begin();
		return;
	}

	int mincnt = 98765, mini, minj;
	if (ind == 0) {
		mini = 0;
		minj = 1;
	}
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int cnt = 0;
				for (string str: s) {
					if (str[i] < str[j]) cnt++;
				}
				if (max(cnt, (int)s.size() - cnt) < mincnt) {
					mincnt = max(cnt, (int)s.size() - cnt);
					mini = i;
					minj = j;
				}
			}
		}
	}

	set<string> left, right;
	for (string str: s) {
		if (str[mini] < str[minj]) left.insert(str);
		else right.insert(str);
	}

	todo[ind].first = {mini, minj};
	make(2 * ind + 1, left);
	make(2 * ind + 2, right);
}

string find(int ind) {
	if (todo[ind].first.first == -1) return todo[ind].second;
	if (compare(todo[ind].first.first + 1, todo[ind].first.second + 1)) return find(2 * ind + 1);
	else return find(2 * ind + 2);
}

void init(int T, int N) {
	n = N;
	string s;
	for (int i = 0; i < n; ++i) s += (char)('1' + i);

	set<string> st;
	do {
		st.insert(s);
	} while (next_permutation(s.begin(), s.end()));
	make(0, st);
}

void sorting() {
	string ans = find(0);
	for (int i = 0; i < n; ++i) {
		answer(i + 1, ans[i] - '0');
	}
}
