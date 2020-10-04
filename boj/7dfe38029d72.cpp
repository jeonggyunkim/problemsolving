#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	multiset<int> st;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		st.insert(t);
	}

	auto it = st.begin();
	auto jt = it; jt++;
	if (*it == *jt) {
		cout << "No";
		return 0;
	}

	vector<int> out;
	int low = *it;
	int d = *jt - *it, now = low;
	while (1) {
		it = st.find(now);
		if (it != st.end()) {
			st.erase(it);
			out.push_back(now);
		}
		else break;
		now += d;
	}

	if (st.empty()) {
		cout << "Yes";
		return 0;
	}

	int pos = 1;
	d = *(st.begin()) - low;
	now = low;
	for (it = st.begin(); it != st.end(); ++it) {
		now += d;
		if (*it != now) {
			pos = 0;
			break;
		}
	}

	if (pos) {
		cout << "Yes";
		return 0;
	}

	st.insert(out.back());
	pos = 1;
	d = *(st.begin()) - low;
	now = low;
	for (it = st.begin(); it != st.end(); ++it) {
		now += d;
		if (*it != now) {
			pos = 0;
			break;
		}
	}

	if (pos) cout << "Yes";
	else cout << "No";
}