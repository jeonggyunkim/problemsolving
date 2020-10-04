#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int num[1020] = {};
	cin >> s;

	for (int i = s.size() - 1; i >= 0; --i) {
		num[s.size() - 1 - i] = s[i] - '0';
	}

	for (int i = 1000; i >= 0; --i) num[i + 4] += num[i];
	for (int i = 0; i < 1015; ++i) {
		while (num[i] >= 2) {
			num[i] -= 2;
			num[i + 1]++;
		}
	}

	bool start = 0;
	for (int i = 1019; i >= 0; --i) {
		if (start || num[i]) {
			start = 1;
			cout << num[i];
		}
	}
}