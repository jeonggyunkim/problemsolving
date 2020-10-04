#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input[8];
	for (int i = 0; i < 8; ++i) for (int j = 0; j < 3; ++j) {
		char t;
		cin >> t;
		input[i] += t;
	}

	int edge[8][3] = {{0, 1, 2}, {0, 2, 3}, {0, 3, 4}, {0, 4, 1}, {5, 2, 1}, {5, 3, 2}, {5, 4, 3}, {5, 1, 4}};
	string color = "WYROGB";
	sort(color.begin(), color.end());

	do {
		bool check[8] = {};
		for (int i = 0; i < 8; ++i) {
			string s[3];
			for (int x = 0; x < 3; ++x) for (int y = 0; y < 3; ++y) {
				s[x] += color[edge[i][(x + y) % 3]];
			}
			for (int j = 0; j < 8; ++j) {
				bool up = 0;
				for (int k = 0; k < 3; ++k) if (s[k] == input[j]) {
					check[j] = 1;
					up = 1;
				}
				if (up) break;
			}
		}
		bool ans = 1;
		for (int i = 0; i < 8; ++i) ans &= check[i];
		if (ans) {
			cout << "YES";
			return 0;
		}
	} while (next_permutation(color.begin(), color.end()));
	cout << "NO";
}