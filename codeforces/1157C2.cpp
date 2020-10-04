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
		else if (arr[right] == arr[left] && arr[right] > last) {
			if (right == left) {
				if (arr[right] > last) {
					out += 'R';
					cnt++;
				}
			}
			else {
				int cnt1 = 1, cnt2 = 1;
				left++; right--;
				while (left < n && arr[left] > arr[left - 1]) {
					cnt1++;
					left++;
				}
				while (right >= 0 && arr[right] > arr[right + 1]) {
					cnt2++;
					right--;
				}
				if (cnt1 > cnt2) {
					cnt += cnt1;
					while (cnt1--) out += 'L';
				}
				else {
					cnt += cnt2;
					while (cnt2--) out += 'R';
				}
			}
			break;
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
