#include <iostream>
#include <algorithm>
using namespace std;

int first[100], second[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> first[i] >> second[i];
	}

	int rep[3] = {1, 2, 3};
	int ans = 0;
	do {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (first[i] == rep[j] && second[i] == rep[(j + 1) % 3]) cnt++;
			}
		}
		ans = max(ans, cnt);
	} while (next_permutation(rep, rep + 3));
	cout << ans;
}
