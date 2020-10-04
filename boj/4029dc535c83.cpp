#include <iostream>
#include <algorithm>
using namespace std;

int arr1[1000010], arr2[1000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; ++i) cin >> arr1[i];
	for (int i = 0; i < b; ++i) cin >> arr2[i];

	int i1 = 0;
	int i2 = 0;

	while (i1 < a && i2 < b) {
		if (arr1[i1] < arr2[i2]) cout << arr1[i1++] << ' ';
		else cout << arr2[i2++] << ' ';
	}
	while (i1 < a) cout << arr1[i1++] << ' ';
	while (i2 < b) cout << arr2[i2++] << ' ';
}