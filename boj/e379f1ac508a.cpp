#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

char arr[1010][1010];
string str[1010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; ++i) cin >> arr[i];

	for (int i = 0; i < c; ++i) {
		for (int j = r - 1; j > 0; --j) str[i] += arr[j][i];
	}

	int cnt = 0;
	while (cnt < r - 1) {
		unordered_set<string> s;
		for (int i = 0; i < c; ++i) {
			if (s.count(str[i])) {
				cout << cnt;
				return 0;
			}
			s.insert(str[i]);
		}
		cnt++;
		for (int i = 0; i < c; ++i) str[i].pop_back();
	}
	cout << cnt;
}