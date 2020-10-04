#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[301];
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int low = 0, high = 30010;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		int i = 0, sum = 0, cnt = 0;
		bool pos = 1;
		while (i < n) {
			if (arr[i] > mid) {
				pos = 0;
				break;
			}
			sum += arr[i];
			if (sum > mid) {
				sum = arr[i];
				cnt++;
			}
			i++;
		}
		cnt++;
		if (!pos || cnt > m) low = mid;
		else high = mid;
	}

	cout << high << '\n';
	vector<int> ans;
	int i = 0, past = 0, sum = 0, cnt = 0;
	while (i < n) {
		sum += arr[i];
		if (sum > high) {
			sum = arr[i];
			ans.push_back(i - past);
			cnt++;
			past = i;
		}
		i++;
	}
	ans.push_back(n - past);
	cnt++;
	while (cnt != m) {
		ans.push_back(0);
		cnt++;
	}

	for (int i = ans.size() - 1; i >= 0; --i) {
		if (ans[i] == 0) {
			for (int j = 0; j < ans.size(); ++j) {
				if (ans[j] >= 2) {
					ans[j]--;
					ans[i]++;
					break;
				}
			}
		}
	}
	for (int u: ans) cout << u << ' ';
}