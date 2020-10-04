#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	char arr[20];
	cin >> arr;
	for (int i = 1; i < n; ++i) {
		if (arr[2 * i - 1] == arr[2 * i]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}