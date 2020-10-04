#include <iostream>
#include <map>
using namespace std;

int arr[1000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		m[arr[i]];
	}

	int cnt = 0;
	for (auto it = m.begin(); it != m.end(); ++it) it->second = cnt++;

	for (int i = 0; i < n; ++i) {
		cout << m[arr[i]] << ' ';
	}
}