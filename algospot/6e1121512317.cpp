#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int n;
int weight[101];
int imp[101];
int dp[101][1001];
bool choice[101][1001];
char name[101][21];

int cal(int s, int w) {
	if (dp[s][w] != -1) return dp[s][w];
	if (s == n) return dp[s][w] = 0;
	int a = cal(s + 1, w), b;
	if (w >= weight[s]) b = imp[s] + cal(s + 1, w - weight[s]);
	else b = 0;
	if (a < b) choice[s][w] = true;
	return dp[s][w] = (a > b ? a : b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int w;
		cin >> n >> w;
		memset(dp, -1, sizeof(dp));
		memset(choice, 0, sizeof(choice));

		for (int i = 0; i < n; ++i) cin >> name[i] >> weight[i] >> imp[i];

		cal(0, w);
		vector<int> v;
		int p = 0, q = w;
		while (p != n) {
			if (choice[p][q]) {
				v.push_back(p);
				q -= weight[p];
			}
			p++;
		}

		cout << dp[0][w] << ' ' << v.size() << '\n';
		for (int i = 0; i < v.size(); ++i) {
			cout << name[v[i]] << '\n';
		}
	}
}
