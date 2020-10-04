#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int x = 1; x <= tc; ++x) {
		int n;
		cin >> n;
		vector<pair<double, bool>> arr;
		vector<bool> out(2 * n, 0);

		double d;
		for (int i = 0; i < n; ++i) {
			cin >> d;
			arr.push_back({d, 1});
		}
		for (int i = 0; i < n; ++i) {
			cin >> d;
			arr.push_back({d, 0});
		}

		sort(arr.begin(), arr.end());

		int y = 0, z = n;
		for (int i = 0; i < 2 * n; ++i) {
			if (!arr[i].second) {
				for (int j = i + 1; j < 2 * n; ++j) {
					if (arr[j].second && !out[j]) {
						out[i] = 1;
						out[j] = 1;
						y++;
						break;
					}
				}
			}
		}

		out = vector<bool>(2 * n, 0);
		for (int i = 2 * n - 1; i >= 0; --i) {
			if (!arr[i].second) {
				for (int j = i - 1; j >= 0; --j) {
					if (arr[j].second && !out[j]) {
						out[i] = 1;
						out[j] = 1;
						z--;
						break;
					}
				}
			}
		}
		cout << "Case #" << x << ": " << y << ' ' << z << '\n';
	}
}