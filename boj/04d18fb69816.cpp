#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int time = 0;
	for (int i = 0; i < N; ++i) time += (N - i) * arr[i];

	cout << time;
}