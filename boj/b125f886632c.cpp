#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> s;

	vector<char> st;
	for (int i = 0; i < s.size(); ++i) {
		st.push_back(s[i]);
		while ((n = st.size()) >= 4 && st[n - 1] == 'P' && st[n - 2] == 'A' && st[n - 3] == 'P' && st[n - 4] == 'P') {
			st.pop_back();
			st.pop_back();
			st.pop_back();
		}
	}
	if (st.size() == 1 && st[0] == 'P') cout << "PPAP";
	else cout << "NP";
}
