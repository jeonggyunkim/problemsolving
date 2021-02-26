#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int n;
int tree[1000010];
int s[1000010];

void insert(int i) {
	while (i <= n) {
		tree[i]++;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i &= (i - 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<ii> arr;

	int t;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		arr.push_back({t, i});
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; ++i) {
		s[arr[i].second] = get(arr[i].second);
		insert(arr[i].second);
	}

	for (int i = 1; i <= n; ++i) cout << s[i] << '\n';
}