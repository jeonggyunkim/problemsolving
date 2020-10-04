#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> m;

int find(string& s) {
	if (s.size() == 1) return 1;
	if (m.count(s)) return m[s];
	string left, right;
	left = s.substr(0, s.size() - 1);
	right = s.substr(1, s.size() - 1);
	if (left == right) return m[s] = find(left);
	else return m[s] = find(left) + find(right);
}

int main() {
	string s;
	cin >> s;

	cout << find(s);
}