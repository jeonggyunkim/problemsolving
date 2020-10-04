#include <iostream>
using namespace std;

int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
char input[16];

void find(int n, int sum, int a) {
	if (n == 1) {
		for (int i = 0; i < 10; ++i) {
			if (sum == cnt[i]) {
				input[a] = '0' + i;
				return;
			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		if ((n - 1) * 2 <= sum - cnt[i] && (n - 1) * 7 >= sum - cnt[i]) {
			input[a] = '0' + i;
			find(n - 1, sum - cnt[i], a + 1);
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> input;
	int n = -1;
	while (input[++n]);

	int ans = 0;
	for (int i = 0; i < n; ++i) ans += cnt[input[i] - '0'];
	long long start = atoll(input);
	for (int i = n - 1; i >= 0; --i) {
		while (1) {
			input[i]++;
			if (input[i] > '9') {
				if (i == 0) input[i] = '0';
				else break;
			}
			int sum = 0;
			for (int j = 0; j <= i; ++j) sum += cnt[input[j] - '0'];
			if ((n - 1 - i) * 2 <= ans - sum && (n - 1 - i) * 7 >= ans - sum) {
				find(n - 1 - i, ans - sum, i + 1);
				long long end = atoll(input);
				long long p = 1;
				while (n--) p *= 10;
				if (end <= start) cout << p + end - start;
				else cout << end - start;
				return 0;
			}
		}
	}
}