#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000];
bool sign[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;

		vector<int> odd, even;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if (arr[i] & 1) {
				sign[i] = 1;
				odd.push_back(arr[i]);
			}
			else {
				sign[i] = 0;
				even.push_back(arr[i]);
			}
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end(), greater<int>());
		
		cout << "Case #" << test << ": ";
		int a = 0, b = 0;
		for (int i = 0; i < n; ++i) {
			if (sign[i]) cout << odd[a++] << ' ';
			else cout << even[b++] << ' ';
		}
		cout << '\n';
	}
}