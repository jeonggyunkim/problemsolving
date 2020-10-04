#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	set<string> st;
	for (int i = 1; i <= s.size() - 2; ++i) {
		for (int j = 1; j <= s.size() - 1 - i; ++j) {
			int k = s.size() - i - j;
			string a, b, c;
			a = s.substr(0, i); reverse(a.begin(), a.end());
			b = s.substr(i, j); reverse(b.begin(), b.end());
			c = s.substr(i + j, k); reverse(c.begin(), c.end());
			st.insert(a + b + c);
		}
	}
	cout << *st.begin();
}