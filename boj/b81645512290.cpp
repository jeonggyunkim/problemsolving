#include <iostream>
#include <string>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int trie[1000000][26];
int fin[1000000];
int dp[200010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	string str;
	int cnt = 1;
	while (n--) {
		cin >> str;
		int now = 0;
		for (int i = 0; i < str.size(); ++i) {
			int num = str[i] - 'a';
			if (trie[now][num] == 0) {
				trie[now][num] = cnt;
				now = cnt++;
			}
			else now = trie[now][num];
			fin[now]++;
		}
	}

	cin >> str;
	dp[0] = 1;
	for (int i = 0; i < str.size(); ++i) {
		int now = 0;
		for (int j = 0; i + j < str.size(); ++j) {
			if (trie[now][str[i + j] - 'a']) now = trie[now][str[i + j] - 'a'];
			else break;
			dp[i + j + 1] += ((ll)dp[i] * fin[now]) % MOD;
			dp[i + j + 1] %= MOD;
		}
	}

	cout << dp[str.size()];
}