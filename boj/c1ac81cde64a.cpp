#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool ispel(string a) {
	string b = a;
	reverse(b.begin(), b.end());
	return a == b;
}

string genpal(int len, bool second) {
	string ret(len, 'a');
	if (second) {
		if (len & 1) ret[len / 2] = 'b';
		else ret[len / 2] = ret[len / 2 - 1] = 'b';
	}
	return ret;
}

string genans(string a, int len, bool second) {
	if (len <= a.size()) {
		string ret = a.substr(0, len);
		reverse(ret.begin(), ret.end());
		return ret;
	}
	else {
		reverse(a.begin(), a.end());
		return genpal(len - a.size(), second) + a;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	while (getline(cin, a) && getline(cin, b)) {
		if (a == b) {
			cout << "No Solution.\n";
			continue;
		}
		if (ispel(a) != ispel(b)) {
			cout << '\n';
			continue;
		}

		int len = 1;
		while (len) {
			bool ap, bp;
			ap = (len >= a.size()) || ispel(a.substr(len, a.size() - len));
			bp = (len >= b.size()) || ispel(b.substr(len, b.size() - len));

			if (ap && bp) {
				bool fa, fb;
				fa = (len <= a.size());
				fb = (len <= b.size());

				string a_ans, b_ans;
				a_ans = genans(a, len, 0);
				b_ans = genans(b, len, 0);
				if (fa && fb) {
					if (a_ans != b_ans) {
						if (a_ans < b_ans) cout << a_ans;
						else cout << b_ans;
						break;
					}
				}
				else {
					if (fa) {
						if (a_ans == b_ans) {
							b_ans = genans(b, len, 1);
							cout << b_ans;
						}
						else {
							if (a_ans > b_ans) cout << b_ans;
							else cout << a_ans;
						}
						break;
					}
					else {
						if (a_ans == b_ans) {
							a_ans = genans(a, len, 1);
							cout << a_ans;
						}
						else {
							if (a_ans > b_ans) cout << b_ans;
							else cout << a_ans;
						}
						break;
					}
				}
			}
			else if (ap || bp) {
				if (ap) cout << genans(a, len, 0);
				else cout << genans(b, len, 0);
				break;
			}
			len++;
		}
		cout << '\n';
	}
}