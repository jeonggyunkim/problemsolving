#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int n;
long long coin[33];

int status() {
	int ret = 0;
	for (long long j = 1; j < (1LL << n); j <<= 1) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (coin[i] & j) cnt++;
		}
		ret += min(cnt, n - cnt);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	srand(time(0));
	cin >> n;

	char input[34];
	for (int i = 0; i < n; ++i) {
		cin >> input;
		for (int j = 0; j < n; ++j) {
			if (input[j] == 'H') coin[i] |= (1LL << j);
		}
	}

	int ans = 987654321;
	for (int epoch = 0; epoch < 4000; ++epoch) {
		int now = status();
		int i = rand() % n, start = rand() % n;
		do {
			coin[i] = ~coin[i];
			int news = status();
			if (news < now) {
				now = news;
				start = i;
			}
			else {
				coin[i] = ~coin[i];
			}
			i = (i + 1) % n;
		} while (i != start);
		ans = min(ans, now);
		for (int j = 0; j < n; ++j) {
			int t = rand();
			if (t < RAND_MAX / 2) coin[j] = ~coin[j];
		}
	}
	cout << ans;
}