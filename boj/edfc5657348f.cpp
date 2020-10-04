#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c, b;
	cin >> n >> c >> b;

	string s(n, '0');
	if (c & 1) s[0] = '1';

	vector<int> arr(b);
	for (int i = 0; i < b; ++i) {
		cin >> arr[i];
		arr[i]--;
	}

	int ind = 0;
	for (int i = 1; i < n; ++i) {
		if (ind < b && i == arr[ind]) ind++;
		else {
			if (c / 2 && s[i - 1] == '0') {
				s[i] = '1';
				c -= 2;
			}
		}
	}

	cout << s;
}