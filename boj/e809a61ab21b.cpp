#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pi;

void getpi(string& N) {
	int m = N.size();
	pi.resize(m, 0);

	int begin = 1, match = 0;
	while (begin + match < m) {
		if (N[begin + match] == N[match]) {
			++match;
			pi[begin + match - 1] = match;
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}

int main() {
	string H, N;
	char t;
	while (t = getchar()) {
		if (t == '\n') break;
		else H.push_back(t);
	}
	while (t = getchar()) {
		if (t == '\n' || t == EOF) break;
		else N.push_back(t);
	}

	getpi(N);

	int n = H.size(), m = N.size();
	vector<int> ans;

	int begin = 0, match = 0;
	while (begin <= n - m) {
		if (match < m && H[begin + match] == N[match]) {
			++match;
			if (match == m) ans.push_back(begin);
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}

	printf("%d\n", ans.size());
	for (int u: ans) printf("%d ", u + 1);
}