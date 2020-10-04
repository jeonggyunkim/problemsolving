#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[100];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int m;
	cin >> m;

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == m) {
			count++;
		}
	}
	cout << count;

	return 0;
}
