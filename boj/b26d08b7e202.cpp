#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[5000000];

int main() {
	cin.tie(NULL);
	cout.sync_with_stdio(0);

	cin >> n >> k;
	k--;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	nth_element(arr, arr + k, arr + n);

	cout << arr[k] << endl;
}