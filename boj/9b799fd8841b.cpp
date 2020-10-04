#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	vector<int> ans(n, -1);

	stack<ii> s;
	cin >> t;
	s.push(ii(t, 0));
	for (int i = 1; i < n; ++i) {
		cin >> t;
		while (!s.empty() && s.top().first < t) {
			ans[s.top().second] = t;
			s.pop();
		}
		s.push(ii(t, i));
	}

	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}