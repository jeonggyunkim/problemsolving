#include <iostream>
using namespace std;

int convert(string s) {
	int hour = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '.') {
			for (int j = 4; j < i; ++j) {
				hour *= 10;
				hour += s[j] - '0';
			}
			hour *= 60;
			hour += 30;
			if (s[3] == '-') hour *= -1;
			return hour;
		}
	}
	for (int j = 4; j < s.size(); ++j) {
		hour *= 10;
		hour += s[j] - '0';
	}
	hour *= 60;
	if (s[3] == '-') hour *= -1;
	return hour;
}

string time(string s, int d) {
	int time = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + s[4] - '0';
	time += d;
	if (time < 0) time += 24 * 60;
	time %= 24 * 60;
	string ret;
	ret += '0' + (time / 60) / 10;
	ret += '0' + (time / 60) % 10;
	ret += ':';
	ret += '0' + (time % 60) / 10;
	ret += '0' + (time % 60) % 10;

	return ret;
}

int main() {
	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;
	int u = convert(t);

	while (n--) {
		cin >> t;
		cout << time(s, -u + convert(t)) << '\n';
	}
}