#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		vector<string> vec;
		int n;
		cin >> n;

		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			vec.push_back(s);
		}

		bool ans = 0;
		for (int i = 0; i < n; ++i) {
			if (vec[i][0] >= 'a' && vec[i][0] <= 'z') {
				ans = 1;
				for (int j = i + 1; j < n; ++j) cout << vec[j] << ' ';
				cout << vec[i] << ' ';
				for (int j = 0; j < i; ++j) cout << vec[j] << ' ';
			}
		}

		if (!ans) {
			for (int i = 0; i < n; ++i) cout << vec[i] << ' ';
		}
		cout << '\n';
	}
}