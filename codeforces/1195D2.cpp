#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
	
int arr[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int len[11] = {};
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int t = arr[i];
		int l = 0;
		while (t) {
			t /= 10;
			l++;
		}
		len[l]++;
	}


	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int l = 1; l <= 10; ++l) {
			long long p = 1;
			int t = arr[i];
			long long sum = 0;
			for (int k = 0; k < l; ++k) {
				sum += (t % 10) * p * 11;
				sum %= MOD;
				p = (p * 100) % MOD;
				t /= 10;
			}
			while (t) {
				sum += 2 * (t % 10) * p;
				sum %= MOD;
				p = (p * 10) % MOD;
				t /= 10;
			}
			ans += sum * len[l];
			ans %= MOD;
		}
	}
	cout << ans;
}