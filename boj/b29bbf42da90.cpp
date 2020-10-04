#include <iostream>
#include <vector>
using namespace std;

int main() {
	char t;
	int cnt[26] = {};
	while ((t = getchar()) != EOF) {
		if (t >= 'a' && t <= 'z') {
			cnt[t - 'a']++;
		}
	}

	int m = -1;
	vector<int> ans;

	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > m) {
			m = cnt[i];
			ans.clear();
			ans.push_back(i);
		}
		else if (cnt[i] == m) {
			ans.push_back(i);
		}
	}

	for (int i = 0; i < ans.size(); ++i) printf("%c", ans[i] + 'a');
}