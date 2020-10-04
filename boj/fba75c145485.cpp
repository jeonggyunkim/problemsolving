#include <iostream>
#include <map>
using namespace std;

typedef pair<int, int> ii;

map<char, int> color;
map<int, int> num;

bool seq() {
	if (num.size() != 5) return false;
	auto it = num.begin(), jt = it;
	jt++;
	while (jt != num.end()) {
		if (it->first + 1 != jt->first) return false;
		it++; jt++;
	}
	return true;
}

ii samemax() {
	ii ret = ii(-1, 0);
	for (auto it = num.begin(); it != num.end(); ++it) {
		if (it->second >= ret.first) {
			if (it->second == ret.first) {
				ret.second += 10 * it->first;
			}
			else {
				ret.first = it->second;
				ret.second = it->first;
			}
		}
	}
	return ret;
}

int main() {
	char a;
	int b;
	for (int i = 0; i < 5; ++i) {
		scanf("%c %d ", &a, &b);
		color[a]++;
		num[b]++;
	}

	auto maxptr = num.end(); maxptr--;
	if (color.size() == 1 && seq()) cout << 900 + maxptr->first;
	else if (num.size() == 2) {
		auto it = num.begin();
		if (it->second == 1 || it->second == 4) {
			if (it->second == 1) {
				it++;
				cout << 800 + it->first;
			}
			else cout << 800 + it->first;
		}
		else {
			int ans = 700;
			if (it->second == 2) {
				ans += it->first;
				it++;
				cout << ans + it->first * 10;
			}
			else {
				ans += it->first * 10;
				it++;
				cout << ans + it->first;
			}
		}
	}
	else if (color.size() == 1) cout << 600 + maxptr->first;
	else if (seq()) cout << 500 + maxptr->first;
	else {
		ii t = samemax();
		if (t.first == 3) cout << 400 + t.second;
		else if (t.first == 2) {
			if (t.second > 10) cout << 300 + t.second;
			else cout << 200 + t.second;
		}
		else cout << 100 + maxptr->first;
	}
}