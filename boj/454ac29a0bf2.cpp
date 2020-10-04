#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dp[10010];
int price[110];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= m; ++i) cin >> price[i];

	vector<tuple<int, int, int>> arr(n);
	int a, b, w;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> w;
		arr[i] = {a, b, w};
	}

	sort(arr.begin(), arr.end());

	int j = 0;
	for (int i = 1; i <= 10000; ++i) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		while (j < n && get<0>(arr[j]) == i) {
			int end = get<1>(arr[j]);
			dp[end] = max(dp[end], dp[i] + (end - i) * price[get<2>(arr[j])]);
			j++;
		}
	}
	cout << dp[10000];
}