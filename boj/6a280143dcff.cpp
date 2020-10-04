#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}