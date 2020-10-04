#include <iostream>
#include <vector>
#include <memory.h>
#define INF 987654321
using namespace std;

int dp[100][100][3];
vector<int> t1, t2;
int C, D, d, t;

int cal(int a, int b, int before) {
	if (dp[a][b][before] > 0) return dp[a][b][before];

	if (a == t1.size() || b == t2.size()) {
		int ret = 0;
		if (a == t1.size() && b == t2.size()) return 0;
		if (a == t1.size()) {
			ret += (C + d) * (t2.size() - b);
			if (before != 1) ret += D;
		}
		else {
			ret += (C + d) * (t1.size() - a);
			if (before != 2) ret += D;
		}
		return dp[a][b][before] = ret;
	}

	int ret = INF, r;

	r = 0;
	if (t1[a] == t2[b]) r += C;
	else r += 2 * C;
	r += cal(a + 1, b + 1, 0);
	ret = min(ret, r);

	r = C + d;
	if (before != 2) r += D;
	r += cal(a + 1, b, 2);
	ret = min(ret, r);

	r = C + d;
	if (before != 1) r += D;
	r += cal(a, b + 1, 1);
	ret = min(ret, r);

	return dp[a][b][before] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, 0, sizeof(dp));
		cin >> C >> D >> d;
		t1.clear(); t2.clear();
		while (cin >> t, t) t1.push_back(t);
		while (cin >> t, t) t2.push_back(t);
		cout << cal(0, 0, 0) << '\n';
	}
}