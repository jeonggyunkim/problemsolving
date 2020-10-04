#include <iostream>
#include <vector>
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
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N, t;
	cin >> N >> t;
	N += t;

	getpi(N);

	vector<int> ans;
	int len = N.size();
	while (len) {
		ans.push_back(len);
		len = pi[len - 1];
	}
	for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << ' ';
}
