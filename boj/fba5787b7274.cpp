#include <iostream>
#include <iomanip>
#include <memory.h>
#define MOD 100000
using namespace std;

typedef pair<long long, bool> ib;

char input[201];
ib dp[201][201];

ib gh(int i, int j) {
	if (j < i) return ib(1, false);
	if (dp[i][j].first != -1) return dp[i][j];
	long long ret = 0;
	bool check = false;
	for (int k = i + 1; k <= j; k += 2) {
		if (input[i] == '?') {
			if (input[k] == '?') {
				ib t1 = gh(i + 1, k - 1);
				ib t2 = gh(k + 1, j);
				ret += 3LL * t1.first * t2.first;
				if (!(t1.first == 0 && t1.second == false) && !(t2.first == 0 && t2.second == false)) {
					check |= t1.second; check |= t2.second;
				}
			}
			else if (input[k] == ')' || input[k] == ']' || input[k] == '}') {
				ib t1 = gh(i + 1, k - 1);
				ib t2 = gh(k + 1, j);
				ret += t1.first * t2.first;
				if (!(t1.first == 0 && t1.second == false) && !(t2.first == 0 && t2.second == false)) {
					check |= t1.second; check |= t2.second;
				}
			}
		}
		else if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
			if (input[k] == '?' || (input[k] - input[i]) == 1 || (input[k] - input[i]) == 2) {
				ib t1 = gh(i + 1, k - 1);
				ib t2 = gh(k + 1, j);
				ret += t1.first * t2.first;
				if (!(t1.first == 0 && t1.second == false) && !(t2.first == 0 && t2.second == false)) {
					check |= t1.second; check |= t2.second;
				}
			}
		}
		if (ret > MOD) {
			ret %= MOD;
			check = true;
		}
	}
	return dp[i][j] = ib(ret, check);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cin >> input;

	if (n & 1) {
		cout << 0;
		return 0;
	}
	else {
		ib ans = gh(0, n - 1);
		if (ans.second) cout << setfill('0') << setw(5) << ans.first;
		else cout << ans.first;
	}
}