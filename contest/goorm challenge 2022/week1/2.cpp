#include <iostream>
using namespace std;

int main() {
	int n, ans = 0;
	string s, t;

	cin >> n >> s;
	while (n--) {
		cin >> t;
		if (t.find(s) != string::npos) ans++;
	}
	cout << ans;
}