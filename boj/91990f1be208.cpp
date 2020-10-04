#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, t;
	cin >> k;

	vector<int> st;
	for (int i = 0; i < k; ++i) {
		cin >> t;
		if (t) st.push_back(t);
		else st.pop_back();
	}

	long long ans = 0;
	for (int u: st) ans += u;
	cout << ans;
}