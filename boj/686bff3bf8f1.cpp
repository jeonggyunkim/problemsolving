#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct conv {
	int first;
	string num;
	int lz;
	bool operator<(conv a) const {
		if (this->first != a.first) return this->first < a.first;
		else if (this->first) return 0;
		if (this->num.size() != a.num.size()) return this->num.size() < a.num.size();
		int t = strcmp(this->num.c_str(), a.num.c_str());
		if (t) return t < 0;
		return this->lz < a.lz;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<vector<conv>, int>> arr(n);
	vector<string> ori(n);

	for (int i = 0; i < n; ++i) {
		cin >> ori[i];
		arr[i].second = i;

		for (int j = 0; j < ori[i].size(); ++j) {
			arr[i].first.push_back(conv());
			if (ori[i][j] >= 'A') {
				if (ori[i][j] >= 'a') arr[i].first.back().first = 2 * (ori[i][j] - 'a') + 2;
				else arr[i].first.back().first = 2 * (ori[i][j] - 'A') + 1;
			}
			else {
				arr[i].first.back().first = 0;
				int lz = 0;
				while (j < ori[i].size() && ori[i][j] == '0') {
					lz++;
					j++;
				}
				while (j < ori[i].size() && ori[i][j] <= '9') {
					arr[i].first.back().num += ori[i][j];
					j++;
				}
				arr[i].first.back().lz = lz;
				j--;
			}
		}
	}

	sort(arr.begin(), arr.end());
	for (int i = 0 ; i < n; ++i) {
		cout << ori[arr[i].second] << '\n';
	}
}