#include <iostream>
#include <vector>
#include <string>
using namespace std;

int arr[8] = {0, 15, 19, 28, 38, 41, 53, 58};

int conv(string s) {
	int ret = 0;
	for (int i = 0; i < 6; ++i) {
		if (s[i] == '1') ret = 2 * ret + 1;
		else ret *= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int t = conv(s.substr(6 * i, 6));
		int find = -1;
		for (int j = 0; j < 8; ++j) {
			int tt = t ^ arr[j];
			if (t == arr[j] || (tt & (tt - 1)) == 0) {
				find = j;
				break;
			}
		}
		if (find != -1) ans.push_back(find);
		else {
			cout << i + 1;
			return 0;
		}
	}

	for (int u: ans) cout << (char)('A' + u);
}