#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ii score[8];
	for (int i = 0; i < 8; ++i) {
		cin >> score[i].first;
		score[i].second = i + 1;
	}

	vector<int> ans;
	sort(score, score + 8, greater<ii>());

	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		sum += score[i].first;
		ans.push_back(score[i].second);
	}

	cout << sum << '\n';
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}