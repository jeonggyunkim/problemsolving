#include <iostream>
using namespace std;

int arr[55];

int main() {
	int n, s;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cin >> s;

	for (int i = 0; i < n; ++i) {
		int maxe = -1, maxi;
		for (int j = i; j < min(n, i + s + 1); ++j) {
			if (arr[j] > maxe) {
				maxe = arr[j];
				maxi = j;
			}
		}
		for (int j = maxi; j >= i + 1; --j) {
			swap(arr[j], arr[j - 1]);
			s--;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << ' ';
	}
}