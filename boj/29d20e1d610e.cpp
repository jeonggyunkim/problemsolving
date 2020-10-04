#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> mp;
	string a, b;
	while (n--) {
		cin >> a >> b;
		mp[a] = b;
	}

	while (m--) {
		cin >> a;
		cout << mp[a] << '\n';
	}
}