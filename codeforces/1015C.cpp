#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> redu;
	int a, b;
	long long sum = 0, sum_b = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		sum += a;
		sum_b += b;
		redu.push_back(a - b);
	}

	if (sum_b > m) {
		cout << -1;
		return 0;
	}

	sort(redu.begin(), redu.end());

	int ans = 0;
	int i = n - 1;
	while (sum > m) {
		ans++;
		sum -= redu[i--];
	}

	cout << ans;
}