#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct real {
	string before;
	string after;
	int len1, len2;
	char sign = 1;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	string s;
	while (tc--) {
		vector<real> vec;
		int ml1 = 0, ml2 = 0;
		while (cin >> s, s != "0") {
			real t;
			if (s[0] == '-') {
				t.sign = -1;
				s = s.substr(1, s.size() - 1);
			}
			int a = s.find('.');
			if (a == -1) {
				t.len1 = s.size();
				t.len2 = 0;
				t.before = s;
			}
			else {
				t.len1 = s.find('.');
				t.len2 = s.size() - t.len1 - 1;
				t.before = s.substr(0, t.len1);
				t.after = s.substr(t.len1 + 1, t.len2);
			}
			ml1 = max(ml1, t.len1);
			ml2 = max(ml2, t.len2);
			vec.push_back(t);
		}

		vector<int> cal(ml1 + ml2 + 4, 0);
		for (real u: vec) {
			for (int i = 0; i < u.len1; ++i) {
				cal[ml1 + 2 - u.len1 + i] += u.sign * (u.before[i] - '0');
			}
			for (int i = 0; i < u.len2; ++i) {
				cal[ml1 + 2 + i] += u.sign * (u.after[i] - '0');
			}
		}

		for (int i = cal.size() - 1; i >= 1; --i) {
			while (cal[i] < 0) {
				cal[i] += 10;
				cal[i - 1] -= 1;
			}
			while (cal[i] >= 10) {
				cal[i] -= 10;
				cal[i - 1] += 1;
			}
		}
		if (cal[0] < 0) {
			cout << '-';
			for (int i = 0; i < cal.size(); ++i) cal[i] = -cal[i];
			for (int i = cal.size() - 1; i >= 1; --i) {
				while (cal[i] < 0) {
					cal[i] += 10;
					cal[i - 1] -= 1;
				}
				while (cal[i] >= 10) {
					cal[i] -= 10;
					cal[i - 1] += 1;
				}
			}
		}
		int start = -1, end = -1;
		for (int i = 0; i < cal.size(); ++i) {
			if (start == -1 && cal[i] != 0) {
				start = i;
				break;
			}
		}
		for (int i = cal.size() - 1; i >= 0; --i) {
			if (end == -1 && cal[i] != 0) {
				end = i;
				break;
			}
		}

		if (start == -1 && end == -1) cout << 0;
		else {
			if (start > ml1 + 1) {
				cout << "0.";
				for (int i = 0; i < start - ml1 - 2; ++i) cout << 0;
			}
			for (int i = start; i <= end; ++i) {
				cout << cal[i];
				if (i == ml1 + 1 && i != end) cout << '.';
			}
			if (end < ml1 + 1) {
				for (int i = 0; i < ml1 + 1 - end; ++i) cout << 0;
			}
		}
		cout << '\n';
	}
}