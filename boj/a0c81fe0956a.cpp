#include <iostream>
#define MOD 1000000007
using namespace std;

const char* uni = "UNIST";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dp[6] = {};
	dp[0] = 1;

	int n;
	cin >> n;

	char s[50];
	while (n--) {
		cin >> s;
		for (int i = 0; i < 5; ++i) {
			if (s[0] == uni[i]) {
				dp[i + 1] += dp[i];
				for (int j = 1; s[j] && j < 5; ++j) {
					if (s[j] == uni[i + j]) dp[i + j + 1] += dp[i];
					else break;
				}
				for (int j = 1; j <= 5; ++j) dp[j] %= MOD;
				break;
			}
		}
	}

	cout << dp[5];
}