#include <iostream>
#include <string>
using namespace std;

int arr[2010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	int same = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == t[i]) same++;
	}

	if (same >= n) cout << s.size() - same + n;
	else {
		n -= same;
		cout << s.size() - n;
	}
}