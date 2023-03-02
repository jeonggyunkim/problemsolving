#include <iostream>
#include <algorithm>
using namespace std;

string s[2000000];

bool compare(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b ;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >>	k;

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	sort(s, s + n, compare);
	cout << s[k - 1];
}