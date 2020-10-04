#include <iostream>
#include <string>
#include <stack>
#define ERR {cout << -1; return 0;}
using namespace std;

int main() {
	int w;
	cin >> w;

	string s;

	char t;
	while ((t = getchar()) != EOF) {
		if (t != ' ' && t != '\n') s.push_back(t);
	}

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ':' || s[i] == ';' || s[i] == '.') ERR
		if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'L' && s[i] != 'B' && s[i] != 'S') ERR
	}

	if (s.size() == 0) ERR
	if (s.size() == 1) {
		if (s[0] == 'S') cout << 1;
		else cout << -1;
		return 0;
	}

	stack<char> st;
	if (s[0] != 'L' && s[0] != 'S' && s[0] != 'B') ERR
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == 'L' || s[i] == 'B') {
			if (s[i + 1] != '[' && s[i + 1] != '(') ERR
		}
		else if (s[i] == 'S') {
			if (s[i + 1] != ']' && s[i + 1] != ')' && s[i + 1] != ',') ERR
		}
		else if (s[i] == '(' || s[i] == '[') {
			if (s[i + 1] != 'L' && s[i + 1] != 'S' && s[i + 1] != 'B') ERR
			st.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']') {
			if (s[i + 1] != ',' && s[i + 1] != ')' && s[i + 1] != ']') ERR
			if (s[i] == ')' && st.top() != '(') ERR
			if (s[i] == ']' && st.top() != '[') ERR
			st.pop();
		}
		else if (s[i] == ',') {
			if (s[i + 1] != 'L' && s[i + 1] != 'S' && s[i + 1] != 'B') ERR
		}
		else ERR
	}
	if (s.back() != 'S' && s.back() != ')' && s.back() != ']') ERR
	else {
		if (s.back() != 'S') {
			if (st.empty()) ERR
			if (s.back() == ')' && st.top() != '(') ERR
			if (s.back() == ']' && st.top() != '[') ERR
			st.pop();
		}
	}
	if (!st.empty()) ERR

	int v = 0, f = 0, b = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'L') {
			v += 2;
			b += 1;
			f += 2;
		}
		else if (s[i] == 'B') {
			v += 2;
			f += 3;
		}
		else if (s[i] == 'S') {
			v += 1;
			f += 1;
		}
	}
	f -= 1;

	cout << f + w * b - v + 2;
}