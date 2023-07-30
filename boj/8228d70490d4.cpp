#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, t;
	cin >> n >> s;

	for (int i = 0; i < n; ++i) cin >> t;

	string st;
	cin >> st;

	for (int i = st.size() - 1; i >= 0; --i) {
		cout << st[i];
	}
}