#include <iostream>
using namespace std;

int arr[101];
int cnt[1000010];

void prime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			cnt[i]++;
			n /= i;
		}
	}
	if (n != 1) cnt[n]++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		prime(arr[i]);
	}

	int ans = 1, move = 0;
	for (int i = 1; i <= 1000000; ++i) {
		if (cnt[i] >= n) {
			int goal = cnt[i] / n;
			for (int j = 0; j < n; ++j) {
				int now = 0;
				while (arr[j] % i == 0) {
					arr[j] /= i;
					now++;
				}
				move += max(0, goal - now);
			}
			while (goal--) ans *= i;
		}
	}
	cout << ans << ' ' << move;
}