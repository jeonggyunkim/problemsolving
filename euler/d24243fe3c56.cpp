#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	freopen("in", "rt", stdin);

	string t;
	cin >> t;

	vector<string> arr;
	string s;
	bool start = 0;
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] == '"') {
			if (!start) s.clear();
			else arr.push_back(s);
			start = !start;
		}
		else if (start) {
			s += t[i];
		}
	}

	sort(arr.begin(), arr.end());
	
	long long ans = 0;
	for (int i = 0; i < arr.size(); ++i) {
		int sum = 0;
		for (char u: arr[i]) sum += u - 'A' + 1;
		ans += (i + 1) * sum;
	}
	cout << ans << endl;
}