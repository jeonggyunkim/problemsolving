#include <iostream>
#include <vector>
#define N 1000010
using namespace std;

int num[N];
int ind[N];
int lis[N];
int lis_index[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	int sz = 1;
	ind[0] = -1;
	lis[0] = num[0];
	lis_index[0] = 0;

	for (int i = 1; i < n; ++i) {
		if (lis[sz - 1] < num[i]) {
			ind[i] = lis_index[sz - 1];
			lis[sz] = num[i];
			lis_index[sz] = i;
			sz++;
		}
		else {
			int j = lower_bound(lis, lis + sz, num[i]) - lis;
			if (lis[j] != num[i]) {
				lis[j] = num[i];
				lis_index[j] = i;
				if (j != 0) {
					ind[i] = lis_index[j - 1];
				}
				else ind[i] = -1;
			}
		}
	}

	cout << sz << '\n';
	int i = lis_index[sz - 1];

	vector<int> ans;
	while (i != -1) {
		ans.push_back(num[i]);
		i = ind[i];
	}
	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << ' ';
	}
}