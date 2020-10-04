#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int left = 0, right = n - 1;
	string out;
	int cnt = 0, last = -1;
	while (right >= left) {
		if (arr[right] > arr[left]) {
			if (arr[left] > last) {
				out += 'L';
				last = arr[left];
				left++;
			}
			else if (arr[right] > last) {
				out += 'R';
				last = arr[right];
				right--;
			}
			else break;
		}
		else {
			if (arr[right] > last) {
				out += 'R';
				last = arr[right];
				right--;
			}
			else if (arr[left] > last) {
				out += 'L';
				last = arr[left];
				left++;
			}
			else break;
		}
		cnt++;
	}

	cout << cnt << '\n' << out;
}
