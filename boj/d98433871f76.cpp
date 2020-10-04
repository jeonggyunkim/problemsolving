#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
#define EPS 1e-7
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int tri[30][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<iii> arr;
	double t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> t;
			int trans = (int)(t * 10 + EPS);
			tri[i][j] = trans;
		}
		tri[i][2] += tri[i][0];
		tri[i][3] += tri[i][1];

		arr.push_back({tri[i][0], 0, i});
		arr.push_back({tri[i][2], 1, i});
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	multiset<ii> sero;
	for (int i = 0; i < arr.size(); ++i) {
		if (i) {
			int sum = 0, start, cnt = 0;
			for (auto it = sero.begin(); it != sero.end(); ++it) {
				if (it->second) {
					cnt--;
					if (cnt == 0) sum += it->first - start;
				}
				else {
					if (cnt == 0) start = it->first;
					cnt++;
				}
			}
			ans += sum * (get<0>(arr[i]) - get<0>(arr[i - 1]));
		}
		if (get<1>(arr[i])) {
			auto it = sero.find({tri[get<2>(arr[i])][1], 0});
			sero.erase(it);
			it = sero.find({tri[get<2>(arr[i])][3], 1});
			sero.erase(it);
		}
		else {
			sero.insert({tri[get<2>(arr[i])][1], 0});
			sero.insert({tri[get<2>(arr[i])][3], 1});
		}
	}

	if (ans % 100 == 0) cout << ans / 100;
	else {
		cout.precision(2);
		cout << fixed;
		cout << (double)ans / 100;
	}
}