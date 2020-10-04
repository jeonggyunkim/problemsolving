#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

typedef pair<string, int> si;

bool comp(si& a, si& b) {
	if (a.first[0] != b.first[0]) return a.first[0] < b.first[0];
	return atoi(a.first.substr(2, a.first.size() - 2).c_str()) < atoi(b.first.substr(2, b.first.size() - 2).c_str());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<si> arr(5 * n);
	for (int i = 0; i < 5 * n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end(), comp);

	vector<int> num(5 * n);
	for (int i = 0; i < 5 * n; ++i) num[arr[i].second] = i;


	stack<int> line, wait;
	for (int i = 5 * n - 1; i >= 0; --i) line.push(num[i]);

	for (int i = 0; i < 5 * n; ++i) {
		if (!wait.empty() && wait.top() == i) {
			wait.pop();
			continue;
		}
		bool in = 0;
		while (!line.empty()) {
			if (line.top() != i) {
				wait.push(line.top());
				line.pop();
			}
			else {
				line.pop();
				in = 1;
				break;
			}
		}
		if (!in) {
			cout << "BAD";
			return 0;
		}
	}
	cout << "GOOD";
}