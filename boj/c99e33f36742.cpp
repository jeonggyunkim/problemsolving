#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;

void pre_order(int i, int d) {
	if (d >= n) return;
	cout << arr[i] << ' ';
	pre_order(i * 2 + 1, d + 1);
	pre_order(i * 2 + 2, d + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	arr.push_back(1);

	for (int i = 1; i < n; ++i) {
		vector<int> temp = {1};
		int a = 0, b = 0;
		for (int j = 0; j < i - 1; ++j) {
			for (int k = 0; k < (1 << j); ++k) temp.push_back(arr[a++] * 2);
			for (int k = 0; k < (1 << j); ++k) temp.push_back(arr[b++] * 2 + 1);
		}
		for (int k = 0; k < (1 << (i - 1)); ++k) temp.push_back(arr[a++] * 2 + 1);
		for (int k = 0; k < (1 << (i - 1)); ++k) temp.push_back(arr[b++] * 2);
		arr = temp;
	}
	pre_order(0, 0);
}