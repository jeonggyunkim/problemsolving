#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	vector<vector<int>> arr(26, vector<int>(s.size() + 1, 0));

	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 0; j < 26; ++j) {
			arr[j][i] = arr[j][i - 1];
		}
		arr[s[i - 1] - 'a'][i]++;
	}

	int n;
	cin >> n;
	char t;
	int a, b;
	while (n--) {
		cin >> t >> a >> b;
		cout << arr[t - 'a'][b + 1] - arr[t - 'a'][a] << '\n';
	}
}