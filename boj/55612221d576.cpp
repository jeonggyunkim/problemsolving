#include <iostream>
#include <map>
using namespace std;

int arr[200010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	map<int, int> mp;
	mp[0]++;
	
	int t;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
		mp[arr[i]]++;
	}
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		mp[arr[i]]--;
		ans += mp[arr[i] + m];
	}
	cout << ans;
}