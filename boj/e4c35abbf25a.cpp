#include <iostream>
using namespace std;

int score[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b, c, d;
	for (int i = 0; i < n * (n - 1) / 2; ++i) {
		cin >> a >> b >> c >> d;
		a--; b--;
		if (c > d) score[a] += 3;
		else if (c == d) {
			score[a]++;
			score[b]++;
		}
		else {
			score[b] += 3;
		}
	}

	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		for (int j = 0; j < n; ++j) {
			if (score[j] > score[i]) cnt++;
		}
		cout << cnt << '\n';
	}
}