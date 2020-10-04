#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

typedef tuple<int, int, int> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b, h;
	vector<iii> arr;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> h;
		arr.push_back({a, h, 1});
		arr.push_back({b, h, 2});
	}

	sort(arr.begin(), arr.end());

	long long ans = 0;
	multiset<int> ms;
	for (int i = 0; i < arr.size() - 1; ++i) {
		if (get<2>(arr[i]) == 1) ms.insert(get<1>(arr[i]));
		else ms.erase(ms.find(get<1>(arr[i])));

		if (!ms.empty()) {
			ans += (long long)*ms.rbegin() * (get<0>(arr[i + 1]) - get<0>(arr[i]));
		}
	}
	cout << ans;
}