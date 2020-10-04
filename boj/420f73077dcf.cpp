#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n), cnt(1000001, 0), newarr(n), ans(n, -1);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = 0; i < n; ++i) {
		newarr[i] = cnt[arr[i]];
	}

	stack<ii> s;
	s.push(ii(newarr[0], 0));
	for (int i = 1; i < n; ++i) {
		while (!s.empty() && s.top().first < newarr[i]) {
			ans[s.top().second] = arr[i];
			s.pop();
		}
		s.push(ii(newarr[i], i));
	}

	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}