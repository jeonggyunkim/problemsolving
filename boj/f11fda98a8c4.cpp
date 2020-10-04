#include <iostream>
#include <algorithm>
using namespace std;

string s[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
	}
	sort(s, s + n);

	for (int i = 0; i < n; ++i) cout << s[i] << '\n';
}