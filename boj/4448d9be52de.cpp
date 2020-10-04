#include <iostream>
#include <vector>
#define N 1000000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> num(N + 1, 0);
	vector<int> mini(N + 1, 0);
	for (int i = 2; i <= N / 2; ++i) {
		for (int j = 2 * i; j <= N; j += i) {
			num[j]++;
			if (num[j] == 1) mini[j] = i;
		}
	}

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, m;
		cin >> n >> m;

		int ans = 0;
		if (num[n] == 0) {
			cout << "Case #" << test << ": 0\n";
			continue;
		}
		for (int i = 2; i < n; ++i) {
			if (num[i] == num[n] && num[i] && mini[i] >= m) {
				ans++;
			}
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}
}