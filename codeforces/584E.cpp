#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	vector<int> arr1(n), ind1(n);
	vector<int> arr2(n), ind2(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i];
		arr1[i]--;
		ind1[arr1[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> arr2[i];
		arr2[i]--;
		ind2[arr2[i]] = i;
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += abs(ind1[i] - ind2[i]);
	}
	cout << sum / 2 << '\n';

	vector<ii> ans;
	for (int i = 0; i < n; ++i) {
		while (ind1[arr2[i]] != i) {
			int t = ind1[arr2[i]];
			for (int j = t - 1; j >= i; --j) {
				if (ind2[arr1[j]] >= t) {
					swap(arr1[j], arr1[t]);
					swap(ind1[arr1[j]], ind1[arr1[t]]);
					ans.push_back(ii(j, t));
					break;
				}
			}
		}
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
	}
}