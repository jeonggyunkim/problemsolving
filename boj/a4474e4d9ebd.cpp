#include <iostream>
#include <set>
using namespace std;

int main() {
	int arr[9][2];
	for (int i = 0; i < 9; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}

	set<int> ans;
	for (int i = 0; i < 9; ++i) {
		arr[i][0] = 1 - arr[i][0];
		int ru[10] = {};
		int two = 0, three = 0;
		for (int j = 0; j < 9; ++j) {
			if (ru[arr[j][1]] && ru[arr[j][1]] != arr[j][0] + 2) {
				goto fail;
			}
			ru[arr[j][1]] = arr[j][0] + 2;
		}
		for (int i = 1; i < 10; ++i) {
			if (ru[i] == 3) three++;
			else two++;
		}
		if (three >= 2) goto fail;
		else if (three == 1) {
			int now;
			for (int i = 1; i < 10; ++i) if (ru[i] == 3) now = i;
			ans.insert(now);
		}
		else {
			for (int i = 1; i < 10; ++i) {
				if (ru[i] == 0) ans.insert(i);
			}
		}
		fail:
		arr[i][0] = 1 - arr[i][0];
	}
	if (ans.size() != 1) cout << -1;
	else cout << *ans.begin();
}