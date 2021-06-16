#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	set<int> st;
	int ans = 2000000001, a, b;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		auto it = st.lower_bound(-t);
		if (it != st.begin()) {
			auto jt = it;
			jt--;
			if (abs(*jt + t) < ans) {
				ans = abs(*jt + t);
				a = *jt;
				b = t;
			}
		}
		if (it != st.end()) {
			if (abs(*it + t) < ans) {
				ans = abs(*it + t);
				a = *it;
				b = t;
			}
			auto jt = it;
			jt++;
			if (jt != st.end() && abs(*jt + t) < ans) {
				ans = abs(*jt + t);
				a = *jt;
				b = t;
			}
		}
		st.insert(t);
	}
	if (a > b) swap(a, b);
	cout << a << ' ' << b;
}