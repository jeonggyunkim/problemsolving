#include <iostream>
#include <map>
using namespace std;

map<string, int> a = {{"Mon", 0}, {"Tue", 1}, {"Wed", 2}, {"Thu", 3}, {"Fri", 4}};

int main() {
	int t, n;
	cin >> t >> n;

	string s1, s2;
	int n1, n2;
	for (int i = 0; i < n; ++i) {
		cin >> s1 >> n1 >> s2 >> n2;
		t -= a[s2] * 24 + n2 - (a[s1] * 24 + n1);
	}
	if (t > 48) cout << -1;
	else if (t < 0) cout << 0;
	else cout << t;
}