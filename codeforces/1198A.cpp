#include <bits/stdc++.h>
using namespace std;
	
typedef pair<int, int> ii;
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, I;
	cin >> n >> I;
	
	map<int, int> m;
	int t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		m[t]++;
	}
	
	vector<ii> arr;
	for (auto it = m.begin(); it != m.end(); ++it) {
		arr.push_back({it->first, it->second});
	}
	
	int maxbit = I * 8 / n;
	int pow = 1;
	for (int i = 0; i < min(20, maxbit); ++i) pow *= 2;
	
	int cnt = 0;
	for (int i = 0; i < min(pow, (int)arr.size()); ++i) cnt += arr[i].second;
	int ans = cnt;
	for (int i = 1; i <= (int)arr.size() - pow; ++i) {
		cnt -= arr[i - 1].second;
		cnt += arr[i + pow - 1].second;
		ans = max(ans, cnt);
	}
	
	cout << n - ans;
}