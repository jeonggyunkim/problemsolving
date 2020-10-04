#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	stack<pair<char, int>> st;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0' && !st.empty() && st.top().first == '1') st.pop();
		else st.push({s[i], i});
	}

	while (!st.empty()) {
		s[st.top().second] = '0';
		st.pop();
	}

	cout << s;
}